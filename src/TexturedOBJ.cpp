#include "TexturedOBJ.h"

namespace okek
{

    void TexturedOBJ::use()
    {
        
        shader->use();
        for(int i = 0; i< this->textures; i++)
        {
            texture[i]->use(i);
            shader->setInt("texture1", i);
        }
    }

    TexturedOBJ::TexturedOBJ(Shader *shader, Texture2D *texture,
     OTexturedMesh *mesh, float size,
     float x, float y, float z,
     float rx,float ry,float rz)
     
     {
        this->vao = vao;
        this->texture[0] = texture;
        this->shader = shader;
        this->position = glm::vec3(x,y,z);
        this->rotation = glm::vec3(rx,ry,rz);

     }
    

    TexturedOBJ::TexturedOBJ(TexturedOBJ* obj,
    glm::vec3 position, glm::vec3 rotation,
    glm::vec3 center, float size)
    {   
        
        this->center = center;
        this->vao = obj->vao;
        for(int i = 0; i < 16; i++)
                this->texture[i] = obj->texture[i];
        this->shader = obj->shader;
        this->position = position;
        this->rotation = rotation;
    }

    TexturedOBJ::TexturedOBJ(Shader *shader,
    Texture2D *texture, OTexturedMesh *mesh,
    glm::vec3 position, glm::vec3 rotation,
    glm::vec3 center, float size)
    {
        this->size = size;
        this->vao = vao;
        this->texture[0] = texture;
        this->shader = shader;
        this->position = position;
        this->rotation = rotation;
    }
};