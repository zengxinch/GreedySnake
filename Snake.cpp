#include "Snake.h"
#include "Tools.h"

#include <conio.h>
#include <iostream>

// ��ʼ����
void Snake::InitSnake()
{
	for (Point& point : body)
	{
		point.PrintCircular();
	}
}

// ������
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


// �������ƶ���ͷ������β����
void Snake::NormalMove()
{
	Move();
	body.front().Clear();
	body.pop_front();
}

// �ı䷽��
bool Snake::ChangeDirection()
{
	char ch;
	// _kbhit ����������Ӧ���������¼� , keyboard hit
	if (_kbhit())
	{
		// _getch() ����������㰴�������ҵ�ʱ����ȷ���-32������_getch��������һ�λ᷵��72/80
		ch = _getch();
		switch (ch)
		{
		case -32:
			ch = _getch();
			switch (ch)
			{
			case 72:
				// �������뵱ǰ�˶������෴����Ч
				if (direction != Direction::DOWN) direction = Direction::UP;
				break;
			case 80:
				// �������뵱ǰ�˶������෴����Ч
				if (direction != Direction::UP) direction = Direction::DOWN;
				break;
			case 75:
				// �������뵱ǰ�˶������෴����Ч
				if (direction != Direction::RIGHT) direction = Direction::LEFT;
				break;
			case 77:
				// �������뵱ǰ�˶������෴����Ч
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

// �����߽�
bool Snake::OverEdge()
{
	return body.back().GetX() < 30 && body.back().GetX() > 1 && body.back().GetY() < 30 && body.back().GetY() > 1;
}

// ײ������
bool Snake::HitItself()
{
	std::deque<Point>::size_type cnt = 1;
	// ���ͷ����
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