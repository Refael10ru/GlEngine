#ifndef _TYPEDEF_
#define _TYPEDEF_

namespace okek
{
    struct Cvec3
    {
        float dir[3];
    };

    struct TextureCord
    {
        float Q, U;
    };
    struct Color
    {
        float R, G, B;
    };    

    struct TexturedCPoint
    {
        Cvec3 position;
        TextureCord cord;
    };

    struct Ctriangle
    {
        float dir[9];
    };

    //represents a group of points in space
    //can be looked at as a frame of a 3d animation
    struct Cpoints
    {
        //true if on heap
        bool heap;
        int sizeqwords;
        Cvec3 points[];
    };

    struct TexturedCPoints
    {
        //true if on heap
        bool heap;
        int sizeqwords;
        TexturedCPoint points[];
    };

    class CtriangleOffsets
    {   
    public:
        unsigned int offset[3];
    };

    class vec3
    {
    public:
        vec3() = default;

        //be aware that the size is not checked!
        vec3(float*);
        //geter for stored var
        Cvec3 get();
    protected:
        Cvec3 vec;

    };

    class triangle
    {
    public:
        triangle() = default;

        //be aware that the size is not checked!
        triangle(float*);
        
        Ctriangle get();

        //should be used only on funtions from opengl
        float* getp();


    protected:
        Ctriangle tri;
    };


};
#endif