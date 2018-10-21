#pragma once
#include <vector>

#include "RoundRobin.h"
#include "Process.h"

class Scheduler{
public:
	Scheduler(const std::vector<Process>& processes);
	virtual ~Scheduler();
	void scheduleTimeSlice();
	void removeProcess(const Process& process);
private:
	RoundRobin<Process> rr;
};

