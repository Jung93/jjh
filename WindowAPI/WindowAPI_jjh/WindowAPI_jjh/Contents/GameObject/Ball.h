#pragma once
class Ball
{
public:

	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	void SetDirection(Vector dir) { _direction = dir; }
	void SetCenter(Vector center) { _ball->Center() = center; }
	float GetRadius() { return _ball->Radius(); }

private:
	shared_ptr<CircleCollider> _ball;
	Vector _direction;
	float _speed = 10.0f;
};

