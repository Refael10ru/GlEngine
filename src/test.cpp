#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "globjects.h"
#include "glengine.h"
#include "window.h"
#include "shader.h"
#include "fileio.h"

using namespace GLEngine;  

int main()
{ 
	if (!SetupGLFW())	// Sets GLFW up
		return -1; 	
		
	Window window = Window("GLEngine App", Point2D(1920, 1080), Color(0.2, 0.3, 0.3, 1));

	glfwMakeContextCurrent(window.GLWindow); 
	glfwSetFramebufferSizeCallback(window.GLWindow, window.FrameBufferSizeCallBack); 
	
	std::cout << "GLEW Status: " << SetupGLEW();     

	std::vector<Vertex3Df> vertexVector = {
		Vertex3Df(Point3Df(-0.2, -0.2, 0.0), Color()),	// Left
		Vertex3Df(Point3Df(0.2, -0.2, 0.0), Color()),	// Right
		Vertex3Df(Point3Df(0.0, 0.2	, 0.0), Color())	// Top
	};

	char* VertexShaderString = FileIO::Read("/home/rishit/source/repos/GLEngine/shaders/vertexshader.vs"),
	 *FragmentShaderString = FileIO::Read("/home/rishit/source/repos/GLEngine/shaders/fragmentshader.fs"); 

	// Mesh* mesh = new Mesh(vertexVector, Shader(VertexShaderString, FragmentShaderString, true)); 

	GLEObject* Object = new GLEObject(vertexVector, Shader(VertexShaderString, FragmentShaderString, true)); 
	
	Renderer::GLLoop(window, Object);	

	glfwTerminate();

	return 0; 
}
