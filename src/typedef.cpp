#include "typedef.hpp"

namespace okek
{
    vec3::vec3(float* fTarget)
    {
        for(int i = 0; i < 3; i++)
            this->vec.dir[0] = fTarget[0];
    }
    Cvec3 vec3::get() { return this->vec;}




    triangle::triangle(float* fTarget)
    {
        for(int i = 0; i < 9; i++)
                this->tri.dir[i] = fTarget[i];
    }
    Ctriangle triangle::get() { return this->tri; }
    float* triangle::getp() { return this->tri.dir; }





    TexturedMesh::TexturedMesh(TexturedMesh* Target)
    {
        this->points = Target->points;
        this->indices = Target->indices;
    }
    void TexturedMesh::SetIndicesP(Cmesh_indices* Target) { this->indices = Target; }
    void TexturedMesh::SetPointsP(TexturedCPoints* Target) { this->points = Target; }
    TexturedCPoints* TexturedMesh::getPointsP() { return this->points; }
    

};
