#include "pch.h"
#include "Benchmark.h"


Benchmark::Benchmark()
{

}


float Benchmark::CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
	static unsigned long long _previousTotalTicks = 0;
	static unsigned long long _previousIdleTicks = 0;

	unsigned long long totalTicksSinceLastTime = totalTicks - _previousTotalTicks;
	unsigned long long idleTicksSinceLastTime = idleTicks - _previousIdleTicks;

	float ret = 1.0f - ((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime) / totalTicksSinceLastTime : 0);

	_previousTotalTicks = totalTicks;
	_previousIdleTicks = idleTicks;
	return ret;
}



void Benchmark::GetVirtualMem()
{
	// Total
	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memInfo);
	DWORDLONG totalVirtualMem = memInfo.ullTotalPageFile;

	//Currently Used
	DWORDLONG virtualMemUsed = memInfo.ullTotalPageFile - memInfo.ullAvailPageFile;

	//Used by Process
	PROCESS_MEMORY_COUNTERS_EX  pmc;
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	SIZE_T virtualMemUsedByMe = pmc.PrivateUsage;

	cout << "Virtual Memory Available: "
		 << totalVirtualMem
		 << endl;

	cout << "Virtual Memory Used: "
		<< virtualMemUsed
		<< endl;

	cout << "Virtual Memory Used by Process: "
		<< virtualMemUsedByMe
		<< endl;

}

void Benchmark::GetRAM()
{
	// Total
	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memInfo);
	DWORDLONG totalPhysMem = memInfo.ullTotalPhys;


	//Currently Used
	DWORDLONG physMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;

	//Used by Process
	PROCESS_MEMORY_COUNTERS_EX  pmc;
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	SIZE_T physMemUsedByMe = pmc.WorkingSetSize;

	cout << "RAM Available: "
		<< totalPhysMem
		<< endl;

	cout << "RAM Used: "
		<< physMemUsed
		<< endl;

	cout << "RAM Used by Process: "
		<< physMemUsedByMe
		<< endl;
}


void Benchmark::GetCPU()
{
	FILETIME idleTime, kernelTime, userTime;
	auto cpuLoad = GetSystemTimes(&idleTime, &kernelTime, &userTime) ? CalculateCPULoad(FileTimeToInt64(idleTime), FileTimeToInt64(kernelTime) + FileTimeToInt64(userTime)) : -1.0f;
	cout << "CPU Load : "
		<< cpuLoad * 100
		<< " %" << endl;
}

void Benchmark::StartTimer()
{
	_start = chrono::steady_clock::now();
	
}

void Benchmark::StopTimer()
{
	auto end = chrono::steady_clock::now();

	cout << "Elapsed time in nanoseconds : "
		 << chrono::duration_cast<chrono::nanoseconds>(end - _start).count()
		 << " ns" << endl;

	cout << "Elapsed time in microseconds : "
		 << chrono::duration_cast<chrono::microseconds>(end - _start).count()
		 << " us" << endl;

	cout << "Elapsed time in milliseconds : "
		 << chrono::duration_cast<chrono::milliseconds>(end - _start).count()
		 << " ms" << endl;

	cout << "Elapsed time in seconds : "
		 << chrono::duration_cast<chrono::seconds>(end - _start).count()
		 << " sec" << endl;
}

Benchmark::~Benchmark()
{
}
