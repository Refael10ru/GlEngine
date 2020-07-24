#include "typedef.hpp"

namespace okek
{

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
        unsigned int indices[], int sizeIndices,
        bool heap);

        ~ColoredMesh();

        void SetMeshIndices(unsigned int indices[], int sizeIndices);
        //dont use of indices on stack
        void SetIndicesP(Cmesh_indices* Target);
        
        void Setpoints(float vertices[],int sizeVertices);

        void SetPointsP(ColoredCPoints* Target);
        //retreves meshpointer
        ColoredCPoints* getPointsP();

    protected:
        //a pointer to indices
        Cmesh_indices* indices;

        //a pointer to the ColoredMesh
        ColoredCPoints* points;
        
        

        const char* reader = 
        "#version 400\n"
        "layout (location = 0) in vec3 aPos;"
        "layout (location = 1) in vec3 Color;"
        "out vec3 vertexColor;"
        "out vec3 vertexPosition;"
        "void main()"
        "{"
        "    vertexPosition = aPos;"
        "    vertexColor = Color;"
        "}";

        static char parser[];
    };

};