#include "Map.h"
#include "Food.h"
#include "Tools.h"
#include "Snake.h"
#include "Controller.h"
#include "Startinterface.h"

#include <time.h>
#include <iostream>
#include <conio.h>

// 开始界面
void Controller::Start()
{
	// 设置窗口大小
	SetWindowSize(41, 32);
	// 设置开始动画前景为绿色
	SetColor(FOREGROUND_GREEN);
	StartInterface start;
	start.Action();

	// 设置光标位置，并输出提示语，等待任意按间结束
	SetCursorPosition(13, 26);
	std::cout << "Press any key to start...";
	SetCursorPosition(13, 27);
	system("pause");
}

// 绘制选择难度界面
void Controller::Select()
{
	// 初始化界面难度选择，设置为浅绿色
	SetColor(Color_ForeGround_LightGreen);
	SetCursorPosition(13, 26);
	std::cout << "                          ";
	SetCursorPosition(13, 27);
	std::cout << "                          ";
	SetCursorPosition(6, 21);
	std::cout << "Please Choose Game Difficulty.";
	SetCursorPosition(6, 22);
	std::cout << "(Press up or down to choose";
	SetCursorPosition(6, 23);
	std::cout << " and Press Enter to confirm.)";
	
	// 第一个选项设置背景色表示当前被选中
	SetCursorPosition(27, 22);
	SetBackColor();
	std::cout << "Easy";
	SetCursorPosition(27, 24);
	SetColor(Color_ForeGround_LightGreen);
	std::cout << "Normal";
	SetCursorPosition(27, 26);
	std::cout << "Hard";
	SetCursorPosition(27, 28);
	std::cout << "Much Hard";
	SetCursorPosition(0, 31);
	

	score = 0, key = 1;      // 上下方向键选择模块; 记录选中项，初始选中第一个
	int ch;                  // 记录键入值
	bool flag = false;       // 记录是否键入Enter

	while (ch = _getch())
	{
		switch (ch)
		{
		case 72: // 向上
			if (key > 1) // 当选中项为第一项时，UP无效
			{
				switch (key)
				{
				case 2:
					// 将选中项设置选中背景色
					SetCursorPosition(27, 22);
					SetBackColor();
					std::cout << "Easy";

					// 将未选中项恢复原来颜色
					SetCursorPosition(27, 24);
					SetColor(Color_ForeGround_LightGreen);
					std::cout << "Normal";

					--key;
					break;
				case 3:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "Normal";

					SetCursorPosition(27, 26);
					SetColor(Color_ForeGround_LightGreen);
					std::cout << "Hard";

					--key;
					break;
				case 4:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "Hard";

					SetCursorPosition(27, 28);
					SetColor(Color_ForeGround_LightGreen);
					std::cout << "Much Hard";

					--key;
					break;
				}
			}
			break;

		case 80://DOWN
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "Normal";

					SetCursorPosition(27, 22);
					SetColor(Color_ForeGround_LightGreen);
					std::cout << "Easy";

					++key;
					break;
				case 2:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "Hard";

					SetCursorPosition(27, 24);
					SetColor(Color_ForeGround_LightGreen);
					std::cout << "Normal";

					++key;
					break;
				case 3:
					SetCursorPosition(27, 28);
					SetBackColor();
					std::cout << "Much Hard";

					SetCursorPosition(27, 26);
					SetColor(Color_ForeGround_LightGreen);
					std::cout << "Hard";

					++key;
					break;
				}
			}
			break;

		case 13: // Enter
			flag = true;
			break;
		default: // 无效按键
			break;
		}
		if (flag) break;

		// 将光标置于左下角，避免光标闪烁影响游戏体验
		SetCursorPosition(0, 31); 
	}

	// 根据所选项设置蛇的移动速度，Speed越小，速度越快
	switch (key) 
	{
	case 1:
		speed = 135;
		break;
	case 2:
		speed = 100;
		break;
	case 3:
		speed = 60;
		break;
	case 4:
		speed = 30;
		break;
	default:
		break;
	}
}

