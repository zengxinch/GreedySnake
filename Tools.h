#pragma once

#include <windows.h>
#include <stdio.h>

#define Color_BackGround_White BACKGROUND_BLUE |BACKGROUND_GREEN | BACKGROUND_RED
#define Color_ForeGround_LightGreen FOREGROUND_BLUE | FOREGROUND_GREEN
#define Color_ForeGround_Brown FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN
#define Color_ForeGround_Yellow FOREGROUND_RED | FOREGROUND_GREEN
#define Color_ForeGround_Highlight_LightGreen FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY // 11
#define Color_ForeGround_Highlight_Yellow FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY

void SetWindowSize(int cols, int rows);
void SetCursorPosition(const int x, const int y);
void SetColor(int colorID);
void SetBackColor();