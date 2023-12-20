#include "TSystem.h"
TSystem::TSystem(int _tact) {
	tact = _tact;
	waiting = 0;
	incoming = 0;
	accepted = 0;
	completed = 0;
}
TSystem::~TSystem() = default;
void TSystem::Work(TProcessor P, TTask T, TQueue Q) {
	srand(tact);
	int k = 0;
	for (int i = 1; i <= tact; i++) {
		cout << endl << "���� " << i << endl;
		if (T.NewTask()) {
			cout << "��������� ������ #" << i << endl;
			incoming++;
			if (!Q.Full()) {
				cout << "������ #" << i << " ������� � ������� �� ����������" << endl << endl;
				accepted++;
				Q.Put(i);
			}
			else {
				cout << "������� �����������. ����� � ������������." << endl << endl;
			}
		}
		else {
			cout << "�� ������� ����� ������ �� ���������." << endl << endl;
		}
		
		
		if (!P.Busy()) {
			if (!Q.Empty()) {
				k = Q.Get();
				P.RunNewTask(k);
				cout << "������ ���������� ������ #" << k << endl;
			}
			else {
				cout << "������ �����������." << endl;
				waiting++;
			}
		}
		else {
			cout << "��� ���������� ������ #" << k << " ..." << endl << endl;
		}
		
		
		if (P.Done()) {
			completed++;
		}
	}
	cout << endl << endl;
	cout << "������: " << tact << endl;
	cout << "������������� �����: " << incoming << endl;
	cout << "������� ����� � ������� �� ����������: " << accepted << endl;
	cout << "��������� �����: " << completed << endl;
	cout << "������� � ������������: " << incoming - accepted << " (" << ((double)incoming - (double)accepted) / (double)incoming * 100 << "%)" << endl;
	cout << "������ �������: " << waiting << " (" << ((double)waiting / (double)tact) * 100.0 << "%)" << endl;
	cout << "������� ���������� ������ ���������� �����: " << (double)(tact - waiting) / (double)completed << endl;

}