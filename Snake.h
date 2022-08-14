#pragma once

#include "Point.h"
#include "Food.h"

#include <deque>

class Food;

class Snake
{
public:
	enum Direction { UP, DOWN, LEFT, RIGHT };

private:
	std::deque<Point> body;
	Direction direction;
	friend class Food;

public:
	Snake()
	{
		body.emplace_back(14, 8);
		body.emplace_back(15, 8);
		body.emplace_back(16, 8);
		direction = Direction::DOWN;
	}
	void InitSnake();
	void Move();
	void NormalMove();
	bool OverEdge();
	bool HitItself();
	bool ChangeDirection();
	bool GetFood(const Food&);
	bool GetBigFood(Food&);
};