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



    mesh::mesh(Cmesh* Target) { this->cmesh = Target; }
    void mesh::SetmeshP(Cmesh* Target) { this->cmesh = Target; }
    Cmesh* mesh::getmeshP() { return cmesh; }
    

};
