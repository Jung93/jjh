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

	const Vector& GetCenter() { return _ball->Center(); }

	void Fire(Vector center, Vector dir);

	bool IsActive() { return _isActive; }
	bool IsOut();

private:
	shared_ptr<CircleCollider> _ball;
	Vector _direction;
	float _speed = 10.0f;
	float _gravity = 0.0f;

	bool _isActive = false;
};

