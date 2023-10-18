// �迭 ��� ��(Heap) ���� -- �켱������ �������� �� �κп� ��ġ
// ��: ���� ���� Ʈ��
#ifndef HEAP_H_
#define HEAP_H_

const int arrLen = 100;	// �� �迭 ũ��
typedef int HData;		// �� ���� ������ -- int��

// ���� �������� ���� �켱������ ����
typedef int (*PriorityComp)(HData d1, HData d2);

// Heap Ŭ����
class Heap {
private:
	PriorityComp comp;	// �켱���� �񱳿� �Լ� ������
	HData arr[arrLen];
	int num;	// ���� ���� ����ִ� ���� ����

public:
	Heap(PriorityComp pc) :num(0), comp(pc) {}
	~Heap() {}

	bool isEmpty() const { return num == 0; }
	void Insert(HData data);
	int GetChildIndex(int index) const;
	HData Delete();
};

#endif