#include "objet3D.hpp"


Objet3D::Objet3D()
{
    loadObj("objets/teapot.obj");
    shader=nullptr;
    /*vertices={
        0.0f, 0.0f, 0.0f,
        0.4f, 0.0f, 0.0f,
        0.4f,  0.4f, 1.0f,
        0.0, -0.4, -1.0
    };

    indices={0,1,2,1,0,3};*/

    glGenBuffers(1, &vbo);
    //c'est un type array
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    //on y met les coordonnees du triangle
    glBufferData(GL_ARRAY_BUFFER, vertices.size()* sizeof(vertices),
                 &vertices.front(), GL_DYNAMIC_DRAW);
    //on dit a opengl comment l'interpreter
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);


    glGenBuffers(1, &vbi);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbi);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);


    glEnableVertexAttribArray(0);

    position=glm::vec3(0.0);
    rotation=glm::mat4(1.0);
}

void Objet3D::dessiner()
{
    shader->utiliser();
    glUniform3fv(glGetUniformLocation(shader->ID(),"position"), 1, glm::value_ptr(position));
    glUniformMatrix4fv(glGetUniformLocation(shader->ID(),"rotation"), 1,GL_FALSE,glm::value_ptr(rotation));
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(
       0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
       3,                  // size
       GL_FLOAT,           // type
       GL_FALSE,           // normalized?
       0,                  // stride
       (void*)0            // array buffer offset
    );
    //glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbi);

    glDrawElements(
        GL_TRIANGLES,      // mode
        indices.size(),    // count
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
        std::string ligne = "";
            while(!fileStream.eof()) {
                std::getline(fileStream, ligne);
                /*if(ligne[0]=='v' && ligne[1] == ' '){//v est une ligne décrivant un sommet
                     std::istringstream iss(ligne.substr(2));//on utilise un iss de la ligne sans "v "
                     float x,y,z;
                     iss >> x >> y>> z;//on preleve les valeurs des sommets
                     vertices.push_back(x);
                     vertices.push_back(y);
                     vertices.push_back(z);
                     //std::cout<<x<<"_"<<y<<"_"<<z<<std::endl;
                }
                if(ligne[0] == 'f' && ligne[1] == ' '){//si c'est des indices de triangles
                    ligne=ligne.substr(2);
                    unsigned int indiceObj;
                    for(int i=0;i<3;i++){
                        std::size_t posEspace=ligne.find_first_of(" ");
                        indiceObj=atoi(ligne.substr(0,posEspace).c_str());
                        indiceObj--;
                        indices.push_back(indiceObj);
                        ligne=ligne.substr(posEspace+1);
                    }
                    //std::cout<<indices[0]<<"_"<<indices[1]<<"_"<<indices[2]<<std::endl;
                }*/
                std::vector<std::string> tokens;
                boost::split(tokens, line, boost::is_any_of("/ "));
                switch (tokens.front()) {
                case "v":
                    tokens.erase(tokens.begin());
                    for(auto tok:tokens)
                        vertices.push_back(atof(tok));
                    break;
                case "f":
                    tokens.erase(tokens.begin());
                    switch (tokens.size()) {
                    case 3:
                        for(std::string tok:tokens)
                            indices.push_back(atoi(tok));
                        break;
                    case 6:
                        vector<std::string>::iterator it=tokens.begin();
                        while(it!=tokens.end()-1){
                            indices.push_back(atoi(*it));
                            it++;
                            //ajout au vecteur d'indices de texture
                            it++;
                        }
                        break;
                    case 9:
                        vector<std::string>::iterator it=tokens.begin();
                        while(it!=tokens.end()-2){
                            indices.push_back(atoi(*it));
                            it++;
                            //ajout au vecteur d'indices de textures
                            it++;
                            //ajout au vecteur d'indices de normales
                            it++;
                        }
                    default:
                        std::cout<<tokens.size();
                        break;
                    }
                    break;
                default:
                    std::cout<<tokens.front();
                    break;
                }
            }
        fileStream.close();
    }
}

Objet3D::~Objet3D()
{
    glDeleteBuffers(1, &vbo);
}
