#include "pch.h"
#include "Process.h"
#include <iostream>
#include <string>



Process::Process(const std::string & inName) : mName(inName){
}

Process::~Process(){
}

void Process::doSomeTask(){
	std::cout << "doSomeTask() on " << mName << std::endl;
}

bool Process::operator==(const Process & rhs){
	return mName == rhs.mName;
}
