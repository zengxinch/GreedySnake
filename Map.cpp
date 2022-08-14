#include "Map.h"

#include <Windows.h>

void Map::PrintInitmap()
{
	for (Point& p : initmap)
	{
		p.Print();
		Sleep(10);
	}
}