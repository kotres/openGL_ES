#include "objet3D.hpp"


Objet3D::Objet3D()
{
    //camera=nullptr;
}

Objet3D::Objet3D(std::string filePath,Shader& shader)
{
    normalOffset=0;
    textureOffset=0;
    loadObj(filePath.c_str());

    shader.utiliser();
    InitBuffers(shader);
}

Objet3D::Objet3D(std::vector<GLfloat> vertices,
                 unsigned int normalOffset,
                 unsigned int textureOffset,
                 Shader &shader)
{
    this->normalOffset=normalOffset;
    this->textureOffset=textureOffset;
    this->vertices=vertices;

    shader.utiliser();
    InitBuffers(shader);
}

void Objet3D::dessiner(glm::mat4 mvpMatrix)
{
    glUniformMatrix4fv(glGetUniformLocation(shaderID,"mvpMatrix"), 1,GL_FALSE,glm::value_ptr(mvpMatrix));
    glBindVertexArray(vao);

    glDrawElements(
        GL_TRIANGLES,      // mode
        iVertices.size(),    // count
        GL_UNSIGNED_INT,   // type
        (void*)0           // element array buffer offset
    );
    glBindVertexArray(0);
}

void Objet3D::loadObj(const char* filePath){
    std::ifstream fileStream(filePath, std::ios::in);

    if(!fileStream.is_open()) {
        std::cout << "le fichier " << filePath << " n'as pas pu etre ouvert" << std::endl;
    }
    else{
        std::vector<GLfloat> normales;
        std::vector<GLfloat> textures;
        std::vector<std::array<GLfloat,3>> listeNormales;
        std::vector<std::array<GLfloat,2>> listeTexture;
        std::string ligne = "";
            while(!fileStream.eof()) {
                std::getline(fileStream, ligne);
                parseObjLine(ligne,listeNormales,listeTexture,normales,textures);
                }
        normalOffset=vertices.size();
        textureOffset=vertices.size()+normales.size();
        vertices.insert(std::end(vertices), std::begin(normales), std::end(normales));
        vertices.insert(std::end(vertices), std::begin(textures), std::end(textures));
    }

        fileStream.close();
}

void Objet3D::parseObjLine(std::string ligne, std::vector<std::array<GLfloat,3>> &listeNormales,
                           std::vector<std::array<GLfloat,2>>& listeTexture,
                           std::vector<GLfloat>& normales,
                           std::vector<GLfloat>& textures){
    std::vector<std::string> tokens;
    boost::char_separator<char> sep(" /");
    boost::tokenizer<boost::char_separator<char> > tok(ligne,sep);
    for(boost::tokenizer<boost::char_separator<char> >::iterator beg=tok.begin(); beg!=tok.end();++beg){
           tokens.push_back(*beg) ;
       }
    if(tokens.size()>1){
        std::string typeLinge=tokens.front();
        tokens.erase(tokens.begin());
        //std::cout<<tokens.front();
        if(typeLinge=="v"){
            for(auto token:tokens){
                //std::cout<<token<<" ";
                vertices.push_back(std::stof(token));
            }
        }
        if(typeLinge=="f"){
            parseIndices(tokens,listeNormales,listeTexture,normales,textures);
        }
        if(typeLinge=="vn"){
            std::array<GLfloat,3> valNorm;
            for(int i=0;i<3;i++){
                //std::cout<<token<<" ";
                valNorm.at(i)=(std::stof(tokens.at(i)));
            }
            listeNormales.push_back(valNorm);
        }
        if(typeLinge=="vt"){
            std::array<GLfloat,2> valTex={std::stof(tokens.at(0)),std::stof(tokens.at(1))};
            listeTexture.push_back(valTex);
        }
    }
}

