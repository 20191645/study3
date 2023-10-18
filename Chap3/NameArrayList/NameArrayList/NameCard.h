// NameCard 클래스 구현
#ifndef NAMECARD_H_
#define NAMECARD_H_

const int NAMELEN = 30;
const int PHONELEN = 30;
class NameCard {
private:
	char name[NAMELEN];
	char phone[PHONELEN];

public:
	NameCard(const char* name="무명", const char* phone="010-1234-5678");
	~NameCard() {}

	void ShowNameCardInfo() const;
	int NameCompare(const char* name) const;
	void ChangePhoneNum(const char* phone);
	void ShowPhone() const;
};

#endif