#include "framework.h"
#include "BoxCollider.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(Vector center, float radius)
	:_radius(radius)
{
	_type = Collider::Type::CIRCLE,
	_center = center;
	_colors[0] = CreatePen(3, 3, RED);
	_colors[1] = CreatePen(3, 3, GREEN);
	_colors[2] = CreatePen(3, 3, SKY);

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
	//과제
	auto a = other->GetOBB();

	Vector aTob = this->_center - a.position;

	float d = sqrtf(a.length[0] * a.length[0] + a.length[1] * a.length[1]) + this->_radius;
	if (d < aTob.Length())
		return false;

	Vector normal_ea1 = a.direction[0].NormalVector();
	Vector ea1 = a.direction[0];
	Vector normal_ea2 = a.direction[1].NormalVector();
	Vector ea2 = a.direction[1];


	//normal ea1 기준으로 투영
	float length = abs(normal_ea1.Dot(aTob));// a To b 길이의 절대값
	float lengthB = this->_radius;
	float lengthA = a.length[0];
	if (length > lengthB + lengthA)
		return false;

	//normal ea2 기준으로 투영
	length = abs(normal_ea2.Dot(aTob));// a To b 길이의 절대값
	lengthB = this->_radius;
	lengthA = a.length[1];
	if (length > lengthB + lengthA)
		return false;


	return true;


}