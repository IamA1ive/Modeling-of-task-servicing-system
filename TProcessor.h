#pragma once
#include <iostream>

class TProcessor {
	double ProcRate;
	int TaskID;
public:
	TProcessor(double _ProcRate);
	~TProcessor();
	bool Busy();
	void RunNewTask(int _TaskID);
	bool Done();
};
