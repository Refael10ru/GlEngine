#pragma once 

#include "glengine.h"
#include "exceptions.h"


void GLEngine::Mesh::SetVAO()
{
	this->VAO = GLEngine::VertexArrayObject(); 
}

void GLEngine::VertexArrayObject::CreateBufferObject()
{
	unsigned int BufferObject;	// buffer object to be created
	
	glGenBuffers(GL_ARRAY_BUFFER, &BufferObject);

	this->VertexBufferObjects.push_back(BufferObject);
}

void GLEngine::VertexArrayObject::Bind(GLEngine::VertexArrayObject::ObjectType objectType, unsigned int id)
{
	glBindBuffer(1, this->VertexBufferObjects.at(id));
}

void GLEngine::VertexArrayObject::SetBufferData(unsigned int bufferID, Vertex3Df* vertexArray, int arraySize)
{	
	this->Bind(VertexArrayObject::VertexBuffer, bufferID); 	//	Binds the provided vertex buffer
	
	glBufferData(GL_ARRAY_BUFFER, arraySize * 3, General::VertexArrayToFloatArray(vertexArray, arraySize), GL_STATIC_DRAW);	//	Adds data to the buffer
}

void GLEngine::VertexArrayObject::SetVertexAttributePointer(unsigned int id)
{
	glVertexAttribPointer(id, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(id);
}
