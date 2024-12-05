#include "framework.h"
#include "Ball.h"

Ball::Ball()
{
	int rad = rand() % 50 + 10;
	_ball = make_shared<CircleCollider>(Vector(-1000,0), rad);
	_ball->SetSky();
}

Ball::~Ball()
{
}

void Ball::Update()
{
	if (IsOut() == true) _isActive = false;

	if (_isActive == false) return;
	_ball->Update();
	_ball->Center() += _direction * _speed;
	_gravity += 0.1f;
	_ball->Center().y += _gravity;
	



}

void Ball::Render(HDC hdc)
{
	if (_isActive == false) return;

	_ball->Render(hdc);
}

void Ball::Fire(Vector center, Vector dir)
{
	_isActive = true;
	_gravity = 0.0f;

	SetCenter(center);
	SetDirection(dir);
}

bool Ball::IsOut()
{
	int x = _ball->Center().x;
	int y = _ball->Center().y;

	if (x > WIN_WIDTH || x < 0 || y > WIN_HEIGHT)
		return true;

	return false;
}
