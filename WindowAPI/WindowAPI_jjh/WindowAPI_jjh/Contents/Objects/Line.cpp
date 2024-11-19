#include "framework.h"
#include "Line.h"

Line::Line(Vector start, Vector end)
	: _start(start)
	, _end(end)
{
}

Line::~Line()
{
}

void Line::Update()
{
}

void Line::Render(HDC hdc)
{
	int x1 = _start.x;
	int y1 = _start.y;
	int x2 = _end.x;
	int y2 = _end.y;

	MoveToEx(hdc, x1, y1, nullptr);
	LineTo(hdc, x2, y2);
}