// �ؽ� ���̺��� ���� ����ü ���� -- �浹�� �ذ�å���� 'ü�̴�' ����
#ifndef SLOT_H_
#define SLOT_H_

#include "Person.h"

typedef int Key;		// Ű: �ֹε�Ϲ�ȣ
typedef Person* Value;	// ��: Person ��ü

// ���� -- ������ ���̺��� Ÿ���� ����ϴ� ����ü
struct Slot {
	Key key;
	Value value;
};

#endif