#pragma once
#include <raylib.h>
#include <vector>
#include "Vec2.h"

class Board
{
private:
	class Cell
	{
	public:
		Cell();
		void SetColor(Color cellColor_in);
		void Remove();

		Color GetColor() const;
	private:
		bool bExists;
		Color cellColor;
	};

public:

	Board(int screenX, int screenY, int width, int height, int cellsize, int padding);
	void SetCell(int x, int y, Color cellColor_in);
	void DrawCell(int x, int y) const;
	void Draw() const;
private:
	std::vector<Cell> cells;
	const int width;
	const int height;
	const int cellsize;
	const int padding;
	int screenX;
	int screenY;

};