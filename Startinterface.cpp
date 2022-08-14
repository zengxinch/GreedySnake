#include "startinterface.h"
#include "controller.h"

#include <windows.h>

// �ߴ���߳��ֵ���ȫ���ֵĹ���
void StartInterface::PrintFirst()
{
	for (auto& point : startsnake)
	{
		point.Print();
		Sleep(speed);
	}
}

// �ߴ��������ƶ��Ĺ���
void StartInterface::PrintSecond()
{
	// ��ͷ��Ҫ��10�ƶ���40
	for (int i = 10; i != 40; ++i) 
	{
		// ������ͷ����һ��λ�ã�������ѹ��startsnake�У����Ƴ���������βȥ��
		int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
		startsnake.emplace_back(Point(i, j));
		startsnake.back().Print();
		startsnake.front().Clear();
		startsnake.pop_front();
		Sleep(speed);
	}
}

// �ߴӽӴ��ұߵ���ʧ�Ĺ���
void StartInterface::PrintThird()
{
	// ���߻�û��ʧ������û�ƶ���ָ��λ��
	while (!startsnake.empty() || textsnake.back().GetX() < 33) 
	{
		// ����߻�û��ʧ�������ƶ�
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

// ���Ƹ���λ�ú������
void StartInterface::PrintText()
{
	for (auto& point : textsnake)
	{
		if (point.GetX() >= 0)
			point.Print();
	}
}

// �����������
void StartInterface::ClearText()
{
	// �����ͬʱ���������������ƶ�һ��
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

