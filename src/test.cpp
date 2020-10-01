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
		
	Window window = Window("GLEngine App", Color(1, 0.1, 0.5, 1));

	glfwMakeContextCurrent(window.GLWindow); 
	glfwSetFramebufferSizeCallback(window.GLWindow, window.FrameBufferSizeCallBack); 
	
	std::cout << "GLEW Status: " << SetupGLEW();     

	std::vector<Vertex3Df> vertexVector = {
		Vertex3Df(Point3Df(-0.5, -0.5, 0.0), Color()),
		Vertex3Df(Point3Df(0.5, -0.5, 0.0), Color()),
		Vertex3Df(Point3Df(0.0, 0.5, 0.0), Color())
	};

	char* VertexShaderString = FileIO::Read("/home/rishit/source/repos/GLEngine/shaders/vertexshader.vs"),
	 *FragmentShaderString = FileIO::Read("/home/rishit/source/repos/GLEngine/shaders/fragmentshader.fs"); 

	Mesh* mesh = new Mesh(vertexVector, Shader(VertexShaderString,FragmentShaderString, true)); 

	Renderer::GLLoop(window); 

	glfwTerminate();

	return 0; 
}
