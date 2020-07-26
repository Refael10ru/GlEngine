#include "typedef.h"

namespace okek
{

    struct ColoredCPoint
    {
        Cvec3 position;
        Color color;
    };

    struct ColoredCPoints
    {
        //true if on heap
        bool heap;
        unsigned long int PointsBytes;
        ColoredCPoint Cpoints[];
    };

    class ColoredMesh
    {
    public:
        ColoredMesh() = default;

        //move costructor
        ColoredMesh(ColoredMesh*);
        //copy constructor
        ColoredMesh(ColoredMesh&);

        //this is a copy constructor
        //sizeVertices = sum of points
        //sizeIndices = sum of triangles
        ColoredMesh(float vertices[],int sizeVertices,
        unsigned int indices[], int sizeIndices);

        ~ColoredMesh();

        void SetMeshIndices(unsigned int indices[], int sizeIndices);
        //dont use of indices on stack
        void SetIndicesP(Cmesh_indices* Target);
        
        void Setpoints(float vertices[],int sizeVertices);

        void SetPointsP(ColoredCPoints* Target);
        //retreves pointer to "meshpoints"
        ColoredCPoints* getPointsP();

        void SetUpReader();
        const char* reader = 
        "#version 400\n"
        "layout (location = 0) in vec3 aPos;"   
        "layout (location = 1) in vec3 aColor;" 
        "out vec3 ourColor;"
        "void main()"
        "{"
        "gl_Position = vec4(aPos, 1.0);"
        "ourColor = aColor;" 
        "}";
    
        //a pointer to indices
        Cmesh_indices* indices;

        //a pointer to the ColoredMesh
        ColoredCPoints* points;
    protected:  
        

        

        static char parser[];
    };

};