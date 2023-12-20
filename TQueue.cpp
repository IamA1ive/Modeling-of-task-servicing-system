#include "TQueue.h"

TQueue::TQueue(int _size) {
	head = 0;
	tail = 0;
	counter = 0;
	size = _size;
	arr = new int[size];
}
TQueue::~TQueue() {
	delete[] arr;
}
TQueue::TQueue(const TQueue& Q) {
	head = Q.head;
	tail = Q.tail;
	counter = Q.counter;
	size = Q.size;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = Q.arr[i];
	}
}
bool TQueue::Empty() {
	return (counter == 0);
}
bool TQueue::Full() {
	return (counter == size);
}
int TQueue::Get() {
	int res = 0;
	if (!Empty()) {
		res = arr[head++];
		if (head == size) head = 0;
		counter--;
	}
	else cout << "ќшибка: очередь пуста!" << endl;
	return res;
}
void TQueue::Put(int k) {
	if (!Full()) {
		if (tail == size) tail = 0;
		arr[tail++] = k;
		counter++;
	}
	else cout << "ќчередь переполнена. Ёлемент не может быть добавлен." << endl;
}




