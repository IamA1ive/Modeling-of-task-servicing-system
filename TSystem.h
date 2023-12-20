#pragma once
#include <iostream>
#include "TProcessor.h"
#include "TTask.h"
#include "TQueue.h"
#include <cstdlib>
using namespace std;

class TSystem {
	int tact, waiting, incoming, accepted, completed;
public:
	TSystem(int _tact);
	~TSystem();
	void Work(TProcessor P, TTask T, TQueue Q);
};

