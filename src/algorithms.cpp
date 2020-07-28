// for definition of functions declared in algorithms.h
#include "algorithms.h"

namespace GLEngine
{
	template<typename T>
	void RandomAlgos::Swap(T* val, T* val1)
	{
		T* temp = val;

		val = val1;
		val1 = temp;
	}

	template<typename T> 		
	int RandomAlgos::PointCmp(T point, T point1)
	{	
		if (point.Coordinates.Y == point1.Coordinates.Y && point.Coordinates.X == point1.Coordinates.X)
			return 0;

		if (point.Coordinates.Y > point1.Coordinates.Y)
			return 1;
				
		return -1;
	} 	

	int RandomAlgos::GetIndex(Point2D point, vector<Point2D> pointArray, int arrayLength)
	{
		return Search::BinarySearch(point, pointArray, 0, arrayLength);
	}

	template<typename T>
	void RandomAlgos::PrintVector(vector<T> array)
	{
		for (int x = 0; x < array.size(); x++)
			std::cout << array.at(x);
	}
	
	template<typename T>
	bool RandomAlgos::IsElement(T val, vector<T> pointVector)
	{
		return (Search::BinarySearch(val, pointVector, 0, pointVector.size() - 1) >= 0) ? true : false;
	}
	
	template<typename T>
	void RandomAlgos::PrintPoint2DVector(vector<T> point2DVector)
	{
		for (int x = 0; x < point2DVector.size(); x++)
			printf("(%f, %f)\n", point2DVector.at(x).Coordinates.X, point2DVector.at(x).Y);				
	}

	template<typename T>
	void RandomAlgos::PrintPoint3DVector(vector<T> point3DVector)
	{
		for (int x = 0; x < point3DVector.size(); x++)
			printf("(%f, %f, %f)\n", point3DVector.at(x).Coordinates.X, point3DVector.at(x).Y, point3DVector.at(x).Coordinates.X);				
	}

	void Sort::BubbleSort(Point2D* array, int len)
	{
		for (int x = 0; x < len; x++)
			for (int y = 0;  y < len - x - 1; x++)	
				if (array[y].Coordinates.Y > array[y + 1].Coordinates.Y)
					RandomAlgos::Swap(&array[y], &array[y + 1]);				
	}

	void Sort::BubbleSort(int* array, int len)
	{
		for (int x = 0; x < len - 1; x++)
			for (int y = 0;  y < len - x - 1; y++)
				if (array[y] > array[y + 1])
					RandomAlgos::Swap(array + y, array + (y + 1));	
	} 

	void Sort::BubbleSort(vector<Point2D> pointVector)
	{
		int len;

		for (int x = 0; x < (len = pointVector.size()) - 1; x++)
			for (int y = 0; y <  len -  x - 1; y++)
				if (RandomAlgos::PointCmp(pointVector.at(y), pointVector.at(y + 1)) > 0)
					RandomAlgos::Swap<Point2D>(&pointVector.at(y), &pointVector.at(y + 1));
	}

	template <typename T>
	void Sort::BubbleSort(vector<T> pointVector)
	{
		int len;

		for (int x = 0; x < (len = pointVector.size()) - 1; x++)
			for (int y = 0; y <  len -  x - 1; y++)
				if (RandomAlgos::PointCmp(pointVector.at(y), pointVector.at(y + 1)) > 0)
					RandomAlgos::Swap<T>(&pointVector.at(y), &pointVector.at(y + 1));
	}

	int Search::LinearSearch(Point2D val, Point2D* array, int size)
	{	
		for (int x = 0; x < size; x++)
			if (val.Coordinates.X ==  array[x].Coordinates.X && val.Coordinates.Y ==  array[x].Coordinates.Y)
				return true;

		return -1;
	}

	int Search::BinarySearch(Point2D val, vector<Point2D> array, int start, int end)
	{
		int mid = start + end - start / 2;

		if (end >= start)
		{
			if (!RandomAlgos::PointCmp(val, array.at(mid)))
				return mid;

			if (RandomAlgos::PointCmp(val, array.at(mid)) == 1)
				return Search::BinarySearch(val, array, mid + 1, end);
			
			if (RandomAlgos::PointCmp(val, array.at(mid)) == -1)			
				return Search::BinarySearch(val, array, start, mid - 1);
		}		

		return -1;
	}

