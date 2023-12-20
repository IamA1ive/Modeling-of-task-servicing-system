#include <iostream>
#include <locale.h>
#include "TQueue.h"
#include "TTask.h"
#include "TSystem.h"
#include "TProcessor.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	double intensity, ProcRate;
	int tact, q;
	cout << "¬ведите интенсивность потока задач: " << endl;
	cin >> intensity; 
	cout << "¬ведите производительность процессора: " << endl;
	cin >> ProcRate;
	cout << "¬ведите количество тактов: " << endl;
	cin >> tact;
	cout << "¬ведите размер очереди: " << endl;
	cin >> q;
	TTask T(intensity);
	TQueue Q(q);
	TProcessor P(ProcRate);
	TSystem S(tact);
	S.Work(P, T, Q);

	return 0;
}