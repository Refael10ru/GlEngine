#pragma once 

#define ALGORITHMS_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "ds.h"
#include "cartesianobj.h"
#include "glengine.h"

using namespace std;

namespace GLEngine
{
	class RandomAlgos
	{
	public:
	template<typename T>
		static void Swap(T* val, T* val1);
		 
		static int GetIndex(Point2D point, vector<Point2D> pointArray, int arrayLength);

		template<typename T>	// template for general data types
		static void PrintArray(vector<T> array);

		template<typename T>
		static bool IsElement(T val, vector<T> pointVector);

		template<typename T> 		
		static int PointCmp(T point, T point1);
		

		template<typename T>	
		static void PrintVector(vector<T>);

		template<typename T>	// todo: use a defined RegEx for printf();
		static void PrintPoint2DVector(vector<T> pointVector);	// for printing 2D Points/GLPoints 
		
		template<typename T>
		static void PrintPoint3DVector(vector<T> pointVector);	// for printing 3D Points/GLPoints		
	};

	class Sort
	{
	public:
		static void BubbleSort(Point2D* array, int len);
		
		static void BubbleSort(int* array, int len);

		static void BubbleSort(vector<Point2D> pointVector);

		template<typename T> 
		static void BubbleSort(vector<T> pointVector);
	};

	class Search
	{	
	public:
		static int LinearSearch(Point2D val, Point2D* array, int size);

		static int BinarySearch(Point2D val, vector<Point2D> array, int start, int end);
		
		template<typename T>
		static int BinarySearch(T val, vector<T> array, int start, int end);

		static int BinarySearch(GLPoint3D val, vector<GLPoint3D> array, int start, int end);

		static int BinarySearch(int val, int* array, int start, int end);
	};

	class Convert
	{
	public:
		static Point2D* VectorToPointArray(vector<Point2D > pointVector);	// converts vector<Point2D > to a Point2D  array;

		static GLPoint2D* VectorToGLPointArray(vector<Point2D> pointVector);	// converts vector<Point2D> to a Point2D array
		
		static Point2D* GLVectorToPointArray(vector<GLPoint2D> pointVector);	// converts vector<GLPoint> to a Point array
				
		static GLPoint2D* VectorToGLPointArray(vector<GLPoint2D> pointVector); // converts vector<GLPoint2D> to a GLPoint2D array
	
		static Point3D* VectorToPointArray(vector<Point3D> pointVector);	// converts vector<Point3D> to a Point3D  array;

		static GLPoint3D* VectorToGLPointArray(vector<Point3D> pointVector);	// converts vector<Point3D> to a Point3D array
		
		static Point3D* GLVectorToPointArray(vector<GLPoint3D> pointVector);	// converts vector<GLPoint3D> to a Point3D array
				
		static GLPoint3D* VectorToGLPointArray(vector<GLPoint3D> pointVector); // converts vector<GLPoint3D> to a GLPoint3D array

		Convert()
		{}
	};
}
