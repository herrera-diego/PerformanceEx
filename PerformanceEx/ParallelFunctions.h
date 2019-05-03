#pragma once

#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

template <class T>
class ParallelFunctions
{
private:
	void swap(T *xp, T *yp);
	void printArray(T arr[], int size);
public:
	ParallelFunctions();
	~ParallelFunctions();
	void SortParallel(T arr[], int n);
	void SortSequential(T arr[], int n);
	void AutoSortParallel(T arr[], int n);
};

