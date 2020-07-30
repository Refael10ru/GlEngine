#ifndef _TYPEDEF_
#define _TYPEDEF_

namespace okek
{
    struct Cvec3
    {
        float x;
        float y;
        float z;
    };

    struct TextureCord
    {
        float Q, U;
    };
    struct Color
    {
        float R, G, B;
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


    class CtriangleOffsets
    {   
    public:
        unsigned int offset[3];
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