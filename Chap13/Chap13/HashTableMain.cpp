// �ؽ� ���̺� Ȯ�� -- 'ü�̴�'�� �����ϱ� ���� ���� ����Ʈ Ȱ��
#include "HashTable.h"
#include <iostream>

// �ؽ� �Լ�
int HashFunc(int k) {
	return k % 100;
}

int main() {
	using std::cout;
	using std::endl;

	// �ؽ� ���̺� ���� �� �ʱ�ȭ
	HashTable ht(&HashFunc);
	Person* np;

	// ���̺� ������ ����
	np = new Person(900254, "Lee", "Seoul");
	ht.Insert(np->GetSSN(), np);
	np = new Person(900139, "KIM", "Jeju");
	ht.Insert(np->GetSSN(), np);
	np = new Person(900827, "HAN", "Kangwon");
	ht.Insert(np->GetSSN(), np);

	// �ؽ� �� ��ġ�� ��ü ����
	np = new Person(900927, "Jung", "Busan");
	ht.Insert(np->GetSSN(), np);

	// ���̺� ������ Ž��
	np = ht.Search(900254);
	if (np != NULL)
		np->ShowInfo();
	np = ht.Search(900139);
	if (np != NULL)
		np->ShowInfo();
	np = ht.Search(900827);
	if (np != NULL)
		np->ShowInfo();
	np = ht.Search(900927);
	if (np != NULL)
		np->ShowInfo();

	// ���̺� ������ ����
	np = ht.Delete(900254);
	if (np != NULL)
		delete np;
	np = ht.Delete(900139);
	if (np != NULL)
		delete np;
	np = ht.Delete(900827);
	if (np != NULL)
		delete np;
	np = ht.Delete(900927);
	if (np != NULL)
		delete np;


	return 0;
}