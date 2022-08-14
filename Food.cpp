#include "Food.h"
#include "Tools.h"

#include <cstdlib>
#include <iostream>

void Food::DrawFood(Snake& snake)
{
	// 利用rand函数获得坐标，并将其范围限制在 2-29 （即地图内），
	// 若获得坐标与蛇身重叠，则重新获取
	// 同时，每出现5颗食物出现一颗限时食物

	while (true)
	{
		int tmpX = rand() % 30;
		int tmpY = rand() % 30;
		if (tmpX < 2) tmpX += 2;
		if (tmpY < 2) tmpY += 2;

		bool flag = false;
		for (auto& point : snake.body)
		{
			if ((point.GetX() == tmpX && point.GetY() == tmpY) ||
				(point.GetX() == bigX && point.GetY() == bigY))
			{
				flag = true;
				break;
			}
		}

		if (flag) continue;
		x = tmpX, y = tmpY;
		SetCursorPosition(x, y);
		SetColor(Color_ForeGround_Brown);
		std::cout << "★";
		cnt = (cnt + 1) % 5;
		if (!cnt) DrawBigFood(snake);
		break;
	}
}

void Food::DrawBigFood(Snake& snake)
{
	SetCursorPosition(5, 0);
	SetColor(Color_ForeGround_Highlight_LightGreen);
	// 进度条
	std::cout << "------------------------------------------";
	progressBar = 42;
	while (true)
	{
		int tmpX = rand() % 30;
		int tmpY = rand() % 30;
		if (tmpX < 2) tmpX += 2;
		if (tmpY < 2) tmpY += 2;

		bool flag = false;
		for (auto& point : snake.body)
		{
			if ((point.GetX() == tmpX && point.GetY() == tmpY) ||
				(point.GetX() == bigX && point.GetY() == bigY))
			{
				flag = true;
				break;
			}
		}

		if (flag) continue;
		bigX = tmpX, bigY = tmpY;
		SetCursorPosition(bigX, bigY);
		SetColor(FOREGROUND_GREEN | BACKGROUND_BLUE);
		std::cout << "■";
		isExistedBigFood = true;
		isFlash = true;
		break;
	}
}

int Food::GetCnt()
{
	return cnt;
}

// 限时闪烁食物
void Food::FlashBigFood()
{
	SetCursorPosition(bigX, bigY);
	SetColor(FOREGROUND_GREEN | BACKGROUND_BLUE);
	if (isFlash)
	{
		std::cout << "  ";
		isFlash = false;
	}
	else
	{
		std::cout << "■";
		isFlash = true;
	}
	SetCursorPosition(26, 0);
	SetColor(Color_ForeGround_Highlight_LightGreen);

	// 暂时没看懂
	for (int i = 42; i >= progressBar; i--)
	{
		// \b只是退格，但不会清除那一格的内容
		// 所以再输出 ，再退格
		std::cout << "\b \b";
	}

	if (--progressBar == 0)
	{
		SetCursorPosition(bigX, bigY);
		std::cout << "  ";
		isExistedBigFood = false;
		bigX = 0, bigY = 0;
	}
}

bool Food::GetBigFlag()
{
	return isExistedBigFood;
}

int Food::GetProgressBar()
{
	return progressBar;
}