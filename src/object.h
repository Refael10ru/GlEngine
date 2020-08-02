
#include "shaders.h"
#include "Texture2D.h"
#include "VAO.h"
#include <iostream>

namespace okek
{
    template<typename T>
    class object
    {
public:

    object() = default;


    object(Shader *shader, Texture2D *texture, VAO<T> *vao,
    glm::vec3 position = 0, glm::vec3 rotation = 0 , glm::vec3 center = 0)
    {
        this->center = center;
        this->vao = vao;
        this->texture = texture;
        this->shader = shader;
        this->position = position;
        this->rotation = rotation;
    }

    object(object* obj,
    glm::vec3 position = 0, glm::vec3 rotation = 0, glm::vec3 center = 0)
    {
        this->center = center;
        this->vao = obj->vao;
        for(int i = 0; i < 16; i++)
                this->texture[i] = obj->texture[i];
        this->shader = obj->shader;
        this->position = position;
        this->rotation = rotation;
    }
    
    
    glm::mat4 GetTMatrix()
    {
        glm::mat4 model = glm::mat4(1.0f);//this->size);
        //model = this->size * model;
        model = glm::rotate(model, glm::radians(this->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::rotate(model, glm::radians(this->rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::rotate(model, glm::radians(this->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::translate(model, this->position);
        return model;
    }

    void SetTexture(int i, Texture2D* texture)
    {
        if( i > this->textures)
        {
            if(i > 15)
            {std::cout << "ERROR there can be only 16 textures max per object";}
            else
            {this->textures = i;}
        }
        this->texture[i] = texture;
    }

    void use()
    {
        for(int i = 0; i < this->textures; i++)
            if(this->textute[i])
            {
                texture[i]->use(i);
            }
    }
//protected:
    glm::vec3 position;
    glm::vec3 rotation; 
    float size;
    //going to be used in the future for more complex stuff
    glm::vec3 center;
    VAO<T> *vao;
    short int textures;
    Texture2D* texture[16];
    Shader *shader;
    };
};