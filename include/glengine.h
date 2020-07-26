#pragma once

#define GLENGINE_H


#include <GLFW/glfw3.h>
#include "cartesianobj.h"
#include "cartesian.h"

using namespace CartesianObjects;

namespace GLEngine 
{
	class Window	// stores the config 
	{
	public:
		char* Title;
		
		Coordinates2D Dimensions;

		Window(Coordinates2D dimensions, char* title) : Dimensions(dimensions), Title(title)
		{}

		Window(Coordinates2D dimensions) : Dimensions(dimensions), Title("New Window")
		{}
	};
}