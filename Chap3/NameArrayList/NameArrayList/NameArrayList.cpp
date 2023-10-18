// ���� ����Ʈ(ArrayList) ����
// LData => NameCard
#include "NameArrayList.h"

// ����Ʈ ������ - �ʱ�ȭ
ArrayList::ArrayList() :index(0), num(0) {}

// ����Ʈ ������ ����
void ArrayList::insert(LData data) {
	if (num < arrLen)
		arr[num++] = data;
}

// ù ��° ����Ʈ ������ ��ȯ
bool ArrayList::first(LData* pdata) {
	if (num == 0)
		return false;
	else {
		index = 0;
		*pdata = arr[0];
		return true;
	}
}

// ����Ʈ�� ���� ����Ű�� �ε��� ���� �ε����� ������ ��ȯ
bool ArrayList::next(LData* pdata) {
	if (num - 1 <= index)
		return false;
	else {
		index++;
		*pdata = arr[index];
		return true;
	}
}

// ���� ����Ű�� �ε��� ������ ����
LData ArrayList::remove() {
	LData temp = arr[index];
	for (int i = index; i < num; i++)
		arr[i] = arr[i + 1];
	num--;
	index--;
	return temp;
}

// ����Ʈ �������� �� ��ȯ
int ArrayList::count() const {
	return num;
}
