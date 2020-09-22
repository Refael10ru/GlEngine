#pragma once 

#define GLENGINE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdlib.h>
#include <vector>	
#include "shader.h"
#include "tools.h"
#include "Debug.h"

using namespace DebugTools; 

namespace GLEngine
{   
	class VertexArrayObject
	{
	public:
		enum ObjectType
		{
			VertexArray, 
			VertexBuffer
		};

		unsigned int VertexArrayObjectID, 
			*VertexAttributePointer;
		
		std::vector<unsigned int> VertexBufferObjects;	
		
		void CreateBufferObject();	//	Creates a specified number of VertexBuffers 
		void SetVertexAttributePointer(unsigned int);	//	Sets the Vertex Attribute pointer for depending up 
		void SetVertexAttributePointer(unsigned int, unsigned int);	//	Sets the Vertex Attribute pointer for depending up 
		void Bind(VertexArrayObject::ObjectType, unsigned int);	//	Binds a specified VB	O
		void SetBufferData(unsigned int);	// Set main data.
		void SetBufferData(unsigned int, Vertex3Df*, int);	//	Sets the main data

		VertexArrayObject() : VertexBufferObjects(std::vector<unsigned int>())
		{
			unsigned int VBO;

			Debug->Log("VAO default contructor called."); 

			glGenBuffers(1, &VBO);

			Debug->Log("VBO generated."); 

			this->VertexBufferObjects.push_back(VBO); 
		
			Debug->Log(VBO);
		}

		VertexArrayObject(int bufferCount) : VertexBufferObjects(std::vector<unsigned int>())
		{
			unsigned int VBO;

			glGenBuffers(bufferCount, &VBO);

			this->VertexBufferObjects.push_back(VBO); 
		}

		VertexArrayObject(std::vector<Vertex3Df> vertexData) : VertexBufferObjects(std::vector<unsigned int>())
		{
			unsigned int VBO;

			glGenBuffers(1, &VBO);

			this->VertexBufferObjects.push_back(VBO);
			
			this->SetBufferData(VBO, General::VectorToArray<Vertex3Df>(vertexData), vertexData.size()); 	
			this->SetVertexAttributePointer(this->VertexBufferObjects.at(this->VertexBufferObjects.size() - 1));
		}

		// VertexArrayObject(std::vector<>)
		// {

		// }

		// VertexArrayObject() : VertexBufferObjects(std::vector<unsigned int>())
		// {

		// }
	}; 

	class Mesh 	//	3D/2D meshes
	{
	public:		
		int MatrixSize;	//	VertexMatrix array length

		VertexArrayObject VAO;	// Vertex Array Object 
		
		std::vector<Vertex3Df> VertexMatrixVector;	// Stores the triangle vertex matrix of a maesh
	
		Shader MeshShader;	// Shader object of the current mesh

		float* VertexMatrixArray;

		void SetVAO();	//	Sets the Vertex Array Object

		Mesh() : VertexMatrixVector(std::vector<Vertex3Df>()), VertexMatrixArray(new float[1000]), MatrixSize(0) 
		{
		}
		
		Mesh(Vertex3Df* vertexMatrix, int size) : VertexMatrixVector(std::vector<Vertex3Df>()), VertexMatrixArray(General::PointArrayToFloatArray(vertexMatrix, size)) 
		{
		}

		Mesh(std::vector<Vertex3Df> vertexMatrixVector) : VertexMatrixVector(vertexMatrixVector),  VertexMatrixArray(General::VertexVectorToFloatArray(vertexMatrixVector)), MatrixSize(vertexMatrixVector.size() * 3)
		{	
		}
	};

	class Renderer
	{
	public:
		static void Render();
	};
}