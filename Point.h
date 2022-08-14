#pragma once

class Point
{
private:
	int x, y;

public:
	Point() {}
	Point(const int x, const int y) : x(x), y(y) {}

	void Print();
	void PrintCircular();
	void Clear();
	void ChangePosition(const int x, const int y);
	
	bool operator== (const Point& point) { return (point.x == this->x) && (point.y == this->y); }
	int GetX() { return this->x; }
	int GetY() { return this->y; }
};