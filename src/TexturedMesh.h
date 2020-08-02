#ifndef _TEXTUREDMESH_
#define _TEXTUREDMESH_

#include "VAO.h"
namespace okek 
{
    struct TexturedCPoint
    {
        glm::vec3 position;
        Color color;
        TextureCord texturecord;
    };

    class TexturedMesh : public VAO<TexturedCPoint>
    {
    public:
        
        using VAO::VAO;
        
        void PrintVBO(int i);
        
        virtual void SetAtributes() override
        {
            // position attribute
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(okek::TexturedCPoint), (void*)0);
            glEnableVertexAttribArray(0);
            // color attribute
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(okek::TexturedCPoint), (void*)(3* sizeof(float)));
            glEnableVertexAttribArray(1);
            // texture attribute
            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(okek::TexturedCPoint), (void*)(6 * sizeof(float)));
            glEnableVertexAttribArray(2);
        }
    };
    struct OTexturedCPoint
    {
        glm::vec3 position;
        TextureCord texturecord;
    };
    class OTexturedMesh : public VAO<OTexturedCPoint>
    {
    public:
        
        using VAO::VAO;
        
        void PrintVBO(int i);
        
        virtual void SetAtributes() override
        {
            // position attribute
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(okek::OTexturedCPoint), (void*)0);
            glEnableVertexAttribArray(0);
            // texture attribute
            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(okek::OTexturedCPoint), (void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(1);
        }
    };
};

#endif