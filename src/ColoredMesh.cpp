    #include "ColoredMesh.h"
    #include <cstring>
namespace okek
{
    ColoredCPoint::ColoredCPoint(float* Target)
    {
        this->position.dir[0] = Target[0];
        this->position.dir[1] = Target[1];
        this->position.dir[2] = Target[2];
        this->color.R = Target[3];
        this->color.G = Target[4];
        this->color.B = Target[5];
    }



    ColoredMesh::ColoredMesh(float vertices[],int sizeVertices,
        unsigned int indices[], int sizeIndices)
    {
        this->points.resize(sizeVertices);
        memcpy(this->points.data(), vertices, sizeVertices*sizeof(ColoredCPoint));
        this->indices.resize(sizeIndices);
        memcpy(this->indices.data(), indices, sizeIndices*sizeof(CtriangleOffsets));
        
        //std::cout "size of points is "<< this->points.size() << "\n";

        
    }
    ColoredMesh::ColoredMesh(ColoredMesh* Target) 
    { 
        this->points = Target->points;
        this->indices = Target->indices;
    }
    ColoredMesh::~ColoredMesh()
    {

    }
    void ColoredMesh::SetIndices(std::vector<CtriangleOffsets> Target)
    { this->indices = Target; }
    
    ColoredCPoint* ColoredMesh::GetPointsP()
    { return this->points.data(); }

    unsigned long int ColoredMesh::GetPointsSize()
    { return this->points.size(); }

}