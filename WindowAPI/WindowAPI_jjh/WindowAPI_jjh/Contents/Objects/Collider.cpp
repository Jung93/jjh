#include "framework.h"
#include "Collider.h"

Collider::Collider()
{
}

Collider::~Collider()
{
}

bool Collider::IsCollision(shared_ptr<Collider> collider)
{
	//과제. dynamic casting 으로 변환하여 Box인지 Circle인지 확인
	shared_ptr<CircleCollider> circleCol = dynamic_pointer_cast<CircleCollider>(collider);
	//CircleCollider* circleCol2 = dynamic_cast<CircleCollider*>(this);

	//float radiusSum = circleCol2->Radius() + circleCol->Radius();
	//float length = (circleCol->Center() - circleCol2->Center()).Length();


	//return length < radiusSum;
	return false;
}

