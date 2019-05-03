#pragma once

#include <iostream>

using namespace std;

class ParallelFunctions
{
private:
	void swap(int *xp, int *yp);
	void printArray(int arr[], int size);
public:
	ParallelFunctions();
	~ParallelFunctions();

	void SortParallel(int arr[], int n);
	void SortSequential(int arr[], int n);
	void AutoSortParallel(int arr[], int n);
};

