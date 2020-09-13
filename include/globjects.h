#pragma once

#define GLEOBJECTS_H 

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <GLFW/glfw3.h> 
#include "gltypes.h"
#include "globjects.h"
#include "defaults.h"
// #include "executiondata.h"

namespace GLEngine
{
	struct Point2D
	{	
		int X, Y; 

		Point2D() : X(0), Y(0)
		{
		}

		Point2D(int x, int y) : X(x), Y(y)
		{
		}

		Point2D operator +(const Point2D& rhs)
		{
			return Point2D(Point2D(this->X + rhs.X, this->Y + rhs.Y)); 
		}	
		
		Point2D operator -(const Point2D& rhs)
		{
			return Point2D(Point2D(this->X - rhs.X, this->Y - rhs.Y)); 
		}	
		
		Point2D operator *(const Point2D& rhs)
		{
			return Point2D(Point2D(this->X * rhs.X, this->Y * rhs.Y)); 
		}	

		Point2D operator /(const Point2D& rhs)
		{
			return Point2D(Point2D(this->X / rhs.X, this->Y / rhs.Y)); 
		}	
	}; 

	struct Point3D	// Stores a 3D Point
	{
	public:
		int X, Y, Z; 

		Point3D() : X(0), Y(0), Z(0)
		{
		}
		
		Point3D(int x, int y, int z) : X(x), Y(y), Z(z)
		{
		}

		Point3D operator +(const Point3D& rhs)
		{
			return Point3D(this->X + rhs.X, this->Y + rhs.Y, this->Z + rhs.Z);
		}
		
		Point3D operator -(const Point3D& rhs)
		{
			return Point3D(this->X - rhs.X, this->Y - rhs.Y, this->Z - rhs.Z);
		}
		
		Point3D operator *(const Point3D& rhs)
		{
			return Point3D(this->X * rhs.X, this->Y * rhs.Y, this->Z * rhs.Z);
		}

		Point3D operator /(const Point3D& rhs)
		{
			return Point3D(this->X / rhs.X, this->Y / rhs.Y, this->Z / rhs.Z);
		}
	}; 

	extern String* DefaultStringValues; // = new String[1] {
		// "New Window"
	// }; 

	extern Point2D* DefaultResolutions; // = new Point2D[1] {
		// Point2D(800, 600)
	// };
	
	enum DefaultStringType
	{
		WindowTitleStrings
	};

	enum DefaultResolutionType
	{
		DefaultWindow
	}; 

	struct Color	// Stores RGB values.
	{
		float R, G, B, A; 

		Color() : R(0), G(0), B(0), A(0)
		{		
		}
		
		Color(float r, float g, float b, float a) : R(r), G(g), B(b), A(0)
		{
		}

		Color(float r, float g, float b) : R(r), G(g), B(b)
		{
		}
	}; 

	// Contains data about a window.
}

// std::vector<GLEngine::Window*> AllocatedWindows = std::vector<GLEngine::Window*>();	// Execution Data
	