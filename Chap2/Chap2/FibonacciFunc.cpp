// ��͸� �̿��Ͽ� �Ǻ���ġ ���� ����
#include <iostream>

long fibonacci(long n);

int main() {
	using std::cin;
	using std::cout;
	using std::endl;

	long n;
	cout << "�Ǻ���ġ ������ ���ϰ� ���� ������ �Է��Ͻÿ�: ";
	cin >> n;
	cout << "Fibonacci(" << n << "): " << fibonacci(n) << endl;

	return 0;
}

long fibonacci(long n) {
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}