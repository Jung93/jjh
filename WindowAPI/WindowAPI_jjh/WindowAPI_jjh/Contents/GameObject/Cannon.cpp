#include "framework.h"
#include "Barrel.h"
#include "Ball.h"
#include "Cannon.h"

Cannon::Cannon()
{
	_body = make_shared<CircleCollider>(Vector(350, 350), 50);
	_barrel = make_shared<Barrel>();

	for(int i = 0; i < _poolCount; i++)
	{
		auto ball = make_shared<Ball>();
		_ballPool.push_back(ball);
	}
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	_body->Update();
	_barrel->Update();
	srand(time(nullptr));

	for (auto ball : _ballPool)
	{
		ball->Update();
	}

	InputMove();
	InputBarrelRotation();

	if(IsFireReady())
		Fire();


}

void Cannon::Render(HDC hdc)
{
	_barrel->Render(hdc);
	_body->Render(hdc);
	for (auto ball : _ballPool)
	{
		ball->Render(hdc);
	}
}

void Cannon::Fire()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8001)
	{

		auto iter = find_if(_ballPool.begin(), _ballPool.end(), [](const shared_ptr<Ball>& ball)->bool 
			{
				if (ball->IsActive() == false)
					return true;
				return false;
			});

		if (iter == _ballPool.end()) return;
		//if (_delayTime <= 0.0f)
		//{
			(*iter)->Fire(_barrel->GetEnd(), _barrel->GetDirection());
			//_delayTime = 40.0f;
		//}
		//_delayTime -= 1.0f;
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