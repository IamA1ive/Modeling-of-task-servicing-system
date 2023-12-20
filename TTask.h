#pragma once
#include <cstdlib>
class TTask {
	double intensity;
public:
	TTask(double _intensity);
	~TTask();
	bool NewTask();
};