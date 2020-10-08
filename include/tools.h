#pragma once

#define TOOLS_H

#include "gltypes.h"
#include "globjects.h"
#include "globals.h"

namespace GLEngine
{
	class General
	{  
	public:
		template<typename T>
		static void Swap(T* val, T* val1)
		{
			T* temp = val;

			val = val1; 
			val1 = temp; 
		}
		
		template<typename T>
		static void PrintArray(T* array, unsigned int size)
		{	
			for (int x = 0; x < size; x++) 
			{
				std::cout << array[x] << " ";
			}
		}
		
		template<typename T>
		static void PrintArray(std::vector<T> array)
		{	
			for (int x = 0; x < array.size(); x++) 
				std::cout << array.at(x);
		}

		template<typename T>
		static void PrintVectorArray(std::vector<T> array)
		{
			unsigned int size = array.size(); 

			for (int x  = 0; x < size; x++)
				std::cout << array.at(x)
				<< '\n';
		}
		
		static void PrintVectorArray(std::vector<Vertex3Df> array)
		{ 
			for (int x = 0; x < array.size(); x++)
				std::cout << '\n' << x 
				<< "(" <<  array.at(x).Position.X
				<< ", " << array.at(x).Position.Y
				<< ", " << array.at(x).Position.Z
				<< "); ";
		}

		static void PrintArray(Vertex3Df* array, unsigned int size)
		{
			for (int x = 0; x < size; x++)
			{
				std::cout << "Position: "<< array[x].Position.X << ", " << array[x].Position.Y
						<< "\nColor: " << "R: " << array[x].VertexColor.R << "G: " << array[x].VertexColor.G  << "B: " << array[x].VertexColor.B << "A: " << array[x].VertexColor.A
						<< '\n';	
			}
		}

		static void PrintVertexFloatArray(float* array, unsigned int size)
		{
			for (int x = 0; x < size / 3; x++)
				std::cout << '\n' << x << " (X: " << array[x]
				 << ", Y: " <<  array[x + 1]
				 << ", Z: " <<  array[x + 2] <<  "); ";
		}

		static float* PointVectorToFloatArray(std::vector<Point3Df> pointVector)	//	Converts an std::vector<Point3Df> to a T* (probably a float or an int	) array	
		{
			size_t VectorSize = pointVector.size();

			float* Array = new float[VectorSize * 3];

			for (int x = 0; x < VectorSize; x += 3)	//	Sets up the matrix rows
			{
				Array[x] = pointVector.at(x).X;  
				Array[x + 1] = pointVector.at(x).Y;  
				Array[x + 2] = pointVector.at(x).Z;
			}

			return Array;	
		}

		static float* PointArrayToFloatArray(Point3Df* pointArray, int size)	
		{
			float* floatArray = new float[size * 3]; 

			for (int x = 0; x < size; x += 3)	
			{
				floatArray[x] = pointArray->X;
				floatArray[x + 1] = pointArray->Y;
				floatArray[x + 2] = pointArray->Z;
			}

			return floatArray;
		}

		static float* VertexVectorToFloatArray(std::vector<Vertex3Df> vertexArray)	
		{
			int size;

			float* floatArray = new float[(size = vertexArray.size()) * 3]; 
		
			for (int x = 0; x < size; x++)	
			{
				floatArray[x + ((size - 1) * x)] = vertexArray.at(x).Position.X;
				floatArray[(x + ((size - 1) * x)) + 1] = vertexArray.at(x).Position.Y;
				floatArray[(x + ((size - 1) * x)) + 2] = vertexArray.at(x).Position.Z;
			}

			return floatArray;
		}

		static float* PointArrayToFloatArray(Vertex3Df* pointArray, int size)	
		{
			float* floatArray = new float[size * 3]; 

			for (int x = 0; x < size; x += 3)	
			{
				floatArray[x] = pointArray->Position.X;
				floatArray[x + 1] = pointArray->Position.Y;
				floatArray[x + 2] = pointArray->Position.Z;
			}

			return floatArray;
		}

