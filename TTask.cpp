#include "TTask.h"

TTask::TTask(double _intensity) {
	intensity = _intensity;
}
TTask::~TTask() = default;
bool TTask::NewTask() {
	double chance = (std::rand() % 100) / 100.0;
	return (chance <= intensity);
}