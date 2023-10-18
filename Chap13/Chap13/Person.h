// �ؽ� ���̺� ����� ���� Person Ŭ���� ����
#ifndef PERSON_H_
#define PERSON_H_

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

const int LEN = 50;

class Person {
private:
	int ssn;		// �ֹε�Ϲ�ȣ
	char name[LEN];	// �̸�
	char addr[LEN];	// �ּ�

public:
	Person(int ssn, const char* name, const char* addr)
		:ssn(ssn) {
		strncpy(this->name, name, LEN);
		strncpy(this->addr, addr, LEN);
	}

	int GetSSN() const { return ssn; }

	void ShowInfo() const {
		std::cout << "�ֹε�Ϲ�ȣ: " << ssn << std::endl;
		std::cout <<"�̸�: " << name << std::endl;
		std::cout << "�ּ�: " << addr << std::endl << std::endl;
	}
};

#endif