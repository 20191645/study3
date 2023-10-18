// NameCard 클래스 구현
#define _CRT_SECURE_NO_WARNINGS
#include "NameCard.h"
#include <iostream>

// NameCard 생성자 - 초기화
NameCard::NameCard(const char* name, const char* phone) {
	std::strncpy(this->name, name, 30);
	std::strncpy(this->phone, phone, 30);
}

// NameCard 변수 정보 출력
void NameCard::ShowNameCardInfo() const {
	std::cout << "이름: " << name << std::endl;
	std::cout << "번호: " << phone << std::endl;
}

// 이름이 같으면 0, 다르면 0이 아닌 값 반환
int NameCard::NameCompare(const char* name) const {
	return std::strcmp(this->name, name);
}

// 전화번호 정보 변경
void NameCard::ChangePhoneNum(const char* phone) {
	std::strncpy(this->phone, phone, 30);
}

// 전화정보만 출력
void NameCard::ShowPhone() const {
	std::cout << "번호: " << phone << std::endl;
}