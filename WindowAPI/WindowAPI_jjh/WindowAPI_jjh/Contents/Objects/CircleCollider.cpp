#include "framework.h"
#include "BoxCollider.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(Vector center, float radius)
	:_radius(radius)
{
	_center = center;
	_colors[0] = CreatePen(3, 3, RED);
	_colors[1] = CreatePen(3, 3, GREEN);

	SetGreen();
}

CircleCollider::~CircleCollider()
{
}

void CircleCollider::Update()
{
}

void CircleCollider::Render(HDC hdc)
{
	int left = _center.x - _radius;
	int right = _center.x + _radius;
	int top = _center.y - _radius;
	int bottom = _center.y + _radius;
	
	SelectObject(hdc, _colors[_curColor]);

	Ellipse(hdc, left, top, right, bottom);
}

bool CircleCollider::IsCollision(const Vector& pos) const
{
	float legnth = (pos - _center).Length();
	return legnth < _radius;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other) const
{
	float radiusSum = _radius + other->Radius();
	float length = (other->Center() - _center).Length();

	return length < radiusSum;

}

bool CircleCollider::IsCollision(shared_ptr<BoxCollider> other) const
{
	//°úÁ¦

	return false;
}