#include "objet3D.hpp"


Objet3D::Objet3D()
{
    //camera=nullptr;
}

Objet3D::Objet3D(std::string filePath)
{
    normalOffset=0;
    textureOffset=0;
    loadObj(filePath.c_str());

    InitBuffers();
}

Objet3D::Objet3D(std::vector<GLfloat> vertices,
                 unsigned int normalOffset,
                 unsigned int textureOffset,
                 std::vector<unsigned int> iVertices)
{
    this->normalOffset=normalOffset;
    this->textureOffset=textureOffset;
    this->vertices=vertices;
    this->iVertices=iVertices;

    InitBuffers();
}

void Objet3D::dessiner(glm::mat4 mvpMatrix,Shader& shader)
{
    shader.utiliser();
    glUniformMatrix4fv(glGetUniformLocation(shader.ID(),"mvpMatrix"), 1,GL_FALSE,glm::value_ptr(mvpMatrix));
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
        //std::vector<std::array<GLfloat,3>> listeNormales;
        //std::vector<std::array<GLfloat,2>> listeTextures;
        //std::string ligne = "";
        std::vector<glm::vec3> listeNormales;
        std::vector<glm::vec2> listeTextures;
        std::string typeLigne="";
            while(!fileStream.eof()&&typeLigne!="f") {
                //std::getline(fileStream, ligne);
                //parseObjLine(ligne,listeNormales,listeTexture,normales,textures);
                fileStream>>typeLigne;
                if(typeLigne=="v"){
                    GLfloat vertice;
                    for(int i=0;i<3;i++){
                        fileStream>>vertice;
                        vertices.push_back(vertice);
                    }
                }
                if(typeLigne=="vn"){
                    glm::vec3 normale;
                    fileStream>>normale.x>>normale.y>>normale.z;
                    listeNormales.push_back(normale);
                }
                if(typeLigne=="vt"){
                    glm::vec2 textureCoord;
                    fileStream>>textureCoord.x>>textureCoord.y;
                    listeTextures.push_back(textureCoord);
                }
            }
            //std::cout<<listeNormales.size()<<std::endl;
            //std::cout<<listeTextures.size()<<std::endl;
            std::vector<GLfloat> normales;
            normales.resize(vertices.size());
            //std::cout<<vertices.size()<<std::endl;
            std::vector<GLfloat> textures;
            //textures.resize(2*vertices.size()/3);
            //std::cout<<textures.size()<<std::endl;
            while(!fileStream.eof()){
                if(typeLigne=="f"){
                    for(int i=0;i<3;i++){
                        std::string strIndices;
                        fileStream>>strIndices;
                        std::array<unsigned int,3> indices=getIndices(strIndices);
                        iVertices.push_back(indices.at(0));
                        if(textures.size()<2*(indices.at(0)+1))
                            textures.resize(2*(indices.at(0)+1));
                        //std::cout<<textures.size()<<std::endl;
                        textures.at(2*indices.at(0))=listeTextures.at(indices.at(1)).x;
                        normales.at(3*indices.at(0))=listeNormales.at(indices.at(2)).x;

                        textures.at(2*indices.at(0)+1)=listeTextures.at(indices.at(1)).y;
                        normales.at(3*indices.at(0)+1)=listeNormales.at(indices.at(2)).y;
                        normales.at(3*indices.at(0)+2)=listeNormales.at(indices.at(2)).z;
                    }
                }
                fileStream>>typeLigne;
            }
        normalOffset=vertices.size();
        textureOffset=vertices.size()+normales.size();
        vertices.insert(std::end(vertices), std::begin(normales), std::end(normales));
        vertices.insert(std::end(vertices), std::begin(textures), std::end(textures));
    }

        fileStream.close();
}

std::array<unsigned int,3> Objet3D::getIndices(std::string strIndices)
{
    std::array<unsigned int,3> indices;
    //std::cout<<strIndices<<" ";
    std::size_t positionSlash=0;
    for(int i=0;i<3;i++){
        std::size_t positionSlashSuivant=strIndices.find("/",positionSlash);
        //std::cout<<strIndices.substr(positionSlash,positionSlashSuivant)<<" ";
        indices.at(i)=std::stoi(strIndices.substr(positionSlash,positionSlashSuivant))-1;
        //std::cout<<indices.at(i)<<" ";
        positionSlash=positionSlashSuivant+1;
    }
    return indices;
}

void Objet3D::InitBuffers()
{
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &vbi);
    //c'est un type array

    glBindVertexArray(vao);
    glEnableVertexAttribArray(INVERTEX);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    //on y met les coordonnees du triangle
    glBufferData(GL_ARRAY_BUFFER, vertices.size()* sizeof(vertices),
                 &vertices.front(), GL_DYNAMIC_DRAW);
    //on dit a opengl comment l'interpreter
    glVertexAttribPointer(INVERTEX, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

    glEnableVertexAttribArray(INNORMAL);
    glVertexAttribPointer(INNORMAL, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)(normalOffset*sizeof(GLfloat)));

    glEnableVertexAttribArray(INTEXTURE);
    glVertexAttribPointer(INTEXTURE, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)(textureOffset*sizeof(GLfloat)));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbi);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, iVertices.size() * sizeof(unsigned int), &iVertices.front(), GL_DYNAMIC_DRAW);
    glBindVertexArray(0);
}

void Objet3D::detruire()
{
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1,&vbi);
}
