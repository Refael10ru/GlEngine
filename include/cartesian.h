// #pragma once

// #define CARTESIAN_H

// #include <vector>
// #include <stack>
// #include "cartesianobj.h"
// #include "glengine.h"

// #ifndef ALGORITHMS_H
// 	#include "algorithms.h"
// #endif

// namespace GLEngine
// {
// 	class Plane2D
// 	{
// 	public:
// 		std::vector<Point2D> PointVector;  // for storing all the points present in the plane
		
// 		GLPoint2D* GLPointArray;

// 		Window PlaneWindow;

// 		Plane2D(std::vector<Point2D> pointVector) : PointVector(pointVector), GLPointArray(Convert::VectorToGLPointArray(this->PointVector)), PlaneWindow(Window(Coordinates2D()))	// temporary contstructor
// 		{
// 		}	

// 		void Update(); // syncs the GLPoint array with PointVector

// 		bool Add(Point2D);	// adds the provided Point2D to PointVector and sorts the the updated GLPointArray	

// 	};
// }