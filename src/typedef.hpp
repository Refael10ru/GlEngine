namespace okek
{
    struct Cvec3
    {
        float dir[3];
    };

    struct Ctriangle
    {
        float dir[9];
    };


    struct Cmesh_points
    {
        int bytesize;

        //must be a multiple of 3qwords
        int offset[];
    };

    struct Cmesh
    {
        Cmesh_points* points;
        int offsets[];
        
    };

    class vec3
    {
    public:
        vec3() = default;

        //be aware that the size is not checked!
        vec3(float*);
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
        float* getp();


    protected:
        Ctriangle tri;
    };



    class mesh
    {
    public:
        mesh() = default;

        //move costructor
        mesh(Cmesh*);

        void SetmeshP(Cmesh*);
        //retreves meshpointer
        Cmesh* getmeshP();

    protected:
        Cmesh* cmesh;
    };
};