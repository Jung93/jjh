#pragma once
#include "Barrel.h"
#include "Ball.h"

class Cannon : public enable_shared_from_this<Cannon>
{
public:
	Cannon();
	~Cannon();

	void Update();
	void Render(HDC hdc);

	const Vector& GetCenter() { return _body->Center(); }

	void Ready() { _barrel->SetCannon(shared_from_this()); }
	void Fire();

private:
	// �Է����� �¿�� �����̰� ����� �Լ�
	void InputMove();
	// �Է����� �ѽ��� ������ +,-�� �ǰ� ����� �Լ�
	void InputBarrelRotation();

private:
	shared_ptr<CircleCollider> _body;
	shared_ptr<class Barrel> _barrel;
	shared_ptr<class Ball> _ball;
};
