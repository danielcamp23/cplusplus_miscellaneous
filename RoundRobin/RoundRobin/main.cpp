/*
Code extracted from Professional C++ by Marc Gregoire
*/

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

#include "Process.h"
#include "Scheduler.h"


int main() {
	std::vector<Process> processes = { Process("1"), Process("2"), Process("3") };
	Scheduler sched(processes);
	for (int i = 0; i < 6; ++i)
		sched.scheduleTimeSlice();
	sched.removeProcess(processes[1]);
	std::cout << "Removed second process" << std::endl;
	for (int i = 0; i < 5; ++i)
		sched.scheduleTimeSlice();
	return 0;
}