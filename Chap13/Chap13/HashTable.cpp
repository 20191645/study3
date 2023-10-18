// 해쉬 테이블 구현 -- '체이닝'을 구현하기 위해 연결 리스트 활용
#include "HashTable.h"

// 생성자 -- 테이블 초기화
HashTable::HashTable(HashFunction func)
	:hf(func), table() {}

// 테이블 키와 값 저장
void HashTable::Insert(Key k, Value v) {
	int hash = hf(k);	// 해쉬 값
	
	// 중복된 키 값
	if (Search(k) != NULL) {
		std::cout << "키 값 중복\n";
		return;
	}
	
	Slot data = { k,v };
	table[hash].LInsert(data);
}

// 테이블 데이터 삭제
Value HashTable::Delete(Key k) {
	int hash = hf(k);	// 해쉬 값
	Slot data;			// 탐색용 슬롯

	// 삭제 슬롯 탐색
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

// 테이블 데이터 검색
Value HashTable::Search(Key k) {
	int hash = hf(k);	// 해쉬 값
	Slot data;			// 탐색용 슬롯

	// 슬롯 탐색
	if (table[hash].LFirst(&data)) {
		if (data.key == k)
			return data.value;

		while (table[hash].LNext(&data))
			if (data.key == k)
				return data.value;

	}

	// 데이터 없으면 NULL 리턴
	return NULL;
}