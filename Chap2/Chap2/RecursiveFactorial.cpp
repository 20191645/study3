// ��͸� �̿��Ͽ� ���丮�� ����
#include <iostream>

long factorial(long n);

int main() {
	using std::cin;
	using std::cout;
	using std::endl;

	long n;
	cout << "���ϰ� ���� ���丮���� ������ �Է��Ͻʽÿ�: ";
	cin >> n;
	cout << n << "!: " << factorial(n) << endl;

	return 0;
}

long factorial(long n) {
	if (n == 0 || n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}