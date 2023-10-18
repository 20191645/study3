/*
	시뮬레이션 예제:
	- 점심시간은 1시간이고 고객은 15초에 1명씩 주문한다
	- 한 명의 고객은 하나의 버거를 주문한다
	- 모든 고객은 무작위로 메뉴를 선택한다
	- 햄버거를 만드는 사람은 1명
	- 주문한 메뉴를 받을 다음 고객은 대기실에서 나와 대기
	- 치즈버거 12초, 불고기버거 15초, 더블버거 24초
	- 대기실 사이즈: const int arrLen ("HamArrayQueue.h"에 정의된 전역변수)

	- ArrayQueue를 이용하기 위해 "HamArrayQueue.h, cpp" 포함
	- ORDER_INTERVAL, RUNCH_TIME, arrLen.. 등 const int 변수값을 수정하면 결과에 영향을 미친다
*/
#include "ArrayQueue.h"
#include <iostream>
#include <ctime>

int main() {
	using namespace std;
	
	srand(time(0));
	
	ArrayQueue queue;	// 대기실 -- data 값: 고객이 대기실 나가는 시간
	const int ORDER_INTERVAL = 15;	// 고객 주문 간격
	const int LUNCH_TIME = 60 * 60;	// 점심시간(초 단위)
	const int CHEESE = 12;	// 치즈버거 요리 시간
	const int BULGOGI = 15;	// 불고기버거...
	const int DOUBL = 24;	// 더블버거...

	int menu;	// '치즈버거:0, 불고기버거:1, 더블버거:2' 로 간주
	int cheese = 0;		// 치즈버거 주문 횟수
	int bulgogi = 0;	// 불고기버거...
	int doubl = 0;		// 더블버거...
	int customer = 0;	// 대기실이 꽉차서 돌아간 고객 수

	// 시뮬레이션
	for (int i = 0; i < LUNCH_TIME; i++) {
		// 고객 주문
		if (i % ORDER_INTERVAL == 0) {
			
			// 대기실이 꽉차있는 경우
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