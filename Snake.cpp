#include "Snake.h"
#include "Tools.h"

#include <conio.h>
#include <iostream>

// 初始化蛇
void Snake::InitSnake()
{
	for (Point& point : body)
	{
		point.PrintCircular();
	}
}

// 蛇增长
void Snake::Move()
{
	switch (direction)
	{
	case Direction::UP:
		body.emplace_back(Point(body.back().GetX(), body.back().GetY() - 1));
		break;
	case Direction::DOWN:
		body.emplace_back(Point(body.back().GetX(), body.back().GetY() + 1));
		break;
	case Direction::LEFT:
		body.emplace_back(Point(body.back().GetX() - 1, body.back().GetY()));
		break;
	case Direction::RIGHT:
		body.emplace_back(Point(body.back().GetX() + 1, body.back().GetY()));
		break;
	default:
		break;
	}

	SetColor(Color_ForeGround_Highlight_Yellow);
	body.back().PrintCircular();
}


// 蛇正常移动，头增长，尾缩短
void Snake::NormalMove()
{
	Move();
	body.front().Clear();
	body.pop_front();
}

// 改变方向
bool Snake::ChangeDirection()
{
	char ch;
	// _kbhit 非阻塞的响应键盘输入事件 , keyboard hit
	if (_kbhit())
	{
		// _getch() 这个函数在你按上下左右的时候会先返回-32，再用_getch（）接收一次会返回72/80
		ch = _getch();
		switch (ch)
		{
		case -32:
			ch = _getch();
			switch (ch)
			{
			case 72:
				// 若方向与当前运动方向相反，无效
				if (direction != Direction::DOWN) direction = Direction::UP;
				break;
			case 80:
				// 若方向与当前运动方向相反，无效
				if (direction != Direction::UP) direction = Direction::DOWN;
				break;
			case 75:
				// 若方向与当前运动方向相反，无效
				if (direction != Direction::RIGHT) direction = Direction::LEFT;
				break;
			case 77:
				// 若方向与当前运动方向相反，无效
				if (direction != Direction::LEFT) direction = Direction::RIGHT;
				break;
			default:
				break;
			}
			return true;
		case 27:
			return false;
		default:
			return true;
		}
	}
	return true;
}

bool Snake::GetFood(const Food& food)
{
	if (body.back().GetX() == food.x && body.back().GetY() == food.y) return true;
	else return false;
}

bool Snake::GetBigFood(Food& food)
{
	if (body.back().GetX() == food.bigX && body.back().GetY() == food.bigY)
	{
		food.isExistedBigFood = false;
		food.bigX = 0, food.bigY = 0;
		SetCursorPosition(1, 0);
		std::cout << "                                                            ";
		return true;
	}
	return false;
}

// 超出边界
bool Snake::OverEdge()
{
	return body.back().GetX() < 30 && body.back().GetX() > 1 && body.back().GetY() < 30 && body.back().GetY() > 1;
}

// 撞到自身
bool Snake::HitItself()
{
	std::deque<Point>::size_type cnt = 1;
	// 获得头坐标
	Point* head = new Point(body.back().GetX(), body.back().GetY());
	for (Point& point : body)
	{
		if (!(point == *head)) cnt++;
		else break;
	}
	delete head;
	if (cnt == body.size()) return true;
	else return false;
}