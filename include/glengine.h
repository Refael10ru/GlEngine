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
	private:
		void DeleteBufferObjects()	//	Deletes all the buffer objects
		{
			int size = this->VertexBufferObjects.size(); 
			
			for (int x = 0; x < size; x++)
				glDeleteBuffers(1, &this->VertexBufferObjects.at(x)); 
		}

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
			
			Debug->Log("Buffer object created succesfuly.");	

			// this->Bind(VertexArray, this->VertexArrayObjectID); // Binds the VAO
			glBindVertexArray(this->VertexArrayObjectID);

			Debug->Log(this->VertexBufferObjects.at(this->VertexBufferObjects.size() - 1)); 

			this->SetBufferData(this->VertexBufferObjects.at(this->VertexBufferObjects.size() - 1), vertexData, size);	// sets the data to the VBO 	
			
			Debug->Log("Buffer data set succesfully.");
	
			this->SetVertexAttributePointer(0); // sets Vertex Attribute pointer to id 0.
			// this->Bind(VertexArrayObject::VertexBuffe	r, 0);
			glBindBuffer(GL_ARRAY_BUFFER, 0); 
			// this->Bind(VertexArrayObject::VertexArray, 0);
			glBindVertexArray(0); 
		}
		
		~VertexArrayObject()
		{
			glDeleteVertexArrays(1, &this->VertexArrayObjectID);

			this->DeleteBufferObjects();		
		}
	}; 

	class Mesh 	//	3D/2D meshes
	{
	public:		
		int MatrixSize;	//	VertexMatrix array length

		// VertexArrayObject VAO;	// Vertex Array Object 
		
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

		Mesh(float* vertexMatrix, int size, Shader shader) : VertexMatrixVector(std::vector<Vertex3Df>()), VertexMatrixArray(vertexMatrix), MeshShader(shader)
		{
		}

		Mesh(std::vector<Vertex3Df> vertexMatrixVector) : VertexMatrixVector(vertexMatrixVector), VertexMatrixArray(General::VertexVectorToFloatArray(vertexMatrixVector)), MatrixSize(vertexMatrixVector.size() * 3), MeshShader(Shader())
		{
		}

		Mesh(std::vector<Vertex3Df>	vertexMatrixVector, Shader shader) : VertexMatrixVector(vertexMatrixVector),  VertexMatrixArray(General::VertexVectorToFloatArray(vertexMatrixVector)), MatrixSize(vertexMatrixVector.size() * 3), MeshShader(shader)
		{
			// if (vertexMatrixVector.size() > 0) 
				// this->SetVAO();
		}

		~Mesh()
		{
			delete &this->MeshShader;
			// delete &this->VAO;
		}
	};

	extern GLenum* GLObjectEnums; // Stores rendering type GLenums for different objects 

	class GLEObject
	{
	public:
		enum GLEObjectType
		{
			Triangle
		}; 
	
		unsigned int ID; 
		
		VertexArrayObject VAO;	//	VertexArrayObject of the mesh
		Mesh* ObjectMesh;	//	Primary mesh / 0th element of the MeshArray

		std::vector<Mesh*> MeshArray; //	Stores all the meshes created for the current instance

		void CreateObject(float*); 	// Creates a new Mesh instance with the provided vertex array's elements as its vertices, and adds it to MeshArray
		void CreateObject(std::vector<Vertex3Df>);	// Creates a new Mesh instance with the provided Vertex3Df array's elements as its vertices
		void CreateObject(std::vector<Vertex2Df>);	// Creates a new Mesh instance with the provided Vertex3D array's vertice  as its vertices
		void CreateObject(Mesh);	// Adds the provieded mesh to MeshArray	

		GLEObject();
		GLEObject(float*); 
		GLEObject(std::vector<Vertex3Df>); 
		GLEObject(std::vector<Vertex3Df>, GLEObject::GLEObjectType); 
		GLEObject(std::vector<Vertex3Df>, Shader); 
		GLEObject(float*, int, Shader); 
		GLEObject(std::vector<Vertex3Df>, Shader, GLenum); 
	};

	class Renderer
	{
	public:	
		static bool IsNull(); // Null checks all required Mesh properties
		static bool GLLoop(Window, GLEObject*);	//	Runs the OpenGL loop for the provided GLEObject.
		static bool GLLoop(Window, Mesh*);	//	 Runs the OpenGL loop for the provided Mesh.
		static void Render(GLEObject*);	// Renders the provided GLEObject's mesh
		static void Render(Mesh*);	// Renders the provided Mesh
	};

	extern std::vector<GLEObject*> AllocatedGLEObjects;	//	Stores +all the instances of GLEObject created durintg the execution
}
