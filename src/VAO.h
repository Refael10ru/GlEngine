#ifndef _VAO_
#define  _VAO_ 



#include "shaders.h"
#include<vector>
#include<iostream>
#include"typedef.h"
#include <cstring>


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
        this->VBO = Target->VBO;
        this->EBO = Target->EBO;
    }
    //copy constructor
    VAO(T&);

    //this is a copy constructor
    //sizeVertices = sum of VBO
    //sizeEBO = sum of triangles
    VAO(float VBO[],int sizeVertices,
        unsigned int EBO[], int sizeIndices)
    {   
        this->VBO.resize(sizeVertices);
        memcpy(this->VBO.data(), VBO, sizeVertices*sizeof(T));
        this->EBO.resize(sizeIndices);
        memcpy(this->EBO.data(), EBO, sizeIndices*sizeof(CtriangleOffsets));

    }

    VAO(std::string PathToBin,std::string PathToOBJ)
    {
        std::cout << " constructing...";

    }

    ~VAO() = default;

    //initializes atributes of VBO and Copies EBO/VBO onto the GPU 
    void InitializeOnGPU()
    {
        // 1. initialize VAO
        glGenVertexArrays(1, &this->VAO_ID);
        glBindVertexArray(VAO_ID);
        // 2. copy our vertices array in a vertex buffer for OpenGL to use
        glGenBuffers(1, &this->VBO_ID);
        glBindBuffer(GL_ARRAY_BUFFER, VBO_ID);
        glBufferData(GL_ARRAY_BUFFER, this->GetVBOSize() , this->GetVBOP(), GL_STATIC_DRAW);

        // 3. initialize memory layot of VBO
        SetAtributes();

        // 4. copy our index array in a element buffer for OpenGL to use
        glGenBuffers(1, &this->EBO_ID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_ID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->GetEBOSize() , this->GetEBOP(), GL_STATIC_DRAW); 
        
    }

    //must rewrite this function before when inheriting
    //this func initializes memory layot of VBO!
    virtual void SetAtributes() = 0;

    inline void use()
    { glBindVertexArray(VAO_ID); }

    //copyes VBO Vector
    inline void SetVBO(std::vector<T> Target)
    { this->VBO = Target; }

    //copyes EBO Vector
    inline void SetEBO(std::vector<CtriangleOffsets> Target)
    { this->EBO = Target; }


    //retreves pointer to "meshVBO"
    inline T* GetVBOP()
    { return this->VBO.data(); }

    //retreves pointer to "meshEBO"
    inline CtriangleOffsets* GetEBOP()
    { return this->EBO.data(); }

    //gets size of VBO in int
    inline unsigned long int GetVBOSize()
    { return this->VBO.size()*sizeof(T); }

    //gets size of EBO in int
    inline unsigned long int GetEBOSize()
    { return this->EBO.size()*sizeof(CtriangleOffsets); }

protected:  

    //ID of VAO in openGL (if on GPU)
    unsigned int VAO_ID;

    //ID of EBO in openGL (if on GPU)
    unsigned int EBO_ID;
    //a vector of EBO elements
    std::vector<CtriangleOffsets> EBO;

    //ID of VBO in openGL (if on GPU)
    unsigned int VBO_ID;
    //a vector of VAO elements
    std::vector<T> VBO;

    void debug(int i)
    {std::cout << this->EBO[i].offset[0] << " : " << this->EBO[i].offset[1] << " : " << this->EBO[i].offset[2] << "\n";}
    };
};

#endif