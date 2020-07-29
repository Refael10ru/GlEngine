#ifndef _VAO_
#define  _VAO_ 

#include<vector>
#include<iostream>
#include"typedef.h"

namespace okek
{   
    template<typename T>
    class VAO
    {
    public:
        VAO() = default;

        //move costructor
        VAO(T* Target)
        { 
            this->points = Target->points;
            this->indices = Target->indices;
        }
        //copy constructor
        VAO(T&);

        //this is a copy constructor
        //sizeVertices = sum of VBO
        //sizeEBO = sum of triangles
        VAO(float VBO[],int sizeVertices,
            unsigned int EBO[], int sizeIndices)
        {
            this->points.resize(sizeVertices);
            memcpy(this->points.data(), VBO, sizeVertices*sizeof(T));
            this->indices.resize(sizeIndices);
            memcpy(this->indices.data(), EBO, sizeIndices*sizeof(CtriangleOffsets));

            std::cout << "size of points is "<< this->points.size() << "\n";
        
        }
        ~VAO() = default;


        //copyes VBO Vector
        void SetVBO(std::vector<T> Target)
        { this->VBO = Target; }

        //copyes EBO Vector
        void SetEBO(std::vector<CtriangleOffsets> Target)
        { this->EBO = Target; }


        //retreves pointer to "meshVBO"
        T* GetVBOP()
        { return this->VBO.data(); }

        //retreves pointer to "meshEBO"
        CtriangleOffsets* GetEBOP()
        { return this->EBO.data(); }

        //gets size of VBO in int
        unsigned long int GetVBOSize()
        { return this->indices.size()*sizeof(CtriangleOffsets); }

        //gets size of EBO in int
        unsigned long int GetEBOSize()
        { return this->points.size()*sizeof(T); }
    
        //----------------------------->

        //copys EBO/VBO to GPU
        virtual void CopyToGPU()
        { std::cout << "CopingVAO!\n";}


        //----------------------------->
    //protected:  

        //ID of EBO in openGL (if on GPU)
        unsigned int EBO_ID;
        //a vector of EBO elements
        std::vector<CtriangleOffsets> EBO;

        //ID of VBO in openGL (if on GPU)
        unsigned int VBO_ID;
        //a vector of VAO elements
        std::vector<T> VBO;

    };
};
#endif