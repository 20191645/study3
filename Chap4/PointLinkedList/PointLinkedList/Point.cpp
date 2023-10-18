// Point Ŭ���� ����
#include "Point.h"
#include <iostream>

// x, y��ǥ �� ����
void Point::SetPointPos(int xpos, int ypos) {
	x = xpos;
	y = ypos;
}

// Point ���� ���
void Point::ShowPointPos() const {
	std::cout << '[' << x << ", " << y << ']' << std::endl;
}

// �ٸ� Point ��ü�� x, y�� ��
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

// x��ǥ �� ��ȯ
int Point::GetXPos() const {
	return x;
}

// y��ǥ �� ��ȯ
int Point::GetYPos() const {
	return y;
}