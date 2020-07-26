    #include "ColoredMesh.h"
    #include <cstdlib>
    #include <string.h>
namespace okek
{


    ColoredMesh::ColoredMesh(float vertices[],int sizeVertices,
        unsigned int indices[], int sizeIndices)
    {
        this->points = reinterpret_cast<ColoredCPoints*>(malloc(sizeVertices*sizeof(ColoredCPoints) + sizeof(unsigned long int) + 1));
        this->points->heap = true;
        this->points->PointsBytes = sizeVertices;
        memcpy(this->points->Cpoints,
         vertices, sizeVertices);


        this->indices = reinterpret_cast<Cmesh_indices*>(malloc(sizeVertices + sizeof(unsigned long int) + 1));
        this->indices->heap = true;
        this->indices->OffsetsBytes = sizeIndices;
        memcpy(this->indices->offsets,
         indices, sizeIndices);
    }
    ColoredMesh::ColoredMesh(ColoredMesh* Target) 
    { 
        this->points = Target->points;
        this->indices = Target->indices;
    }
    ColoredMesh::~ColoredMesh()
    {
        if(this->points->heap)
        {
            delete this->points;
        }
        if(this->indices->heap)
        {
            delete this->indices;
        }
    }
    void ColoredMesh::SetPointsP(ColoredCPoints* Target) { this->points = Target; }
    void ColoredMesh::SetIndicesP(Cmesh_indices* Target) { this->indices = Target; }
    ColoredCPoints* ColoredMesh::getPointsP() { return this->points; }

}