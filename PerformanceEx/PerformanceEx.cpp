// PerformanceEx.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Benchmark.h"
#include <thread>

using namespace std;

int main()
{
	Benchmark myBenchmark;
	int total = 0;

	myBenchmark.StartTimer();

	for (size_t i = 0; i < 10000000; i++)
	{
		total += i;		
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(15));

	myBenchmark.StopTimer();

	myBenchmark.GetVirtualMem();

	myBenchmark.GetRAM();

	myBenchmark.GetCPU();

	return 0;
}


