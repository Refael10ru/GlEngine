#include "gleio.h"

namespace GLEngine
{
	void GLEIO::ProcessInput(GLFWwindow* window) 
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);
	}
}