#pragma once

#include "windows.h"
#include "TCHAR.h"
#include "pdh.h"
#include "psapi.h"
#include <chrono>
#include <iostream>


using namespace std;

class Benchmark
{
private:
	chrono::time_point<chrono::steady_clock> _start;

	static float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks);
	static unsigned long long FileTimeToInt64(const FILETIME & ft) { return (((unsigned long long)(ft.dwHighDateTime)) << 32) | ((unsigned long long)ft.dwLowDateTime); }

	// Returns 1.0f for "CPU fully pinned", 0.0f for "CPU idle", or somewhere in between
	// You'll need to call this at regular intervals, since it measures the load between
	// the previous call and the current one.  Returns -1.0 on error.

public:
	Benchmark();
	void GetVirtualMem();
	void GetRAM();
	void GetCPU();
	void StartTimer();
	void StopTimer();
	~Benchmark();
};

