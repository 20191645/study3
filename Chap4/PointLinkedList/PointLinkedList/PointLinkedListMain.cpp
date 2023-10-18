// Point Ŭ���� ���� ����Ʈ Ȯ�� -- tail ������ �߰� ���
#include <iostream>
#include "PointLinkedList.h"

int SortOrder(Point* p1, Point* p2) {
	// x��ǥ�� ���� �������� �������� ����(0, 1, 2..)
	// x��ǥ�� ������ y��ǥ�� ���� �������� �������� ����
	if (p1->GetXPos() < p2->GetXPos())
		return 0;
	else if (p1->GetXPos() > p2->GetXPos())
		return 1;
	else if (p1->GetYPos() < p2->GetYPos())
		return 0;
	else
		return 1;
}

int main() {
	using std::cout;
	using std::endl;

	LinkedList list;
	Point* ppos = new Point;

	// ����Ʈ ���� ���� ����
	list.SetSortRule(SortOrder);
	
	// Point �����Ϳ� �� ���� -> ����Ʈ �߰�
	ppos->SetPointPos(4, 5);
	list.LInsert(ppos);

	ppos = new Point;
	ppos->SetPointPos(2, 2);
	list.LInsert(ppos);

	ppos = new Point;
	ppos->SetPointPos(5, 5);
	list.LInsert(ppos);

	ppos = new Point;
	ppos->SetPointPos(5, 2);
	list.LInsert(ppos);

	// ����� Point ������ ���
	cout << "�� ����� �������� ��: " << list.LCount() << endl;
	if (list.LFirst(&ppos)) {
		ppos->ShowPointPos();
		while (list.LNext(&ppos))
			ppos->ShowPointPos();
	}
	cout << endl;

	// x��ǥ�� 2�� ������ ����
	cout << "x��ǥ�� 2�� ������ ����!\n";
	Point pos(2, 0);
	if (list.LFirst(&ppos)) {
		if (ppos->PointComp(pos) == 1) {
			// LData�� Point*, �� ������ �����̹Ƿ� ��������� �Ѵ�
			ppos = list.LRemove();
			delete ppos;
		}

		while (list.LNext(&ppos)) {
			if (ppos->PointComp(pos) == 1) {
				ppos = list.LRemove();
				delete ppos;
			}
		}
	}

	// ���� �� �ٽ� ���
	cout << "�� ����� �������� ��: " << list.LCount() << endl;
	if (list.LFirst(&ppos)) {
		ppos->ShowPointPos();
		while (list.LNext(&ppos))
			ppos->ShowPointPos();
	}

	return 0;
}