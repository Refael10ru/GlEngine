#include "typedef.h"


namespace okek
{





    triangle::triangle(float* fTarget)
    {
        for(int i = 0; i < 9; i++)
                this->tri.dir[i] = fTarget[i];
    }
    Ctriangle triangle::get() { return this->tri; }
    float* triangle::getp() { return this->tri.dir; }


};
