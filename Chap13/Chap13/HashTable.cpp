// �ؽ� ���̺� ���� -- 'ü�̴�'�� �����ϱ� ���� ���� ����Ʈ Ȱ��
#include "HashTable.h"

// ������ -- ���̺� �ʱ�ȭ
HashTable::HashTable(HashFunction func)
	:hf(func), table() {}

// ���̺� Ű�� �� ����
void HashTable::Insert(Key k, Value v) {
	int hash = hf(k);	// �ؽ� ��
	
	// �ߺ��� Ű ��
	if (Search(k) != NULL) {
		std::cout << "Ű �� �ߺ�\n";
		return;
	}
	
	Slot data = { k,v };
	table[hash].LInsert(data);
}

// ���̺� ������ ����
Value HashTable::Delete(Key k) {
	int hash = hf(k);	// �ؽ� ��
	Slot data;			// Ž���� ����

	// ���� ���� Ž��
	if (table[hash].LFirst(&data)) {
		if (data.key == k) {
			data = table[hash].LRemove();
			return data.value;
		}
		while (table[hash].LNext(&data))
			if (data.key == k) {
				data = table[hash].LRemove();
				return data.value;
			}
	}

	return NULL;
}

// ���̺� ������ �˻�
Value HashTable::Search(Key k) {
	int hash = hf(k);	// �ؽ� ��
	Slot data;			// Ž���� ����

	// ���� Ž��
	if (table[hash].LFirst(&data)) {
		if (data.key == k)
			return data.value;

		while (table[hash].LNext(&data))
			if (data.key == k)
				return data.value;

	}

	// ������ ������ NULL ����
	return NULL;
}