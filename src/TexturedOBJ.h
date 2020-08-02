
#include "TexturedMesh.h"
#include "object.h"

namespace okek 
{
    class TexturedOBJ : public object<TexturedCPoint>
    {
    public:
        TexturedOBJ(Shader *shader, Texture2D *texture,
        OTexturedMesh *mesh, float size = 1,
        float x = 0, float y = 0, float z = 0,
        float rx = 0,float ry = 0,float rz = 0);
            
        TexturedOBJ(Shader *shader, Texture2D *texture,
        OTexturedMesh *mesh,
        glm::vec3 position = glm::vec3(0),
        glm::vec3 rotation = glm::vec3(0),
        glm::vec3 center = glm::vec3(0), float size = 0.0f);

        TexturedOBJ(TexturedOBJ* obj,
        glm::vec3 position = glm::vec3(0),
        glm::vec3 rotation = glm::vec3(0),
        glm::vec3 center = glm::vec3(0), float size = 0.0f);

        inline void use();

        inline void GetMatrix();
    };
};