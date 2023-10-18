// NameCard Ŭ���� ����
#define _CRT_SECURE_NO_WARNINGS
#include "NameCard.h"
#include <iostream>

// NameCard ������ - �ʱ�ȭ
NameCard::NameCard(const char* name, const char* phone) {
	std::strncpy(this->name, name, 30);
	std::strncpy(this->phone, phone, 30);
}

// NameCard ���� ���� ���
void NameCard::ShowNameCardInfo() const {
	std::cout << "�̸�: " << name << std::endl;
	std::cout << "��ȣ: " << phone << std::endl;
}

// �̸��� ������ 0, �ٸ��� 0�� �ƴ� �� ��ȯ
int NameCard::NameCompare(const char* name) const {
	return std::strcmp(this->name, name);
}

// ��ȭ��ȣ ���� ����
void NameCard::ChangePhoneNum(const char* phone) {
	std::strncpy(this->phone, phone, 30);
}

// ��ȭ������ ���
void NameCard::ShowPhone() const {
	std::cout << "��ȣ: " << phone << std::endl;
}