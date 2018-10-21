#pragma once
#include <string>
class Process
{
public:
	Process(const std::string& inName);
	virtual ~Process();
	void doSomeTask();
	bool operator == (const Process& rhs);

private:
	std::string mName;
};



