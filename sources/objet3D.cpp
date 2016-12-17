#include "objet3D.hpp"


Objet3D::Objet3D()
{
    loadObj("objets/teapot.obj");
    shader=nullptr;

    /*vertices.clear();
    iVertices.clear();

    vertices={
        0.0f, 0.0f, 0.0f,
        0.4f, 0.0f, 0.0f,
        0.4f,  0.4f, 1.0f,
        0.0, -0.4, -1.0
    };

    iVertices={0,1,2,1,0,3};*/

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

void Objet3D::dessiner()
{
    glm::mat4 modelMatrix=getModelMatrix();//translation*rotation*scale;
    shader->utiliser();
    glUniformMatrix4fv(glGetUniformLocation(shader->ID(),"modelMatrix"), 1,GL_FALSE,glm::value_ptr(modelMatrix));
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
        std::vector<GLfloat> listeNormales;
        std::string ligne = "";
            while(!fileStream.eof()) {
                std::getline(fileStream, ligne);
                parseObjLine(ligne,listeNormales);
                }
            }
        fileStream.close();
}

void Objet3D::parseObjLine(std::string ligne, std::vector<GLfloat>& listeNormales){
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
            parseIndices(tokens,listeNormales);
        }
        if(typeLinge=="vn"){
            for(auto token:tokens){
                //std::cout<<token<<" ";
                listeNormales.push_back(std::stof(token));
            }
        }
    }
}

void Objet3D::parseIndices(std::vector<std::string> lineTokens, std::vector<GLfloat> &listeNormales){
    std::vector<std::string>::iterator it=lineTokens.begin();
    if (lineTokens.size()==3) {
        for(auto token:lineTokens){
        //vertices.push_back(std::stof(token));
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
            if(normales.size()<indiceV+1)
                normales.resize(indiceV+1);
            normales.at(indiceV)=listeNormales.at((std::stoi(*it))-1);
            //std::cout<<normales.back()<<" ";
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

Objet3D::~Objet3D()
{
    glDeleteBuffers(1, &vbo);
}
