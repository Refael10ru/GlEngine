#ifndef _TYPEDEF_
#define _TYPEDEF_


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace okek
{

    struct TextureCord
    {
        float Q, U;
    };
    struct Color
    {
        float R, G, B;
    };    

    class CtriangleOffsets
    {   
    public:
        unsigned int offset[3];
    };




};
#endif