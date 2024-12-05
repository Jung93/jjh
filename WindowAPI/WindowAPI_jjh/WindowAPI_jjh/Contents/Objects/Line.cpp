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

	//Vector startVec = _start - other->_start;
	//Vector endVec = _end - other->_start;

	//float angle = startVec.Angle(other->_end - other->_start);
	//float angle2 = endVec.Angle(other->_end - other->_start);


	//if (angle >= 0.0f && angle2 <= 0.0f)
	//{
	//	return true;
	//}

	//return false;

	Vector dir1 = _end - _start;              // ���� ����(_line3)�� ���� ����
	Vector dir2 = other->_end - other->_start; // �� ��� ����(_line1)�� ���� ����

	// ������ �̿��� �� ������ �������� Ȯ��
	float denom = dir1.Cross(dir2);
	if ((int)denom == 0)               // ������ ��� (���� ����)
		return false;

	// �� ������ �����ϴ� ������ �Ķ���� ���
	Vector diff = other->_start - _start;
	float t = diff.Cross(dir2) / denom;       // ���� ����(_line3)�� �Ķ����
	float u = diff.Cross(dir1) / denom;       // �� ��� ����(_line1)�� �Ķ����

	_cross = _start + (dir1 * t);
	// �� ������ t, u�� [0, 1] ������ �ִ� ��� ����
	if (t >= 0.0f && t <= 1.0f && u >= 0.0f && u <= 1.0f)
		return true;

	return false;

}
