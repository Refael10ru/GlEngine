#ifndef _COLOREDMESH_
#define _COLOREDMESH_

#include "VAO.h"
#include <iostream>
#include <vector>

namespace okek
{

    class ColoredCPoint
    {
    public:
        glm::vec3 position;
        Color color;
    };

    class ColoredMesh : public VAO<ColoredCPoint>
    {
    public:
        using VAO::VAO;

        void debug1(int i);

        virtual void SetAtributes() override
        {
        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(okek::ColoredCPoint), (void*)0);
        glEnableVertexAttribArray(0);
        // color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(okek::ColoredCPoint), (void*)(3* sizeof(float)));
        glEnableVertexAttribArray(1);
        }
    };

};
#endif