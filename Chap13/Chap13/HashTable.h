// 해쉬 테이블 구현 -- '체이닝'을 구현하기 위해 연결 리스트 활용
// "LinkedList1.h, cpp"와 함께 컴파일 -- LData를 Slot 형으로 수정
#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "Slot.h"
#include "LinkedList1.h"

const int MAX = 100;
typedef int (*HashFunction)(Key k);

class HashTable {
private:
	LinkedList table[MAX];	// 슬롯의 배열
	HashFunction hf;	// 해쉬 함수

public:
	HashTable(HashFunction func);
	void Insert(Key k, Value v);
	Value Delete(Key k);
	Value Search(Key k);
};

#endif