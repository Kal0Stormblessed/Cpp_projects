#include "Board.h"
#include <raylib.h>
#include <assert.h>

Board::Cell::Cell()
	:
	bExists(false),
	cellColor(WHITE)
{

}

void Board::Cell::SetColor(Color cellColor_in)
{
	cellColor = cellColor_in;
	bExists = true;
}

void Board::Cell::Remove()
{
	bExists = false;
}

Color Board::Cell::GetColor() const
{
	return cellColor;
}

Board::Board(int screenX, int screenY, int width, int height, int cellsize, int padding)
	:
	screenX(screenX),
	screenY(screenY),
	width(width),
	height(height),
	cellsize(cellsize),
	padding(padding)
{
	assert(width > 0 && height > 0);//If assertion triggers: the width is smaller than 0
	cells.resize(width * height);
}

void Board::SetCell(int x, int y, Color cellColor_in)
{
	assert(x >= 0 && y >= 0);
	assert(x < width && y < height);
	cells[y*width + x].SetColor(cellColor_in);
}

void Board::DrawCell(int x, int y) const
{
	assert(x >= 0 && x < width && y >= 0 && y < height);
	Color tempColor = cells[y * width + x].GetColor();
	DrawRectangle(screenX+x*cellsize+padding, screenY+y*cellsize+padding,cellsize-padding,cellsize-padding,tempColor);
}

void Board::Draw() const
{
	for (int iY = 0; iY < height; ++iY)
	{
		for (int iX = 0; iX < width; ++iX)
		{
			DrawCell(iX, iY);
		}
	}
}
