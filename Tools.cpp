#include "Tools.h"

void SetWindowSize(int cols, int rows)
{
	system("Title GreedySnake");
	char cmd[30];
	sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, rows);
	system(cmd);
}

void SetCursorPosition(const int x, const int y)
{
	// X���У�Y����
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetColor(int colorID)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor()
{	// ǰ��Ϊ��ɫ������Ϊ��ɫ����ɫ+��ɫ+��ɫ��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE | Color_BackGround_White);
}