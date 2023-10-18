// 순차 리스트(ArrayList) 구현
// LData => NameCard
#include "NameArrayList.h"

// 리스트 생성자 - 초기화
ArrayList::ArrayList() :index(0), num(0) {}

// 리스트 데이터 삽입
void ArrayList::insert(LData data) {
	if (num < arrLen)
		arr[num++] = data;
}

// 첫 번째 리스트 데이터 반환
bool ArrayList::first(LData* pdata) {
	if (num == 0)
		return false;
	else {
		index = 0;
		*pdata = arr[0];
		return true;
	}
}

// 리스트가 현재 가리키는 인덱스 다음 인덱스의 데이터 반환
bool ArrayList::next(LData* pdata) {
	if (num - 1 <= index)
		return false;
	else {
		index++;
		*pdata = arr[index];
		return true;
	}
}

// 현재 가리키는 인덱스 데이터 삭제
LData ArrayList::remove() {
	LData temp = arr[index];
	for (int i = index; i < num; i++)
		arr[i] = arr[i + 1];
	num--;
	index--;
	return temp;
}

// 리스트 데이터의 수 반환
int ArrayList::count() const {
	return num;
}
