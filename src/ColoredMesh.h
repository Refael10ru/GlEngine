#include "typedef.h"
#include <iostream>
#include <vector>
namespace okek
{

    class ColoredCPoint
    {
    public:
        Cvec3 position;
        Color color;
        ColoredCPoint() = default;
        ColoredCPoint(float* Target);
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
        void SetIndices(std::vector<CtriangleOffsets> Target);
        
        void Setpoints(float vertices[],int sizeVertices);

        void SetPointsVector(std::vector<ColoredCPoint> Target);
        //retreves pointer to "meshpoints"
        ColoredCPoint* GetPointsP();

        unsigned long int GetPointsSize();

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
    
       
    protected:  
         //a vector of indices
        std::vector<CtriangleOffsets> indices;

        //a vector of ColoredMesh
        std::vector<ColoredCPoint> points;

        

        static char parser[];
    };

};