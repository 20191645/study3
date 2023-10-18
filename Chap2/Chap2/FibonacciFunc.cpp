// 재귀를 이용하여 피보나치 수열 구현
#include <iostream>

long fibonacci(long n);

int main() {
	using std::cin;
	using std::cout;
	using std::endl;

	long n;
	cout << "피보나치 수열을 구하고 싶은 정수를 입력하시오: ";
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