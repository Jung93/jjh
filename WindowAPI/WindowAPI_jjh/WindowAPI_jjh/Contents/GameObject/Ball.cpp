#include "framework.h"
#include "Ball.h"

Ball::Ball()
{
	_ball = make_shared<CircleCollider>(Vector(-1000,0), 15);
}

Ball::~Ball()
{
}

void Ball::Update()
{
	_ball->Center() += _direction * _speed;
	_ball->Update();
	
}

void Ball::Render(HDC hdc)
{
	_ball->Render(hdc);
}
