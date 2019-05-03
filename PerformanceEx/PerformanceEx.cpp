// PerformanceEx.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <thread>
#include "Benchmark.h"
#include "ParallelFunctions.h"

using namespace std;

int main()
{
	Benchmark myBenchmark;
	ParallelFunctions parFunctions;
	int total = 0;

	const int arraySize = 30;

	int myArray[arraySize] ;

	for (size_t i = 0; i < arraySize; i++)
	{
		myArray[i] = rand() % 100;
	}

	int n = sizeof(myArray) / sizeof(myArray[0]);

	myBenchmark.StartTimer();

	parFunctions.SortSequential(myArray, n);

	//std::this_thread::sleep_for(std::chrono::milliseconds(1));

	myBenchmark.StopTimer();

	myBenchmark.GetVirtualMem();

	myBenchmark.GetRAM();

	myBenchmark.GetCPU();

	return 0;
}


