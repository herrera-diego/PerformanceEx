#include "pch.h"
#include "ParallelFunctions.h"


template<class T>
ParallelFunctions<T>::ParallelFunctions()
{
}

template<class T>
ParallelFunctions<T>::~ParallelFunctions()
{
}

template <class T>
void ParallelFunctions<T>::SortSequential(T arr[], int n)
{

	int i, j;

	printArray(arr, n);

	for (i = 0; i < n - 1; i++)
	{
		// Last i elements are already in place    
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}

	printArray(arr, n);
}

template <class T>
void ParallelFunctions<T>::SortParallel(T arr[], int n)
{
	int i, j;

	printArray(arr, n);

	for (i = 0; i < n - 1; i++)
	{
		// Last i elements are already in place    
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}

		for_each(std::begin(arr), std::end(arr), [&](int)
		{
			//std::lock_guard<std::mutex> guard(m); // Error: lock_guard constructor calls m.lock()
			//++x;
		});
	}

	printArray(arr, n);
}



template <class T>
void ParallelFunctions<T>::AutoSortParallel(T arr[], int n)
{
}

template <class T>
void ParallelFunctions<T>::swap(T *xp, T *yp)
{
	T temp = *xp;
	*xp = *yp;
	*yp = temp;
}

template <class T>
void ParallelFunctions<T>::printArray(T arr[], int size)
{
	int i;
	cout << "Array: ";
	for (i = 0; i < size; i++)
	{
		cout << arr[i]<< " ";		
	}

	cout<< " Size: "
		<< size
		<< endl;
}

