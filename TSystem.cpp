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
		cout << endl << "ТАКТ " << i << endl;
		if (T.NewTask()) {
			cout << "Поступила задача #" << i << endl;
			incoming++;
			if (!Q.Full()) {
				cout << "Задача #" << i << " принята в очередь на исполнение" << endl << endl;
				accepted++;
				Q.Put(i);
			}
			else {
				cout << "Очередь переполнена. Отказ в обслуживании." << endl << endl;
			}
		}
		else {
			cout << "На текущем такте задачи не поступали." << endl << endl;
		}
		
		
		if (!P.Busy()) {
			if (!Q.Empty()) {
				k = Q.Get();
				P.RunNewTask(k);
				cout << "Начато исполнение задачи #" << k << endl;
			}
			else {
				cout << "Задачи отсутствуют." << endl;
				waiting++;
			}
		}
		else {
			cout << "Идёт исполнение задачи #" << k << " ..." << endl << endl;
		}
		
		
		if (P.Done()) {
			completed++;
		}
	}
	cout << endl << endl;
	cout << "Тактов: " << tact << endl;
	cout << "Сгенерировано задач: " << incoming << endl;
	cout << "Принято задач в очередь на исполнение: " << accepted << endl;
	cout << "Завершено задач: " << completed << endl;
	cout << "Отказов в обслуживании: " << incoming - accepted << " (" << ((double)incoming - (double)accepted) / (double)incoming * 100 << "%)" << endl;
	cout << "Тактов простоя: " << waiting << " (" << ((double)waiting / (double)tact) * 100.0 << "%)" << endl;
	cout << "Среднее количество тактов выполнения задач: " << (double)(tact - waiting) / (double)completed << endl;

}