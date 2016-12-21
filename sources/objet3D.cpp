#include "objet3D.hpp"


Objet3D::Objet3D()
{
    //camera=nullptr;
}

Objet3D::Objet3D(const char *filePath)
{
    loadObj(filePath);

    //camera=nullptr;

    glGenBuffers(1, &vbo);
    //c'est un type array
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    //on y met les coordonnees du triangle
    glBufferData(GL_ARRAY_BUFFER, vertices.size()* sizeof(vertices),
                 &vertices.front(), GL_DYNAMIC_DRAW);
    //on dit a opengl comment l'interpreter
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);


    glGenBuffers(1, &vbi);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbi);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, iVertices.size() * sizeof(unsigned int), &iVertices.front(), GL_DYNAMIC_DRAW);


    glGenBuffers(1, &vbNormales);
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, vbNormales);
    glBufferData(GL_ARRAY_BUFFER, normales.size()* sizeof(normales),
                 &normales.front(), GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
}

void Objet3D::dessiner(Shader sh, glm::mat4 mvpMatrix)
{
    sh.utiliser();
    glUniformMatrix4fv(glGetUniformLocation(sh.ID(),"mvpMatrix"), 1,GL_FALSE,glm::value_ptr(mvpMatrix));
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(
       0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
       3,                  // size
       GL_FLOAT,           // type
       GL_FALSE,           // normalized?
       0,                  // stride
       (void*)0            // array buffer offset
    );

    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, vbNormales);
    glVertexAttribPointer(
                2,                                // attribute
                3,                                // size
                GL_FLOAT,                         // type
                GL_FALSE,                         // normalized?
                0,                                // stride
                (void*)0                          // array buffer offset
            );

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbi);

    glDrawElements(
        GL_TRIANGLES,      // mode
        iVertices.size(),    // count
        GL_UNSIGNED_INT,   // type
        (void*)0           // element array buffer offset
    );
}

void Objet3D::loadObj(const char* filePath){
    std::ifstream fileStream(filePath, std::ios::in);

    if(!fileStream.is_open()) {
        std::cout << "le fichier " << filePath << " n'as pas pu etre ouvert" << std::endl;
    }
    else{
        std::vector<std::array<GLfloat,3>> listeNormales;
        std::vector<std::array<GLfloat,2>> listeTexture;
        std::string ligne = "";
            while(!fileStream.eof()) {
                std::getline(fileStream, ligne);
                parseObjLine(ligne,listeNormales,listeTexture);
                }
            }
        fileStream.close();
        loadTexture(filePath);
}

void Objet3D::parseObjLine(std::string ligne, std::vector<std::array<GLfloat,3>> &listeNormales,std::vector<std::array<GLfloat,2>>& listeTexture){
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
            parseIndices(tokens,listeNormales,listeTexture);
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

void Objet3D::parseIndices(std::vector<std::string> lineTokens, std::vector<std::array<GLfloat,3>>& listeNormales, std::vector<std::array<GLfloat,2>> &listeTexture){
    std::vector<std::string>::iterator it=lineTokens.begin();
    if (lineTokens.size()==3) {
        for(auto token:lineTokens){
            iVertices.push_back(std::stoi(token)-1);
        }
    }
    if (lineTokens.size()==6){
        while(it<lineTokens.end()-1){
            //std::cout<<*it<<" ";
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
            //iVertices.push_back(std::stoi(*it));
            it++;
            //ajout au vecteur d'indices de textures
            it++;
            //ajout au vecteur d'iVertices de normales
            it++;
        }
    }
}

void Objet3D::loadTexture(const char* filePath)
{
    SDL_Surface* surf = SDL_LoadBMP("objets/mugul/mugul_a_roulettes.bmp");
        if (surf==NULL) { //echec de chargement texture
            std::cout<<"erreur de chargement de texture: "<< SDL_GetError()<<std::endl;
        }
        else{
            glGenTextures(1,&texture);
            glBindTexture(GL_TEXTURE_2D,texture);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w,surf->h, 0, GL_RGB,GL_UNSIGNED_BYTE,surf->pixels);
            SDL_FreeSurface(surf);
        }
}

Objet3D::~Objet3D()
{
    glDeleteTextures(1,&texture);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1,&vbi);
    glDeleteBuffers(1,&vbNormales);
}
