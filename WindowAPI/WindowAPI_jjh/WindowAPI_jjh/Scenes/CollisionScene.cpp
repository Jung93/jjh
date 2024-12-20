#include "framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	//_myCircle = make_shared<CircleCollider>(Vector(400, 400), 70);
	//_myMovingCircle = make_shared<CircleCollider>(Vector(0, 0), 100);
	//_myBox = make_shared<BoxCollider>(Vector(600, 600), Vector(100, 100));

	_myCircle = make_shared<CircleCollider>(Vector(400, 400), 70);
	_myMovingCircle = make_shared<BoxCollider>(Vector(0, 0), Vector(100,100));
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	_myCircle->Update();
	_myMovingCircle->Update();
	//_myBox->Update();

	_myMovingCircle->Center() = mousePos;

	if (_myCircle->IsCollision(_myMovingCircle))
		_myCircle->SetRed();
	else
	{
		_myCircle->SetGreen();
	}

	//_myMovingCircle->Center() = mousePos;

	//if (_myMovingCircle->IsCollision(_myCircle))
	//	_myCircle->SetRed();
	//else
	//{
	//	_myCircle->SetGreen();
	//}

	//if (_myBox->IsCollision(_myMovingCircle))
	//	_myBox->SetRed();
	//else
	//{
	//	_myBox->SetGreen();

	//}

	//if (_myBox->IsCollision(mousePos))
	//{
	//	_myBox->SetRed();
	//}
	//else 
	//{
	//	_myBox->SetGreen();
	//}
	//;

}

void CollisionScene::Render(HDC hdc)
{
	_myCircle->Render(hdc);
	_myMovingCircle->Render(hdc);
	//_myBox->Render(hdc);
}
