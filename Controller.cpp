#include "Map.h"
#include "Food.h"
#include "Tools.h"
#include "Snake.h"
#include "Controller.h"
#include "Startinterface.h"

#include <time.h>
#include <iostream>
#include <conio.h>

// ��ʼ����
void Controller::Start()
{
	// ���ô��ڴ�С
	SetWindowSize(41, 32);
	// ���ÿ�ʼ����ǰ��Ϊ��ɫ
	SetColor(FOREGROUND_GREEN);
	StartInterface start;
	start.Action();

	// ���ù��λ�ã��������ʾ��ȴ����ⰴ�����
	SetCursorPosition(13, 26);
	std::cout << "Press any key to start...";
	SetCursorPosition(13, 27);
	system("pause");
}

// ����ѡ���ѶȽ���
void Controller::Select()
{
	// ��ʼ�������Ѷ�ѡ������Ϊǳ��ɫ
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
	
	// ��һ��ѡ�����ñ���ɫ��ʾ��ǰ��ѡ��
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
	

	score = 0, key = 1;      // ���·����ѡ��ģ��; ��¼ѡ�����ʼѡ�е�һ��
	int ch;                  // ��¼����ֵ
	bool flag = false;       // ��¼�Ƿ����Enter

	while (ch = _getch())
	{
		switch (ch)
		{
		case 72: // ����
			if (key > 1) // ��ѡ����Ϊ��һ��ʱ��UP��Ч
			{
				switch (key)
				{
				case 2:
					// ��ѡ��������ѡ�б���ɫ
					SetCursorPosition(27, 22);
					SetBackColor();
					std::cout << "Easy";

					// ��δѡ����ָ�ԭ����ɫ
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
		default: // ��Ч����
			break;
		}
		if (flag) break;

		// ������������½ǣ���������˸Ӱ����Ϸ����
		SetCursorPosition(0, 31); 
	}

	// ������ѡ�������ߵ��ƶ��ٶȣ�SpeedԽС���ٶ�Խ��
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

// ������Ϸ����
void Controller::DrawGame()
{
	// ������Ļ
	system("cls");
	
	// ���Ƶ�ͼ�߽�
	SetColor(Color_ForeGround_LightGreen);
	Map* map = new Map();
	map->PrintInitmap();
	delete map;

	// ���Ʋ����
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
	std::cout << "Score��";
	SetCursorPosition(35, 7);
	std::cout << "0";
	SetCursorPosition(32, 9);
	std::cout << "Move(Arrow keys).";
	SetCursorPosition(32, 11);
	std::cout << "Breaking(ESC).";
}

// ѡ��˵�
int Controller::Menu()
{
	// ���Ʋ˵�
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

	// ����ѡ��
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

	// ѡ�������Ϸ���򽫲˵�����
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

// ���Ʒ���
void Controller::RewriteScore()
{
	// ���÷���Ϊ6λ���Ҷ���
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

// ��Ϸ��������
int Controller::GameOver()
{
	// ������Ϸ��������
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

	// ѡ��
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

// ��Ϸ����ѭ��
int Controller::PlayGame()
{
	// ��ʼ���ߺ�ʳ��
	Snake* snake = new Snake();
	Food* food = new Food();
	SetColor(Color_ForeGround_Yellow);
	snake->InitSnake();

	// ������������ӣ����ޣ�ʳ����ֵ�λ�ý���̶�
	srand((unsigned)time(NULL));
	food->DrawFood(*snake);

	// ��Ϸѭ��
	// �ж��Ƿ�ײ��ǽ��������
	while (snake->OverEdge() && snake->HitItself())
	{
		// ����ѡ��˵�����ESC����false
		if (!snake->ChangeDirection())
		{
			// ���Ʋ˵������õ�����ֵ
			int tmp = Menu();
			switch (tmp)
			{
			case 1: // ������Ϸ
				break;
			case 2: // ���¿�ʼ
				delete snake;
				delete food;
				// ���� 1 ��ʾ���¿�ʼ
				return 1;
			case 3:
				delete snake;
				delete food;
				// ���� 2 ��ʾ�˳���Ϸ
				return 2;
			default:
				break;
			}
		}

		// �Ե�ʳ��
		if (snake->GetFood(*food))
		{
			snake->Move(); // ������
			UpdateScore(1); // ���·���
			RewriteScore(); // ���»��Ʒ���
			food->DrawFood(*snake); // �����µ�ʳ��
		}
		else
		{
			snake->NormalMove();
		}

		// �Ե���ʱʳ��
		if (snake->GetBigFood(*food))
		{
			snake->Move();
			UpdateScore(food->GetProgressBar() / 5); // ����������ʱʳ�������ȷ��
			RewriteScore();
		}

		// �������ʱʳ���˸��
		if (food->GetBigFlag())
		{
			food->FlashBigFood();
		}

		Sleep(speed);
	}

	// ������
	delete snake;
	delete food;
	// ������Ϸ�������棬��������ѡ��
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

// ��Ϸһ��ѭ��
void Controller::Game()
{
	// ��ʼ��Ϸ
	Start();

	// ��Ϸ����Ϊһ����ѭ����ֱ���˳���Ϸʱ����ѭ��������ֵ��tmp
	while (true)
	{
		Select();
		DrawGame();
		// ������Ϸѭ���������¿�ʼ���˳���Ϸʱ������ѭ��������ֵ��tmp
		int tmp = PlayGame();
		
		if (tmp == 1)
		{
			system("cls");
			continue;
		}
		else break;
	}
}