// �ϳ��� Ÿ�� ����
#include <iostream>

void hanoi_move(int num, char from, char by, char to);

int main() {
	hanoi_move(3, 'A', 'B', 'C');

	std::cout << std::endl;

	hanoi_move(4, 'A', 'B', 'C');
	return 0;
}

void hanoi_move(int num, char from, char by, char to) {
	using std::cout;

	if (num == 1)
		cout << "����1: " << from << "���� " << to << "�� �̵�\n";
	else {
		hanoi_move(num - 1, from, to, by);
		cout << "����" << num << ": " << from << "���� " << to << "�� �̵�\n";
		hanoi_move(num - 1, by, from, to);
	}
}