namespace okek
{
    struct Cvec3
    {
        float dir[3];
    };

    struct Cvec6
    {
        float dir[6];
    };

    struct Cvec5
    {
        float dir[5];
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

    struct ColoredCPoints
    {
        //true if on heap
        bool heap;
        int sizeqwords;
        Cvec6 points[];
    };
    struct TexturedCPoints
    {
        //true if on heap
        bool heap;
        int sizeqwords;
        Cvec5 points[];
    };


    struct Cmesh_indices 
    {
        //true if on heap
        bool heap;
        //represents how much triangles offsets groups together
        int size3qwords;
        //instructions for how to group points into triangles
        int offsets[];   
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



    class TexturedMesh
    {
    public:
        TexturedMesh() = default;

        //move costructor
        TexturedMesh(TexturedMesh*);
        //copy constructor
        TexturedMesh(TexturedMesh&);

        //this is a copy constructor
        //sizeVertices = sum of points
        //sizeIndices = sum of triangles
        TexturedMesh(float vertices[],int sizeVertices,
        unsigned int indices[], int sizeIndices,
        bool heap);

        ~TexturedMesh();

        void SetMeshIndices(unsigned int indices[], int sizeIndices);
        
        void SetIndicesP(Cmesh_indices* Target);
        
        void SetMeshpoints(float vertices[],int sizeVertices);

        void SetPointsP(TexturedCPoints* Target);
        //retreves meshpointer
        TexturedCPoints* getPointsP();

       

    protected:
        //a pointer to indices
        TexturedCPoints* points;
        unsigned int MeshPointsID;
        //a pointer to the ColoredMesh
        Cmesh_indices* indices;
        unsigned int MeshIndicesID;

        const char* ReadShader;
    };
};