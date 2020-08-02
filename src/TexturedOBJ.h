#ifndef _TEXTUREDOBJ_
#define _TEXTUREDOBJ_


#include "TexturedMesh.h"
#include "object.h"

namespace okek 
{
    class TexturedOBJ : public object<TexturedCPoint>
    {
    public:
            
        TexturedOBJ(Shader *shader, Texture2D *texture,
        OTexturedMesh *mesh,
        glm::vec3 position = glm::vec3(0),
        glm::vec3 rotation = glm::vec3(0),
        glm::vec3 center = glm::vec3(0), float size = 0.0f);

        TexturedOBJ(TexturedOBJ* obj,
        glm::vec3 position = glm::vec3(0),
        glm::vec3 rotation = glm::vec3(0),
        glm::vec3 center = glm::vec3(0), float size = 0.0f);

        inline void use()
        {shader->use();
        for(int i = 0; i< this->textures; i++)
        {
            texture[i]->use(i);
            shader->setInt("texture", i);
        }}

    };
};


#endif