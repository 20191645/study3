// Point 클래스 구현
#include "Point.h"
#include <iostream>

// x, y좌표 값 대입
void Point::SetPointPos(int xpos, int ypos) {
	x = xpos;
	y = ypos;
}

// Point 정보 출력
void Point::ShowPointPos() const {
	std::cout << '[' << x << ", " << y << ']' << std::endl;
}

// 다른 Point 객체와 x, y값 비교
int Point::PointComp(Point& pos) const {
	if (x == pos.x && y == pos.y)
		return 0;
	else if (x == pos.x)
		return 1;
	else if (y == pos.y)
		return 2;
	else
		return -1;
}

// x좌표 값 반환
int Point::GetXPos() const {
	return x;
}

// y좌표 값 반환
int Point::GetYPos() const {
	return y;
}