void Objet3D::parseIndices(std::vector<std::string> lineTokens,
                           std::vector<std::array<GLfloat,3>>& listeNormales,
                           std::vector<std::array<GLfloat,2>> &listeTexture,
                           std::vector<GLfloat>& normales,
                           std::vector<GLfloat>& textures){
    std::vector<std::string>::iterator it=lineTokens.begin();
    if (lineTokens.size()==3) {
        for(auto token:lineTokens){
            iVertices.push_back(std::stoi(token)-1);
        }
    }
    if (lineTokens.size()==6){
        while(it<lineTokens.end()-1){
            //std::cout<<*it<<" ";textures.size()+normales.size())
            unsigned int indiceV=(std::stoi(*it))-1;
            iVertices.push_back(indiceV);
            it++;
            //ajout au vecteur de normales
            //std::cout<<listeNormales.at((std::stoi(*it))-1)<<" ";
            if(listeNormales.size()>0){
                if(normales.size()<3*(indiceV+1))
                    normales.resize(3*(indiceV+1));
                std::array<GLfloat,3> valNorm=listeNormales.at(std::stoi(*it)-1);
                normales.at(3*indiceV)=valNorm.at(0);
                normales.at(3*indiceV+1)=valNorm.at(1);
                normales.at(3*indiceV+2)=valNorm.at(2);
                //std::cout<<normales.back()<<" ";
            }
            else{
                if(textures.size()<2*(indiceV+1))
                    textures.resize(2*(indiceV+1));
                std::array<GLfloat,2> valTex=listeTexture.at(std::stoi(*it)-1);
                textures.at(2*indiceV)=valTex.at(0);
                textures.at(2*indiceV+1)=valTex.at(1);
            }
            it++;
        }
    }
    if (lineTokens.size()==9){
        while(it<lineTokens.end()-2){
            unsigned int indiceV=(std::stoi(*it))-1;
            iVertices.push_back(indiceV);
            it++;
            if(textures.size()<2*(indiceV+1)){
                textures.resize(2*(indiceV+1));
                //std::cout<<listeNormales.size()<<std::endl;
            }
            std::array<GLfloat,2> valTex=listeTexture.at(std::stoi(*it)-1);
            textures.at(2*indiceV)=valTex.at(0);
            textures.at(2*indiceV+1)=valTex.at(1);
            it++;
            if(normales.size()<3*(indiceV+1)){
                normales.resize(3*(indiceV+1));
                //std::cout<<normales.size()<<std::endl;
            }
            std::array<GLfloat,3> valNorm=listeNormales.at(std::stoi(*it)-1);
            normales.at(3*indiceV)=valNorm.at(0);
            normales.at(3*indiceV+1)=valNorm.at(1);
            normales.at(3*indiceV+2)=valNorm.at(2);
            it++;
        }
    }
}

void Objet3D::InitBuffers(Shader& shader)
{
    shaderID=shader.ID();
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &vbi);
    //c'est un type array
    GLuint vertexPosition,normalPosition,texturePosition;
    shader.getAttribLocation(vertexPosition,normalPosition,texturePosition);

    glBindVertexArray(vao);
    glEnableVertexAttribArray(vertexPosition);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    //on y met les coordonnees du triangle
    glBufferData(GL_ARRAY_BUFFER, vertices.size()* sizeof(vertices),
                 &vertices.front(), GL_DYNAMIC_DRAW);
    //on dit a opengl comment l'interpreter
    glVertexAttribPointer(vertexPosition, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

    glEnableVertexAttribArray(normalPosition);
    glVertexAttribPointer(normalPosition, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)(normalOffset*sizeof(GLfloat)));

    glEnableVertexAttribArray(texturePosition);
    glVertexAttribPointer(texturePosition, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)(textureOffset*sizeof(GLfloat)));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbi);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, iVertices.size() * sizeof(unsigned int), &iVertices.front(), GL_DYNAMIC_DRAW);
    glBindVertexArray(0);
}

Objet3D::~Objet3D()
{
    glDeleteVertexArrays(1, &vao);
    //glDeleteTextures(1,&texture);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1,&vbi);
    //glDeleteBuffers(1,&vbNormales);
}
