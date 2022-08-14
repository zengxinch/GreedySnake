#pragma once

#include "Point.h"

#include <vector>

class Map
{
private:
	std::vector<Point> initmap;
public:
	Map()
	{
		for (int y = 1; y <= 30; y++) initmap.emplace_back(Point(y, 1));
		for (int x = 2; x <= 29; x++)
		{
			initmap.emplace_back(Point(1, x));
			initmap.emplace_back(Point(30, x));
		}
		for (int y = 1; y <= 30; y++) initmap.emplace_back(Point(y, 30));
	}

	void PrintInitmap();
};