#include "pch.h"
#include <iostream>
#include <string>

#include "Scheduler.h"

Scheduler::Scheduler(const std::vector<Process>& processes) {
	for (auto& process : processes) {
		rr.add(process);
	}
}

Scheduler::~Scheduler() {
}

void Scheduler::scheduleTimeSlice() {
	try {
		rr.getNext().doSomeTask();
	}
	catch (const std::out_of_range& e) {
		std::cerr<<e.what()<<std::endl;
	}
}

void Scheduler::removeProcess(const Process & process) {
	rr.remove(process);
}
