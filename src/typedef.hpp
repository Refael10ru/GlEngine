namespace okek
{
    struct CVec3
    {
        float dir[3];
    };

    struct Ctriangle
    {
        float dir[9];
    };

    class vec3
    {
    public:
        vec3() = default;

        //be aware that the size is not checked!
        vec3(float*);
        CVec3 get();
    private:
        CVec3 vec;

    };

    class triangle
    {
    public:
        triangle() = default;

        //be aware that the size is not checked!
        triangle(float*);

        Ctriangle get();
        float* getp();


    private:
        Ctriangle tri;
    };
};