		template<typename T>
		static T* VectorToArray(std::vector<T> vector)
		{
			int size;
			
			T* array = new T[size = vector.size()]; 

			for (int x = 0; x < size; x++)
				array[x] = vector.at(x);

			return array;
		}

		static float* VertexArrayToFloatArray(Vertex3Df* vertexArray, int size)
		{	
			float* array = new float[size * 3]; 

			for (int x = 0; x < size; x++)
			{
				array[x] = vertexArray[x].Position.X;
				array[x] = vertexArray[x].Position.Y;
				array[x] = vertexArray[x].Position.Z;
			}

			return array;
		}
	};

	class Algorithms 
	{
	public: 	
		template<typename T>
		static void BubbleSort(T* array, int size)  //  Sorts the provided array
		{
			for (int x = 0; x < size - 1; x++)
				for (int y = 0;  y < size - x - 1; x++)
					if (array[y] > array[y + 1])
						General::Swap(&array[y], &array[y + 1]); 
		}

		template<typename T>
		static void BubbleSort(std::vector<T> array)    //  Sorts the provided std::vector<T>/array
		{
			int size = array.size();

			for (int x = 0; x < size - 1; x++)
				for (int y = 0;  y < size - x - 1; x++)
					if (array.at(y) > array.at(y + 1))
						General::Swap(&array.at(y), &array.at(y + 1)); 
		}

		template<typename T>
		static int BinarySearch(T val, T* array, int start, int end)	//	Binary search implementation for T array
		{
			int mid = start + end - 1 / 2;

			if (start <= end)
			{
				if (array[mid] == val)
					return array[mid]; 
				
				if (array[mid] > val)
					return Algorithms::BinarySearch<T>(val, array, mid, end);
				
				if (array[mid] < val)
					return Algorithms::BinarySearch<T>(val, array, start, mid); 
			}

			return -1; 
		}
		
		template<typename T>
		static int BinarySearch(T val, std::vector<T> array, int start, int end)	//	Binary search implementation for std::vector<T>
		{
			int mid = start + end - 1 / 2;

			if (start <= end)
			{
				if (array.at(mid) == val)
					return array.at(mid); 
				
				if (array.at(mid) > val)
					return Algorithms::BinarySearch<T>(val, array, mid, end);
				
				if (array.at(mid) < val)
					return Algorithms::BinarySearch<T>(val, array, start, mid); 
			}

			return -1; 
		}

		template<typename T>
		static int BinarySearch(T val, std::vector<T> array)	//	Binary search implementation for std::vector<T>, 1 instruction slower than the traditional implementation
		{

			int start = 0, end = array.size(),  mid = start + end - 1 / 2;

			if (start <= end)
			{
				if (array.at(mid) == val)
					return array.at(mid); 
				
				if (array.at(mid) > val)
					return Algorithms::BinarySearch<T>(val, array, mid, end);
				
				if (array.at(mid) < val)
					return Algorithms::BinarySearch<T>(val, array, start, mid); 
			}

			return -1; 
		}

		template<typename T>
		static int GetIndex(T* val, T* array, int size)		//	Finds the index of the provided value (if exists) in the array
		{
			return Algorithms::BinarySearch(val, array, 0, size); 
		}
		
		template<typename T>
		static int GetIndex(T* val, std::vector<T> array)		//	Finds the index of the provided value (if exists) in the std::vector<T>/array
		{
			return Algorithms::BinarySearch(val, array, 0, array.size()); 
		}

		template<typename T>
		static bool IsElement(T val, T* array, int size)	//	Checks if the given element is present in the given array, returns a bool represnting the same
		{
			return (Algorithms::BinarySearch(val, array, 0, size) >= 0);	
		} 
	
		template<typename T>
		static bool IsElement(T val, std::vector<T> array)	//	Checks if the given element is present in the given array, returns a bool represnting the same
		{
			return (Algorithms::BinarySearch(val, array, 0, array.size()) >= 0);	
		} 
	}; 
}
