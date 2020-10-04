#pragma once 

#define GLENGINE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdlib.h>
#include <vector>	
#include "shader.h"
#include "tools.h"
#include "window.h"
#include "globjects.h"
#include "globals.h"

using namespace DebugTools; 

namespace GLEngine
{   	
	extern void SetWindowHints(unsigned int, unsigned int);	//	Sets up the OpenGL version hint
	extern bool SetupGLEW();	//	Sets up the GLEW library
	extern bool SetupGLFW();	//	Sets up the GLFW library

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
		
		void CreateBufferObject();	//	Creates a VertexBuffers
		void CreateBufferObject(int);	//	Creates a specified number of VertexBuffers 
		void SetVertexAttributePointer(unsigned int);	//	Sets the Vertex Attribute pointer for the latest object
		void SetVertexAttributePointer(unsigned int, unsigned int);	//	Sets the Vertex Attribute pointer for the provided object id
		void Bind(VertexArrayObject::ObjectType, unsigned int);	//	Binds a specified VBO
		void SetBufferData(unsigned int);	// Sets main data.
		void SetBufferData(unsigned int, float*, unsigned int);	//	Sets the main data

		VertexArrayObject() : VertexBufferObjects(std::vector<unsigned int>()), VertexArrayObjectID(-1), VertexAttributePointer(nullptr)
		{
			this->CreateBufferObject(); 
		}

		VertexArrayObject(int bufferCount) : VertexBufferObjects(std::vector<unsigned int>()), VertexArrayObjectID(-1), VertexAttributePointer(nullptr)
		{			
			this->CreateBufferObject(); 
		}

		VertexArrayObject(float* vertexData, unsigned int size) : VertexBufferObjects(std::vector<unsigned int>())
		{
			Debug->Log("VertexArrayObject()");
			
			glGenVertexArrays(1, &this->VertexArrayObjectID);  // Generates the VAO
			this->CreateBufferObject();	// Generates the VBO 
			
			// this->Bind(VertexArray, this->VertexArrayObjectID); // Binds the VAO

			glBindVertexArray(this->VertexArrayObjectID);


			Debug->Log("Buffer object created succesfuly.");	

			Debug->Log(this->VertexBufferObjects.at(this->VertexBufferObjects.size() - 1)); 

			this->SetBufferData(this->VertexBufferObjects.at(this->VertexBufferObjects.size() - 1), vertexData, size);	// sets the data to the VBO 	
			
			Debug->Log("Buffer data set succesfully.");
	
			this->SetVertexAttributePointer(0); // sets Vertex Attribute pointer to id 0.
			// this->Bind(VertexArrayObject::VertexBuffer, 0);
			glBindBuffer(GL_ARRAY_BUFFER, 0); 
			// this->Bind(VertexArrayObject::VertexArray, 0);
			glBindVertexArray(0); 
		}
		
		~VertexArrayObject()
		{
			glDeleteVertexArrays(this->VertexArrayObjectID); 		
		}
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

		Mesh() : VertexMatrixVector(std::vector<Vertex3Df>()), VertexMatrixArray(new float[1000]), MatrixSize(0), MeshShader(Shader()) 
		{
		}
		
		Mesh(Vertex3Df* vertexMatrix, int size) : VertexMatrixVector(std::vector<Vertex3Df>()), VertexMatrixArray(General::PointArrayToFloatArray(vertexMatrix, size)), MeshShader(Shader())
		{
		}

		Mesh(Vertex3Df* vertexMatrix, int size, Shader shader) : VertexMatrixVector(std::vector<Vertex3Df>()), VertexMatrixArray(General::PointArrayToFloatArray(vertexMatrix, size)), MeshShader(shader)
		{
		}

		Mesh(std::vector<Vertex3Df> vertexMatrixVector) : VertexMatrixVector(vertexMatrixVector), VertexMatrixArray(General::VertexVectorToFloatArray(vertexMatrixVector)), MatrixSize(vertexMatrixVector.size() * 3), MeshShader(Shader())
		{
		}

		Mesh(std::vector<Vertex3Df>	vertexMatrixVector, Shader shader) : VertexMatrixVector(vertexMatrixVector),  VertexMatrixArray(General::VertexVectorToFloatArray(vertexMatrixVector)), MatrixSize(vertexMatrixVector.size() * 3), MeshShader(shader)
		{
			if (vertexMatrixVector.size() > 0) 
				this->SetVAO();
		}

		~Mesh()
		{
			delete &this->MeshShader;
			delete &this->VAO;
		}
	};

	class Renderer
	{
	public:	
		static bool IsNull(); // Null checks all required Mesh properties
		static bool GLLoop(Window, Mesh*);	//	 Runs the OpenGL loop.
		static void Render(Mesh*);	// Renders the provided Mesh
	};
}
