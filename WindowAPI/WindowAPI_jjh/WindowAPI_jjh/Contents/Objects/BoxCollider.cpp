#include "framework.h"
#include "BoxCollider.h"


BoxCollider::BoxCollider(Vector dot1, Vector dot2)
	:_halfSize(dot2 * 0.5f)
{
	_center = dot1;
	_colors[0] = CreatePen(3, 3, RED);
	_colors[1] = CreatePen(3, 3, GREEN);
}

BoxCollider::~BoxCollider()
{
}

void BoxCollider::Update()
{
}

void BoxCollider::Render(HDC hdc)
{
	//int left = _dot1.x;
	//int right = _dot2.x;
	//int top = _dot1.y;
	//int bottom = _dot2.y;

	//Rectangle(hdc, left, top, right, bottom);
	SelectObject(hdc, _colors[_curColor]);

	Rectangle(hdc, Left(), Top(), Right(), Bottom());
}

bool BoxCollider::IsCollision(const Vector& pos) const
{
	return false;
}

bool BoxCollider::IsCollision(shared_ptr<CircleCollider> other) const
{
	return false;
}

bool BoxCollider::IsCollision(shared_ptr<BoxCollider> other) const
{
	return false;
}