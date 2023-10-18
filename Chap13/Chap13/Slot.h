// 해쉬 테이블의 슬롯 구조체 정의 -- 충돌의 해결책으로 '체이닝' 구현
#ifndef SLOT_H_
#define SLOT_H_

#include "Person.h"

typedef int Key;		// 키: 주민등록번호
typedef Person* Value;	// 값: Person 객체

// 슬롯 -- 실제로 테이블의 타입을 담당하는 구조체
struct Slot {
	Key key;
	Value value;
};

#endif