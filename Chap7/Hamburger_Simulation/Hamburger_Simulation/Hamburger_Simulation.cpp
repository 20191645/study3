/*
	�ùķ��̼� ����:
	- ���ɽð��� 1�ð��̰� ���� 15�ʿ� 1�� �ֹ��Ѵ�
	- �� ���� ���� �ϳ��� ���Ÿ� �ֹ��Ѵ�
	- ��� ���� �������� �޴��� �����Ѵ�
	- �ܹ��Ÿ� ����� ����� 1��
	- �ֹ��� �޴��� ���� ���� ���� ���ǿ��� ���� ���
	- ġ����� 12��, �Ұ����� 15��, ������� 24��
	- ���� ������: const int arrLen ("HamArrayQueue.h"�� ���ǵ� ��������)

	- ArrayQueue�� �̿��ϱ� ���� "HamArrayQueue.h, cpp" ����
	- ORDER_INTERVAL, RUNCH_TIME, arrLen.. �� const int �������� �����ϸ� ����� ������ ��ģ��
*/
#include "ArrayQueue.h"
#include <iostream>
#include <ctime>

int main() {
	using namespace std;
	
	srand(time(0));
	
	ArrayQueue queue;	// ���� -- data ��: ���� ���� ������ �ð�
	const int ORDER_INTERVAL = 15;	// �� �ֹ� ����
	const int LUNCH_TIME = 60 * 60;	// ���ɽð�(�� ����)
	const int CHEESE = 12;	// ġ����� �丮 �ð�
	const int BULGOGI = 15;	// �Ұ�����...
	const int DOUBL = 24;	// �������...

	int menu;	// 'ġ�����:0, �Ұ�����:1, �������:2' �� ����
	int cheese = 0;		// ġ����� �ֹ� Ƚ��
	int bulgogi = 0;	// �Ұ�����...
	int doubl = 0;		// �������...
	int customer = 0;	// ������ ������ ���ư� �� ��

	// �ùķ��̼�
	for (int i = 0; i < LUNCH_TIME; i++) {
		// �� �ֹ�
		if (i % ORDER_INTERVAL == 0) {
			
			// ������ �����ִ� ���
			if (queue.isFull()) {
				customer++;
				continue;
			}

			menu = rand() % 3;
			switch (menu) {
			case 0:
				queue.Enqueue(i + CHEESE);
				cheese++;
				break;
			case 1:
				queue.Enqueue(i + BULGOGI);
				bulgogi++;
				break;
			case 2:
				queue.Enqueue(i + DOUBL);
				doubl++;
				break;
			}
		}

		if (queue.Peek() == i)
			queue.Dequeue();
	}

	std::cout << "Simulation Report!\n";
	std::cout << "- Cheese burger: " << cheese << std::endl;
	std::cout << "- Bulgogi burger: " << bulgogi << std::endl;
	std::cout << "- Double burger: " << doubl << std::endl;
	std::cout << "- No Waiting Customer: " << customer << std::endl;
	std::cout << "- Waiting room size: " << arrLen << std::endl;

	return 0;
}