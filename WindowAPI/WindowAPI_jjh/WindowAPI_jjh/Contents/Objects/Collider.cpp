#include "framework.h"
#include "Collider.h"
#include "CircleCollider.h"

Collider::Collider()
{
}

Collider::~Collider()
{
}

bool Collider::IsCollision(shared_ptr<Collider> collider) const
{

	switch (collider->_type)
	{
	case Collider::NONE:
		return false;
	case Collider::CIRCLE:
	{
		shared_ptr<CircleCollider> circle = dynamic_pointer_cast<CircleCollider>(collider);
		return IsCollision(circle);
	}

	case Collider::BOX:
	{
		shared_ptr<BoxCollider> box = dynamic_pointer_cast<BoxCollider>(collider);
		return IsCollision(box);
	}
	default:
		break;
	}


	/*shared_ptr<CircleCollider> circleCol = dynamic_pointer_cast<CircleCollider>(collider);
	CircleCollider* circleCol2 = dynamic_cast<CircleCollider*>(this);
	BoxCollider* boxCol = dynamic_cast<BoxCollider*>(this);


	if (circleCol2 != nullptr)
	{
		float radiusSum = circleCol2->Radius() + circleCol->Radius();
		float length = (circleCol->Center() - circleCol2->Center()).Length();
		return length < radiusSum;
	}

	if (boxCol != nullptr)
	{
		int boxX = circleCol->Center().x;
		int boxY = circleCol->Center().y;

		if (circleCol->Center().x < boxCol->Left()) {
			boxX = boxCol->Left();
		}
		else if (circleCol->Center().x > boxCol->Right()) {
			boxX = boxCol->Right();
		}
		if (circleCol->Center().y < boxCol->Top()) {
			boxY = boxCol->Top();
		}
		else if (circleCol->Center().y > boxCol->Bottom()) {
			boxY = boxCol->Bottom();
		}

		int distX = circleCol->Center().x - boxX;
		int distY = circleCol->Center().y - boxY;

		return distX * distX + distY * distY < circleCol->Radius() * circleCol->Radius();

	}*/
	
	return false;
}

