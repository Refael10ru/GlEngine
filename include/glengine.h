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
		void SetVertexAttributePointer(unsigned int);	//	Sets the Vertex Attribute pointer for depending up 
		void SetVertexAttributePointer(unsigned int, unsigned int);	//	Sets the Vertex Attribute pointer for depending up 
		void Bind(VertexArrayObject::ObjectType, unsigned int);	//	Binds a specified VBO
		void SetBufferData(unsigned int);	// Set main data.
		void SetBufferData(unsigned int, float*, unsigned int);	//	Sets the main data

		VertexArrayObject() : VertexBufferObjects(std::vector<unsigned int>()), VertexArrayObjectID(-1), VertexAttributePointer(nullptr)
		{
			this->CreateBufferObject(); 
		}

		VertexArrayObject(int bufferCount) : VertexBufferObjects(std::vector<unsigned int>()), VertexArrayObjectID(-1), VertexAttributePointer(nullptr)
		{			
			this->CreateBufferObject(); 
		}

		VertexArrayObject(std::vector<Vertex3Df> vertexData) : VertexBufferObjects(std::vector<unsigned int>())
		{
			this->CreateBufferObject(); 
			this->SetBufferData(this->VertexBufferObjects.at(this->VertexBufferObjects.size() - 1), General::VertexVectorToFloatArray(vertexData), vertexData.size() * 3);	// sets the data to the VBO 	
			this->SetVertexAttributePointer(this->VertexBufferObjects.at(this->VertexBufferObjects.size() - 1));
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

		Mesh(std::vector<Vertex3Df> vertexMatrixVector) : VertexMatrixVector(vertexMatrixVector) //,  VertexMatrixArray(General::VertexVectorToFloatArray(vertexMatrixVector)), MatrixSize(vertexMatrixVector.size() * 3), MeshShader(Shader())
		{	
			// Debug->Log("Contructor called. "); 
		}

		Mesh(std::vector<Vertex3Df>	vertexMatrixVector, Shader shader) : VertexMatrixVector(vertexMatrixVector),  VertexMatrixArray(General::VertexVectorToFloatArray(vertexMatrixVector)), MatrixSize(vertexMatrixVector.size() * 3), MeshShader(shader)
		{
		}
	};

	class Renderer
	{
	public:	
		static bool IsNull(); // Null checks all required Mesh properties
		static bool GLLoop(Window);	//	 Runs the OpenGL loop.
		static void Render(Mesh*);	// Renders the provided Mesh
	};
}
