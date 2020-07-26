#pragma once 

#define ALGORITHMS_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "ds.h"
#include "cartesianobj.h"
#include "glengine.h"

using namespace DataStructures;
using namespace CartesianObjects;
using namespace GLEngine;
using namespace std;


namespace Algorithms
{
	class RandomAlgos
	{
	public:
	template<typename T>
		static void Swap(T* val, T* val1);
		 
		static int GetIndex(Point2D point, vector<Point2D> pointArray, int arrayLength);

		template<typename T>
		static bool IsElement(T val, vector<T> pointVector);

		template<typename T> 		
		static int PointCmp(T point, T point1);
		
		static void PrintVector(vector<Point2D> pointVector);
		
		static void PrintVector(vector<GLPoint2D> pointVector);
	};

	class Sort
	{
	public:
		static void BubbleSort(Point2D* array, int len);
		
		static void BubbleSort(int* array, int len);

		static void BubbleSort(vector<Point2D> pointVector);
		
		static void BubbleSort(vector<GLPoint2D> pointVector);
	};

	class Search
	{	
	public:
		static int LinearSearch(Point2D val, Point2D* array, int size);

		static int BinarySearch(Point2D val, vector<Point2D> array, int start, int end);
		
		static int BinarySearch(GLPoint2D val, vector<GLPoint2D> array, int start, int end);
		
		static int BinarySearch(int val, int* array, int start, int end);
	};

	class Convert
	{
	public:
		static Point2D * VectorToPointArray(vector<Point2D > pointVector);	// converts vector<Point2D > to a Point2D  array;

		static GLPoint2D* VectorToGLPointArray(vector<Point2D> pointVector);	// converts vector<Point2D> to a Point2D array
		;
		
		static Point2D* GLVectorToPointArray(vector<GLPoint2D> pointVector);	// converts vector<GLPoint> to a Point array
		;
		
		static GLPoint2D* VectorToGLPointArray(vector<GLPoint2D> pointVector); // converts vector<GLPoint2D> to a GLPoint2D array
		;
	};
}