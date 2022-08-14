#pragma once

#include "Snake.h"

class Snake;

class Food
{
private:
	int x, y, cnt;
	int bigX, bigY;
	int progressBar;
	bool isFlash; // 闪烁标记
	bool isExistedBigFood; // 限时食物标记
	friend class Snake;
public:
	Food() : x(0), y(0), cnt(0), bigX(0), bigY(0), progressBar(0), isFlash(false), isExistedBigFood(false) {}
	int GetCnt();
	int GetProgressBar();
	bool GetBigFlag();
	void DrawFood(Snake&);
	void DrawBigFood(Snake&);
	void FlashBigFood();
};