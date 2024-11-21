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
	//����. dynamic casting ���� ��ȯ�Ͽ� Box���� Circle���� Ȯ��
	shared_ptr<CircleCollider> circleCol = dynamic_pointer_cast<CircleCollider>(collider);
	//CircleCollider* circleCol2 = dynamic_cast<CircleCollider*>(this);

	//float radiusSum = circleCol2->Radius() + circleCol->Radius();
	//float length = (circleCol->Center() - circleCol2->Center()).Length();


	//return length < radiusSum;
	return false;
}

