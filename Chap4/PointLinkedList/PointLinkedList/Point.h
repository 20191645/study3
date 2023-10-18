// Point 클래스 구현
#ifndef POINT_H_
#define POINT_H_

class Point {
private:
	int x;
	int y;

public:
	Point(int xpos = 0, int ypos = 0) :x(xpos), y(ypos) {}
	~Point() {}

	void SetPointPos(int xpos, int ypos);
	void ShowPointPos() const;
	int PointComp(Point& pos) const;
	int GetXPos() const;
	int GetYPos() const;
};

#endif