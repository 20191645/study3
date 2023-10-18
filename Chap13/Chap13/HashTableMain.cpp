// 해쉬 테이블 확인 -- '체이닝'을 구현하기 위해 연결 리스트 활용
#include "HashTable.h"
#include <iostream>

// 해쉬 함수
int HashFunc(int k) {
	return k % 100;
}

int main() {
	using std::cout;
	using std::endl;

	// 해쉬 테이블 생성 및 초기화
	HashTable ht(&HashFunc);
	Person* np;

	// 테이블 데이터 저장
	np = new Person(900254, "Lee", "Seoul");
	ht.Insert(np->GetSSN(), np);
	np = new Person(900139, "KIM", "Jeju");
	ht.Insert(np->GetSSN(), np);
	np = new Person(900827, "HAN", "Kangwon");
	ht.Insert(np->GetSSN(), np);

	// 해쉬 값 겹치는 객체 저장
	np = new Person(900927, "Jung", "Busan");
	ht.Insert(np->GetSSN(), np);

	// 테이블 데이터 탐색
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

	// 테이블 데이터 삭제
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