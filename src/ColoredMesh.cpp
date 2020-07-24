    #include "ColoredMesh.hpp"
namespace okek
{

    ColoredMesh::ColoredMesh(ColoredMesh* Target) 
    { 
        this->points = Target->points;
        this->indices = Target->indices;
    }
    void ColoredMesh::SetPointsP(ColoredCPoints* Target) { this->points = Target; }
    void ColoredMesh::SetIndicesP(Cmesh_indices* Target) { this->indices = Target; }
    ColoredCPoints* ColoredMesh::getPointsP() { return this->points; }

}