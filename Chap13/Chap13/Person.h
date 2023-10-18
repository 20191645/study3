// 해쉬 테이블에 저장될 값인 Person 클래스 정의
#ifndef PERSON_H_
#define PERSON_H_

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

const int LEN = 50;

class Person {
private:
	int ssn;		// 주민등록번호
	char name[LEN];	// 이름
	char addr[LEN];	// 주소

public:
	Person(int ssn, const char* name, const char* addr)
		:ssn(ssn) {
		strncpy(this->name, name, LEN);
		strncpy(this->addr, addr, LEN);
	}

	int GetSSN() const { return ssn; }

	void ShowInfo() const {
		std::cout << "주민등록번호: " << ssn << std::endl;
		std::cout <<"이름: " << name << std::endl;
		std::cout << "주소: " << addr << std::endl << std::endl;
	}
};

#endif