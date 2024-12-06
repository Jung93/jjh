#include "framework.h"
#include "Line.h"

Line::Line(Vector start, Vector end)
	: _start(start)
	, _end(end)
{
	_colors[0] = CreatePen(3, 3, RED);
	_colors[1] = CreatePen(3, 3, GREEN);

	SetGreen();
}

Line::~Line()
{
	for (auto& pen : _colors)
	{
		DeleteObject(pen);
	}
}

void Line::Update()
{
}

void Line::Render(HDC hdc)
{
	SelectObject(hdc, _colors[_curColor]);

	int x1 = _start.x;
	int y1 = _start.y;
	int x2 = _end.x;
	int y2 = _end.y;

	MoveToEx(hdc, x1, y1, nullptr);
	LineTo(hdc, x2, y2);
}

bool Line::IsCollision(shared_ptr<Line> other) 
{
	Vector dir1 = _end - _start;              
	Vector dir2 = other->_end - other->_start;
	
	float denom = dir1.Cross(dir2);
	if ((int)denom == 0)               
		return false;

	Vector diff = other->_start - _start;
	float t = diff.Cross(dir2) / denom;       
	float u = diff.Cross(dir1) / denom;       

	_cross = _start + (dir1 * t);

	if (t >= 0.0f && t <= 1.0f && u >= 0.0f && u <= 1.0f)
		return true;

	return false;

}
