#include "pch.h"
#include "ParallelFunctions.h"


ParallelFunctions::ParallelFunctions()
{
}


ParallelFunctions::~ParallelFunctions()
{
}

void ParallelFunctions::SortParallel(int arr[], int n)
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

		for_each(std::execution::par_unseq, std::begin(arr), std::end(arr), [&](int) {
			std::lock_guard<std::mutex> guard(m); // Error: lock_guard constructor calls m.lock()
			++x;
		});
	}

	printArray(arr, n);
}

void ParallelFunctions::SortSequential(int arr[], int n)
{

	int i, j;

	printArray(arr,n);

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

void ParallelFunctions::AutoSortParallel(int arr[], int n)
{
}

void ParallelFunctions::swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void ParallelFunctions::printArray(int arr[], int size)
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