/*
	Employee형 원형 연결 리스트(CircularLinkedList) 확인 -- tail 데이터 추가 방식
	- 리스트의 데이터: 직원 정보를 담을 수 있는 Employee 구조체의 주소 값
	- 직원은 순서대로 돌아가면서 당직을 선다(당직 순서 = 리스트 등록 순서)
	- Emp(list, name, days): 매개변수로 전달된 이름의 직원이 당직을 선 후, 
			매개변수로 전달된 숫자만큼 날이 지나서 당직을 서게 되는 직원의 정보 반환
*/
#include "EmployeeCircularList.h"
#include <iostream>

Employee* Emp(CircularList& list, const char* name, int days) {
	Employee* temp;
	int i;

	// name에 해당하는 Employee 찾기
	if (list.LFirst(&temp)) {
		if (strcmp(name, temp->name)) {
			for (i = 1; i < list.LCount(); i++) {
				list.LNext(&temp);
				if (!strcmp(name, temp->name))
					break;
			}
		}
	}

	// days 흐른 후 Employee 찾기
	for (i = 0; i < days; i++) {
		list.LNext(&temp);
	}

	return temp;
}

int main() {
	using std::cout;
	using std::endl;

	CircularList list;
	Employee* data;

	Employee emp1 = { 123, "홍길동" };
	Employee emp2 = { 456, "김철수" };
	Employee emp3 = { 789, "신짱구" };
	Employee emp4 = { 210, "박맹구" };

	// 리스트 데이터 삽입 -- 리스트 순서: 등록 순서
	list.LInsertTail(&emp1);
	list.LInsertTail(&emp2);
	list.LInsertTail(&emp3);
	list.LInsertTail(&emp4);

	// 리스트 정보 출력
	cout << "현재 리스트의 데이터 수: " << list.LCount() << endl;
	if (list.LFirst(&data)) {
		data->ShowEmp();
		for (int i = 1; i < list.LCount(); i++) {
			if (list.LNext(&data))
				data->ShowEmp();
		}
	}
	std::cout << std::endl;

	// 당직자 확인
	cout << "처음 당직자:\n";
	emp2.ShowEmp();
	data = Emp(list, "김철수", 7);
	cout << "7일 후 당직자:\n";
	data->ShowEmp();
	cout << endl;

	// 리스트 정보 삭제
	cout << "신짱구 삭제!\n";
	if (list.LFirst(&data)) {
		if (!strcmp(data->name, "신짱구"))
			list.LRemove();
		for (int i = 1; i < list.LCount(); i++) {
			if (list.LNext(&data))
				if (!strcmp(data->name, "신짱구"))
					list.LRemove();
		}
	}

	// 리스트 정보 출력
	cout << "현재 리스트의 데이터 수: " << list.LCount() << endl;
	if (list.LFirst(&data)) {
		data->ShowEmp();
		for (int i = 1; i < list.LCount(); i++) {
			if (list.LNext(&data))
				data->ShowEmp();
		}
	}
	std::cout << std::endl;

	return 0;
}