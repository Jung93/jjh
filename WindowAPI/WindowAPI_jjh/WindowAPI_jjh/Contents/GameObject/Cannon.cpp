#include "framework.h"
#include "Barrel.h"

#include "Cannon.h"

Cannon::Cannon()
{
	_body = make_shared<CircleCollider>(Vector(350, 350), 50);
	//_barrel = make_shared<Line>(_body->Center(), _body->Center() + Vector(150, 0));
	_barrel = make_shared<Barrel>();
	_ball = make_shared<Ball>();

}

Cannon::~Cannon()
{

}

void Cannon::Update()
{
	InputMove();

	InputBarrelRotation();
	Fire();

	_body->Update();
	_barrel->Update();
	_ball->Update();
}

void Cannon::Render(HDC hdc)
{
	_barrel->Render(hdc);
	_body->Render(hdc);
	_ball->Render(hdc);
}

void Cannon::Fire()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8001)
	{
		Vector dir = mousePos - _body->Center();
		dir.Normalize();


		_ball->SetCenter(_barrel->GetEnd() - dir * _ball->GetRadius());
		_ball->SetDirection(dir);

	}
}

void Cannon::InputMove()
{
	if (GetAsyncKeyState(0x41) & 0x8001)
	{
		_body->Center().x -= 3;
	}

	if (GetAsyncKeyState(0x44) & 0x8001)
	{
		_body->Center().x += 3;
	}

	if (GetAsyncKeyState(0x57) & 0x8001)
	{
		_body->Center().y -= 3;
	}

	if (GetAsyncKeyState(0x53) & 0x8001)
	{
		_body->Center().y += 3;
	}


}

void Cannon::InputBarrelRotation()
{
	// TODO : 방향키 위로 누르면 총신의 각도가 +가 되게
	// 방향키 아래를 누르면 총신의 각도가 -가 되게하기.
	Vector dir = mousePos - _body->Center();
	dir.Normalize();

	_barrel->SetDirection(dir);
}