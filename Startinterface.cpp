#include "startinterface.h"
#include "controller.h"

#include <windows.h>

// 蛇从左边出现到完全出现的过程
void StartInterface::PrintFirst()
{
	for (auto& point : startsnake)
	{
		point.Print();
		Sleep(speed);
	}
}

// 蛇从左向右移动的过程
void StartInterface::PrintSecond()
{
	// 蛇头需要从10移动到40
	for (int i = 10; i != 40; ++i) 
	{
		// 计算蛇头的下一个位置，并将其压入startsnake中，绘制出来，将蛇尾去掉
		int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
		startsnake.emplace_back(Point(i, j));
		startsnake.back().Print();
		startsnake.front().Clear();
		startsnake.pop_front();
		Sleep(speed);
	}
}

// 蛇从接触右边到消失的过程
void StartInterface::PrintThird()
{
	// 当蛇还没消失或文字没移动到指定位置
	while (!startsnake.empty() || textsnake.back().GetX() < 33) 
	{
		// 如果蛇还没消失，继续移动
		if (!startsnake.empty()) 
		{
			startsnake.front().Clear();
			startsnake.pop_front();
		}
		ClearText();
		PrintText();
		Sleep(speed);
	}
}

// 绘制更新位置后的文字
void StartInterface::PrintText()
{
	for (auto& point : textsnake)
	{
		if (point.GetX() >= 0)
			point.Print();
	}
}

// 清除已有文字
void StartInterface::ClearText()
{
	// 清除的同时将文字整体向右移动一格
	for (auto& point : textsnake) 
	{
		if (point.GetX() >= 0)
			point.Clear();
		point.ChangePosition(point.GetX() + 1, point.GetY());
	}
}

void StartInterface::Action()
{
	PrintFirst();
	PrintSecond();
	PrintThird();
}