	template<typename T>
	int Search::BinarySearch(T val, vector<T> array, int start, int end)
	{
		int mid = start + end - start / 2;

		if (end >= start)
		{
			if (!RandomAlgos::PointCmp<T>(val, array.at(mid)))
				return mid;

			if (RandomAlgos::PointCmp<T>(val, array.at(mid)) == 1)
				return Search::BinarySearch<T>(val, array, mid + 1, end);
			
			if (RandomAlgos::PointCmp<T>(val, array.at(mid)) == -1)			
				return Search::BinarySearch<T>(val, array, start, mid - 1);
		}		

		return -1;
	}

	int Search::BinarySearch(int val, int* array, int start, int end)
	{
		if (end >= start)
		{
			int mid = end + (end - start) / 2;

			if (array[mid] == val)
				return mid;

			if (array[mid] < val)
				return BinarySearch(val, array, mid + 1, end);

			return BinarySearch(val, array, start, mid - 1);
		}

		return -1;
	}

	Point2D * Convert::VectorToPointArray(vector<Point2D > pointVector)	// converts vector<Point2D > to a Point2D  array
	{
		int vectorSize; // temp to store pointVector size

		Point2D* pointArray = new Point2D[(vectorSize = pointVector.size())]; 

		for (int x = 0; x < vectorSize; x++)
			pointArray[x] = pointVector.at(x);

		return pointArray;
	}

	GLPoint2D* Convert::VectorToGLPointArray(vector<Point2D> pointVector)	// converts vector<Point2D> to a Point2D array
	{
		int vectorSize;	// temp to store pointVector size

		GLPoint2D* glPointArray = new GLPoint2D[pointVector.size()];
		
		for (int x = 0; x < vectorSize; x++)
			glPointArray[x] = GLPoint2D(pointVector.at(x));

		return glPointArray;
	}

	Point2D* Convert::GLVectorToPointArray(vector<GLPoint2D> pointVector)	// converts vector<GLPoint> to a Point array
	{
		int vectorSize; // temp to store pointVector size

		GLPoint2D pointTemp; 	

		Point2D* pointArray = new Point2D[(vectorSize = pointVector.size())]; 

		for (int x = 0; x < vectorSize; x++)
			pointArray[x] = Point2D((pointTemp = pointVector.at(x)).Coordinates, pointTemp.plotStatus);	// assigns pointArray[x] to a Point2D with Coordinates same as the GLPoint 

		return pointArray;
	}

	GLPoint2D* Convert::VectorToGLPointArray(vector<GLPoint2D> pointVector) // converts vector<GLPoint2D> to a GLPoint2D array
	{
		int vectorSize; // temp to store pointVector size

		GLPoint2D* pointArray = new GLPoint2D[(vectorSize = pointVector.size())]; 

		for (int x = 0; x < vectorSize; x++)
			pointArray[x] = pointVector.at(x);

		return pointArray;
	}

	Point3D * Convert::VectorToPointArray(vector<Point3D > pointVector)	// converts vector<Point2D > to a Point2D  array
	{
		int vectorSize; // temp to store pointVector size

		Point3D* pointArray = new Point3D[(vectorSize = pointVector.size())]; 

		for (int x = 0; x < vectorSize; x++)
			pointArray[x] = pointVector.at(x);

		return pointArray;
	}

	GLPoint3D* Convert::VectorToGLPointArray(vector<Point3D> pointVector)	// converts vector<Point2D> to a Point2D array
	{
		int vectorSize;	// temp to store pointVector size

		GLPoint3D* glPointArray = new GLPoint3D[pointVector.size()];
		
		for (int x = 0; x < vectorSize; x++)
			glPointArray[x] = GLPoint3D(pointVector.at(x));

		return glPointArray;
	}

	Point3D* Convert::GLVectorToPointArray(vector<GLPoint3D> pointVector)	// converts vector<GLPoint> to a Point array
	{
		int vectorSize; // temp to store pointVector size

		GLPoint3D pointTemp; 	

		Point3D* pointArray = new Point3D[(vectorSize = pointVector.size())]; 

		for (int x = 0; x < vectorSize; x++)
			pointArray[x] = Point3D((pointTemp = pointVector.at(x)).Coordinates, pointTemp.plotStatus);	// assigns pointArray[x] to a Point2D with Coordinates same as the GLPoint 

		return pointArray;
	}

	GLPoint3D* Convert::VectorToGLPointArray(vector<GLPoint3D> pointVector) // converts vector<GLPoint2D> to a GLPoint2D array
	{
		int vectorSize; // temp to store pointVector size

		GLPoint3D* pointArray = new GLPoint3D[(vectorSize = pointVector.size())]; 

		for (int x = 0; x < vectorSize; x++)
			pointArray[x] = pointVector.at(x);

		return pointArray;
	}
}