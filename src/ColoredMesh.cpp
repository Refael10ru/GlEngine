#include "ColoredMesh.h"
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

        std::cout << "size of points is "<< this->points.size() << "\n";
        

        
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

    CtriangleOffsets* ColoredMesh::GetIndicesP()
    { return this->indices.data(); }

    unsigned long int ColoredMesh::GetIndicesSize()
    { return this->indices.size()*sizeof(CtriangleOffsets); }

    unsigned long int ColoredMesh::GetPointsSize()
    { return this->points.size()*sizeof(ColoredCPoint); }

    void ColoredMesh::debug(int a)
    {
        std::cout << "info for point with index " << a << "\n";
        
        std::cout << "X : " << this->points[a].position.dir[0] << " ";
        std::cout << "Y : " << this->points[a].position.dir[1] << " ";
        std::cout << "Z : " << this->points[a].position.dir[2] << " \n";
        std::cout << "R : " << this->points[a].color.R << " ";
        std::cout << "G : " << this->points[a].color.G << " ";
        std::cout << "B : " << this->points[a].color.B << "\n";
    }
}