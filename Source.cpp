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
	cout << "������� ������������� ������ �����: " << endl;
	cin >> intensity; 
	cout << "������� ������������������ ����������: " << endl;
	cin >> ProcRate;
	cout << "������� ���������� ������: " << endl;
	cin >> tact;
	cout << "������� ������ �������: " << endl;
	cin >> q;
	TTask T(intensity);
	TQueue Q(q);
	TProcessor P(ProcRate);
	TSystem S(tact);
	S.Work(P, T, Q);

	return 0;
}