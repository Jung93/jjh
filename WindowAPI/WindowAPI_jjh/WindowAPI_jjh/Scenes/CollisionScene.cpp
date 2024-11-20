#include "framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_myCircle = make_shared<CircleCollider>(Vector(400, 400), 70);
	_myMovingCircle = make_shared<CircleCollider>(Vector(0, 0), 100);
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	_myCircle->Update();
	_myMovingCircle->Update();
	
	_myMovingCircle->Center() = mousePos;

	if (_myCircle->IsCollision(_myMovingCircle))
		_myCircle->SetRed();
	else
	{
		_myCircle->SetGreen();
	}

}

void CollisionScene::Render(HDC hdc)
{
	_myCircle->Render(hdc);
	_myMovingCircle->Render(hdc);

}
