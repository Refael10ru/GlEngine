#ifndef _TEXTUREDMESH_
#define _TEXTUREDMESH_

#include "VAO.h"
namespace okek 
{

    class TexturedMesh : public VAO<TexturedCPoint>
    {
    public:
        void CopyToGPU() override
        {
            std::cout << "overrided COPY!\n";
        }
        void debug1(int i);
        
        
    };

};

#endif