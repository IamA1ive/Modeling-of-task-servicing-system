#pragma once
#include <iostream>
using namespace std;

class TQueue {
	int* arr;
	int head, tail, counter, size;
public:
	TQueue(int _size);
	TQueue(const TQueue& Q);
	~TQueue();
	bool Empty();
	bool Full();
	int Get();
	void Put(int k);
};