// 绘制游戏界面
void Controller::DrawGame()
{
	// 清理屏幕
	system("cls");
	
	// 绘制地图边界
	SetColor(Color_ForeGround_LightGreen);
	Map* map = new Map();
	map->PrintInitmap();
	delete map;

	// 绘制侧边栏
	SetColor(Color_ForeGround_LightGreen);
	SetCursorPosition(33, 1);
	std::cout << "Greedy Snake";
	SetCursorPosition(31, 4);
	std::cout << "Difficulty:";
	SetCursorPosition(31, 5);

	switch (key)
	{
	case 1:
		std::cout << "Easy Mode";
		break;
	case 2:
		std::cout << "Normal Mode";
		break;
	case 3:
		std::cout << "Hard Mode";
		break;
	case 4:
		std::cout << "Much Hard Mode";
		break;
	default:
		break;
	}
	SetCursorPosition(31, 7);
	std::cout << "Score：";
	SetCursorPosition(35, 7);
	std::cout << "0";
	SetCursorPosition(32, 9);
	std::cout << "Move(Arrow keys).";
	SetCursorPosition(32, 11);
	std::cout << "Breaking(ESC).";
}

// 选择菜单
int Controller::Menu()
{
	// 绘制菜单
	SetColor(Color_ForeGround_Highlight_LightGreen);
	SetCursorPosition(32, 19);
	std::cout << "Menu: ";
	Sleep(100);
	SetCursorPosition(34, 21);
	SetBackColor();
	std::cout << "Game Continue";
	Sleep(100);
	SetColor(Color_ForeGround_Highlight_LightGreen);
	SetCursorPosition(34, 23);
	std::cout << "Game Restart";
	Sleep(100);
	SetCursorPosition(34, 25);
	std::cout << "Game Over";
	SetCursorPosition(0, 31);

	// 进行选择
	int ch, tmp_key = 1;
	bool flag = false;

	while (ch = _getch())
	{
		switch (ch)
		{
		case 72:
			if (tmp_key > 1)
			{
				switch (tmp_key)
				{
				case 2:
					SetCursorPosition(34, 21);
					SetBackColor();
					std::cout << "Game Continue";
					SetCursorPosition(34, 23);
					SetColor(Color_ForeGround_Highlight_LightGreen);
					std::cout << "Game Restart";
					tmp_key--;
					break;
				
				case 3:
					SetCursorPosition(34, 23);
					SetBackColor();
					std::cout << "Game Restart";
					SetCursorPosition(34, 25);
					SetColor(Color_ForeGround_Highlight_LightGreen);
					std::cout << "Game Over";
					tmp_key--;
					break;
				}
			}
			break;

		case 80:
			if (tmp_key < 3)
			{
				switch (tmp_key)
				{
				case 1:
					SetCursorPosition(34, 23);
					SetBackColor();
					std::cout << "Game Restart";
					SetCursorPosition(34, 21);
					SetColor(Color_ForeGround_Highlight_LightGreen);
					std::cout << "Game Continue";
					tmp_key++;
					break;

				case 2:
					SetCursorPosition(34, 25);
					SetBackColor();
					std::cout << "Game Over";
					SetCursorPosition(34, 23);
					SetColor(Color_ForeGround_Highlight_LightGreen);
					std::cout << "Game Restart";
					tmp_key++;
					break;
				}
			}
			break;
		case 13: //Enter
			flag = true;
			break;
		default:
			break;
		}

		if (flag) break;
		SetCursorPosition(0, 31);
	}

	// 选择继续游戏，则将菜单擦除
	if (tmp_key == 1)
	{
		SetCursorPosition(32, 19);
		std::cout << "              ";
		SetCursorPosition(34, 21);
		std::cout << "              ";
		SetCursorPosition(34, 23);
		std::cout << "              ";
		SetCursorPosition(34, 25);
		std::cout << "              ";
	}

	return tmp_key;
}

void Controller::UpdateScore(const int& t)
{
	score += key * 10 + t;
}

// 绘制分数
void Controller::RewriteScore()
{
	// 设置分数为6位，右对齐
	SetCursorPosition(35, 7);
	SetColor(Color_ForeGround_Highlight_LightGreen);
	int bit = 0, tmp = score;

	while (tmp != 0)
	{
		++bit;
		tmp /= 10;
	}

	for (int i = 0; i < (6 - bit); ++i)
		std::cout << " ";
	std::cout << score;
}

