#ifndef _COLOREDMESH_
#define _COLOREDMESH_
#include "shaders.h"
#include "VAO.h"
#include <cstring>
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

        void SetIndices(unsigned int indices[], int sizeIndices);
        //dont use of indices on stack
        void SetIndices(std::vector<CtriangleOffsets> Target);
        
        void Setpoints(float vertices[],int sizeVertices);

        void SetPoints(std::vector<ColoredCPoint> Target);
        //retreves pointer to "meshpoints"
        ColoredCPoint* GetPointsP();
        CtriangleOffsets* GetIndicesP();


        unsigned long int GetPointsSize();
        unsigned long int GetIndicesSize();
    
        
    protected:  
         //a vector of indices
        std::vector<CtriangleOffsets> indices;

        //a vector of ColoredMesh
        std::vector<ColoredCPoint> points;

        void debug(int a);

    };

};
#endif