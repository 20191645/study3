// ��(Heap) ��� �켱���� ť(Priority Queue) Ȯ��
#include "PriorityQueue.h"
#include <iostream>
#include <string>
using std::string;

// �켱���� �񱳿� �Լ�
int PriorityFunction(string c1, string c2) {
	// ù ��° �Ű������� �켱������ ������ 0���� ū ��
	// �� ��° �Ű������� �켱������ ������ 0���� ���� ��
	// �켱������ �����ϸ� 0
	return c2.size() - c1.size();
}

int main() {
	using std::cout;
	using std::endl;
	
	PQueue pqueue(PriorityFunction);

	pqueue.Enqueue("abcd");
	pqueue.Enqueue("ba");
	pqueue.Enqueue("aca");
	pqueue.Enqueue("b");
	pqueue.Enqueue("ab");

	while (!pqueue.isEmpty())
		cout << pqueue.Dequeue() << endl;

	return 0;
}