// 游戏结束界面
int Controller::GameOver()
{
	// 绘制游戏结束界面
	Sleep(500);
	SetColor(Color_ForeGround_Highlight_LightGreen);
	SetCursorPosition(10, 8);
	std::cout << "---------------";
	Sleep(30);
	SetCursorPosition(9, 9);
	std::cout << "|      Game Over!      |";
	Sleep(30);
	SetCursorPosition(9, 10);
	std::cout << "|                      |";
	Sleep(30);
	SetCursorPosition(9, 11);
	std::cout << "|       You Dead!      |";
	Sleep(30);
	SetCursorPosition(9, 12);
	std::cout << "|                      |";
	Sleep(30);
	SetCursorPosition(9, 13);
	std::cout << "|      Your Score!     |";
	SetCursorPosition(24, 13);
	Sleep(30);
	std::cout << score;
	SetCursorPosition(9, 14);
	std::cout << "|                      |";
	Sleep(30);
	SetCursorPosition(9, 15);
	std::cout << "|      Game Again?     |";
	Sleep(30);
	SetCursorPosition(9, 16);
	std::cout << "|                      |";
	Sleep(30);
	SetCursorPosition(9, 17);
	std::cout << "|                      |";
	Sleep(30);
	SetCursorPosition(9, 18);
	std::cout << "|   Ok            No   |";
	Sleep(30);
	SetCursorPosition(9, 19);
	std::cout << "|                      |";
	Sleep(30);
	SetCursorPosition(9, 20);
	std::cout << "|                      |";
	Sleep(30);
	SetCursorPosition(10, 21);
	std::cout << "--------------------";
	
	Sleep(100);
	SetCursorPosition(11, 18);
	SetBackColor();
	std::cout << "Ok";
	SetCursorPosition(0, 31);

	// 选择
	int ch, tmp_key = 1;
	bool flag = false;
	while (ch = _getch())
	{	
		switch (ch)
		{
		case 75: //LEFT
			if (tmp_key > 1)
			{
				SetCursorPosition(11, 18);
				SetBackColor();
				std::cout << "Ok";
				SetCursorPosition(18, 18);
				SetColor(Color_ForeGround_Highlight_LightGreen);
				std::cout << "No";
				--tmp_key;
			}
			break;
		case 77: //RIGHT
			if (tmp_key < 2)
			{
				SetCursorPosition(18, 18);
				SetBackColor();
				std::cout << "No";
				SetCursorPosition(11, 18);
				SetColor(Color_ForeGround_Highlight_LightGreen);
				std::cout << "Ok";
				++tmp_key;
			}
			break;
		case 13:
			flag = true;
			break;
		default:
			break;
		}
		SetCursorPosition(0, 31);
		if (flag) break;
	}

	SetColor(Color_ForeGround_Highlight_LightGreen);
	switch (tmp_key)
	{
	case 1:
		return 1; // Restart Game
	case 2:
		return 2; // Exit Game
	default:
		return 1;
	}
}

// 游戏二级循环
int Controller::PlayGame()
{
	// 初始化蛇和食物
	Snake* snake = new Snake();
	Food* food = new Food();
	SetColor(Color_ForeGround_Yellow);
	snake->InitSnake();

	// 设置随机数种子，若无，食物出现的位置将会固定
	srand((unsigned)time(NULL));
	food->DrawFood(*snake);

	// 游戏循环
	// 判断是否撞到墙或者自身
	while (snake->OverEdge() && snake->HitItself())
	{
		// 调出选择菜单，按ESC返回false
		if (!snake->ChangeDirection())
		{
			// 绘制菜单，并得到返回值
			int tmp = Menu();
			switch (tmp)
			{
			case 1: // 继续游戏
				break;
			case 2: // 重新开始
				delete snake;
				delete food;
				// 返回 1 表示重新开始
				return 1;
			case 3:
				delete snake;
				delete food;
				// 返回 2 表示退出游戏
				return 2;
			default:
				break;
			}
		}

		// 吃到食物
		if (snake->GetFood(*food))
		{
			snake->Move(); // 蛇增长
			UpdateScore(1); // 更新分数
			RewriteScore(); // 重新绘制分数
			food->DrawFood(*snake); // 绘制新的食物
		}
		else
		{
			snake->NormalMove();
		}

		// 吃到限时食物
		if (snake->GetBigFood(*food))
		{
			snake->Move();
			UpdateScore(food->GetProgressBar() / 5); // 分数根据限时食物进度条确定
			RewriteScore();
		}

		// 如果有限时食物，闪烁它
		if (food->GetBigFlag())
		{
			food->FlashBigFood();
		}

		Sleep(speed);
	}

	// 蛇死亡
	delete snake;
	delete food;
	// 绘制游戏结束界面，并返回所选项
	int tmp = GameOver();
	switch (tmp)
	{
	case 1:
		return 1;
	case 2:
		return 2;
	default:
		return 2;
	}
}

// 游戏一级循环
void Controller::Game()
{
	// 开始游戏
	Start();

	// 游戏可视为一个死循环，直到退出游戏时结束循环并返回值给tmp
	while (true)
	{
		Select();
		DrawGame();
		// 开启游戏循环，当重新开始或退出游戏时，结束循环并返回值给tmp
		int tmp = PlayGame();
		
		if (tmp == 1)
		{
			system("cls");
			continue;
		}
		else break;
	}
}