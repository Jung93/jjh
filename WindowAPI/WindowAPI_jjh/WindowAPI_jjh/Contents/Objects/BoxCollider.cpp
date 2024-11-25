#include "framework.h"
#include "BoxCollider.h"


BoxCollider::BoxCollider(Vector dot1, Vector dot2)
	:_halfSize(dot2 * 0.5f)
{
	_type = Collider::Type::BOX,
	_center = dot1;
	_colors[0] = CreatePen(3, 3, RED);
	_colors[1] = CreatePen(3, 3, GREEN);

	SetGreen();
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
	//x 축 기준 사이에 있다
	if(pos.x < Right() && pos.x > Left())
		if (pos.y < Bottom() && pos.y > Top())
		{
			return true;
		}

	return false;
}

bool BoxCollider::IsCollision(shared_ptr<CircleCollider> other) const
{
	//OBB 충돌
	OBB_INFO a = GetOBB();

	Vector aTob = other->Center() - a.position;

	float d = sqrtf(a.length[0] * a.length[0] + a.length[1] * a.length[1]) + other->Radius();
	if (d < aTob.Length())
		return false;

	Vector normal_ea1 = a.direction[0].NormalVector();
	Vector ea1 = a.direction[0];
	Vector normal_ea2 = a.direction[1].NormalVector();
	Vector ea2 = a.direction[1];


	//normal ea1 기준으로 투영
	float length = abs(normal_ea1.Dot(aTob));// a To b 길이의 절대값
	float lengthB = other->Radius();
	float lengthA = a.length[0];
	if (length > lengthB + lengthA)
		return false;

	//normal ea2 기준으로 투영
	length = abs(normal_ea2.Dot(aTob));// a To b 길이의 절대값
	lengthB = other->Radius();
	lengthA = a.length[1];
	if (length > lengthB + lengthA)
		return false;


	return true;
}

bool BoxCollider::IsCollision(shared_ptr<BoxCollider> other) const
{
	//OBB 충돌
	OBB_INFO a = GetOBB();
	OBB_INFO b = other->GetOBB();

	Vector aTob = b.position - a.position;
	Vector normal_ea1 = a.direction[0].NormalVector();
	Vector ea1 = a.direction[0];
	Vector normal_ea2 = a.direction[1].NormalVector();
	Vector ea2 = a.direction[1];

	Vector normal_eb1 = b.direction[0].NormalVector();
	Vector eb1 = b.direction[0];
	Vector normal_eb2 = b.direction[1].NormalVector();
	Vector eb2 = b.direction[1];

	//normal ea1 기준으로 투영
	float length = abs(normal_ea1.Dot(aTob));// a To b 길이의 절대값
	float lengthB = SeperaterAxis(normal_ea1, eb1, eb2);
	float lengthA = a.length[0];
	if (length > lengthB + lengthA)
		return false;

	//normal ea2 기준으로 투영
	length = abs(normal_ea2.Dot(aTob));// a To b 길이의 절대값
	lengthB = SeperaterAxis(normal_ea2, eb1, eb2);
	lengthA = a.length[1];
	if (length > lengthB + lengthA)
		return false;

	//normal eb1 기준으로 투영
	length = abs(normal_eb1.Dot(aTob));// a To b 길이의 절대값
	lengthA = SeperaterAxis(normal_eb1, ea1, ea2);
	lengthB = b.length[0];
	if (length > lengthB + lengthA)
		return false;

	//normal eb2 기준으로 투영
	length = abs(normal_eb2.Dot(aTob));// a To b 길이의 절대값
	lengthA = SeperaterAxis(normal_eb2, ea1, ea2);
	lengthB = a.length[1];
	if (length > lengthB + lengthA)
		return false;

	return true;
}

BoxCollider::OBB_INFO BoxCollider::GetOBB() const
{
	OBB_INFO info;
	info.position = _center;
	info.direction[0] = { _halfSize.x, 0 };
	info.direction[1] = { 0, -_halfSize.y };
	//info.direction[0].Normalize();
	//info.direction[1].Normalize();

	info.length[0] = _halfSize.x;
	info.length[1] = _halfSize.y;

	return info;
}

float BoxCollider::SeperaterAxis(Vector seperate, Vector e1, Vector e2) const
{
	float r1 = abs(seperate.Dot(e1));
	float r2 = abs(seperate.Dot(e2));

	return r1 + r2;
}
