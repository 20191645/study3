// 재귀를 이용하여 팩토리얼 구현
#include <iostream>

long factorial(long n);

int main() {
	using std::cin;
	using std::cout;
	using std::endl;

	long n;
	cout << "구하고 싶은 팩토리얼의 정수를 입력하십시오: ";
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