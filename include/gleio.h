#pragma once

#define GLEIO_H

#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace GLEngine
{
	class GLEIO	// GLE input output class
	{
	public:
		static void ProcessInput(GLFWwindow* window);	// gets input events for the specified glfw window
	};
} 