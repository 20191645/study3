// Point 클래스 연결 리스트 확인 -- tail 데이터 추가 방식
#include <iostream>
#include "PointLinkedList.h"

int SortOrder(Point* p1, Point* p2) {
	// x좌표의 값을 기준으로 오름차순 정렬(0, 1, 2..)
	// x좌표가 같으면 y좌표의 값을 기준으로 오름차순 정렬
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

	// 리스트 정렬 기준 설정
	list.SetSortRule(SortOrder);
	
	// Point 포인터에 값 대입 -> 리스트 추가
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

	// 저장된 Point 데이터 출력
	cout << "총 저장된 데이터의 수: " << list.LCount() << endl;
	if (list.LFirst(&ppos)) {
		ppos->ShowPointPos();
		while (list.LNext(&ppos))
			ppos->ShowPointPos();
	}
	cout << endl;

	// x좌표가 2인 데이터 삭제
	cout << "x좌표가 2인 데이터 삭제!\n";
	Point pos(2, 0);
	if (list.LFirst(&ppos)) {
		if (ppos->PointComp(pos) == 1) {
			// LData가 Point*, 즉 포인터 형식이므로 해제해줘야 한다
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

	// 삭제 후 다시 출력
	cout << "총 저장된 데이터의 수: " << list.LCount() << endl;
	if (list.LFirst(&ppos)) {
		ppos->ShowPointPos();
		while (list.LNext(&ppos))
			ppos->ShowPointPos();
	}

	return 0;
}