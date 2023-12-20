#include "TProcessor.h"

TProcessor::TProcessor(double _ProcRate) {
	ProcRate = _ProcRate;
	TaskID = 0;
}
TProcessor::~TProcessor() = default;
bool TProcessor::Busy() {
	return (TaskID > 0);
}
void TProcessor::RunNewTask(int _TaskID) {
	TaskID = _TaskID;
}
bool TProcessor::Done() {
	double chance = (std::rand() % 100) / 100.0;
	if (chance <= ProcRate) {
		std::cout << "Задача " << TaskID << " выполнена." << std::endl << std::endl;
		TaskID = 0;
		return true;
	}
	else return false;
}