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

	new Mesh();

	// Mesh mesh = Mesh({
	// 	Vertex3Df(Point3Df(-0.5, -0.5, 0.0), Color()), 
	// 	Vertex3Df(Point3Df(0.5, -0.5, 0.0), Color()), 
	// 	Vertex3Df(Point3Df(0.0, 0.5, 0.0), Color())
	// }); 

	glfwMakeContextCurrent(window.GLWindow); 

	glfwSetFramebufferSizeCallback(window.GLWindow, window.FrameBufferSizeCallBack); 

	SetupGLEW();     

	Renderer::GLLoop(window, new Mesh());

	glfwTerminate();

	return 0; 
}