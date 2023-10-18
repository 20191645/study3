// ���� ����Ʈ(ArrayList) ����
#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

const int arrLen = 100;

// ArrayList�� ���� ������ Ÿ�Կ� ���� typedef ������ �����Ѵ�
typedef int LData;

class ArrayList {
private:
	LData arr[arrLen];
	int index;	// ���� ����Ʈ�� ����Ű�� �ε���
	int num;	// ���� ����Ʈ�� ��� ������ ����

public:
	ArrayList();
	~ArrayList() {}

	void insert(LData data);
	bool first(LData* pdata);
	bool next(LData* pdata);
	LData remove();
	int count() const;
};

#endif