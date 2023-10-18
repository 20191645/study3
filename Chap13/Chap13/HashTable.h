// �ؽ� ���̺� ���� -- 'ü�̴�'�� �����ϱ� ���� ���� ����Ʈ Ȱ��
// "LinkedList1.h, cpp"�� �Բ� ������ -- LData�� Slot ������ ����
#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "Slot.h"
#include "LinkedList1.h"

const int MAX = 100;
typedef int (*HashFunction)(Key k);

class HashTable {
private:
	LinkedList table[MAX];	// ������ �迭
	HashFunction hf;	// �ؽ� �Լ�

public:
	HashTable(HashFunction func);
	void Insert(Key k, Value v);
	Value Delete(Key k);
	Value Search(Key k);
};

#endif