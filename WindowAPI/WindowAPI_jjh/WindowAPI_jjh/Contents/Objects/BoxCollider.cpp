#include "framework.h"
#include "BoxCollider.h"

BoxCollider::BoxCollider(Vector dot1, Vector dot2)
	:_dot1(dot1)
	,_dot2(dot2)
{
}

BoxCollider::~BoxCollider()
{
}

void BoxCollider::Update()
{
}

void BoxCollider::Render(HDC hdc)
{
	int left = _dot1.x;
	int right = _dot2.x;
	int top = _dot1.y;
	int bottom = _dot2.y;

	Rectangle(hdc, left, top, right, bottom);
}