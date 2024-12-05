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

	bool IsFireReady() 
	{ 
		_fireTime += 0.02f;
		if(_fireTime > _delayTime)
		{
			_fireTime = 0.0f;
			return true;
		}
		return false;
	};

private:
	// 입력으로 좌우로 움직이게 만드는 함수
	void InputMove();
	// 입력으로 총신의 각도가 +,-가 되게 만드는 함수
	void InputBarrelRotation();

private:
	shared_ptr<CircleCollider> _body;
	shared_ptr<class Barrel> _barrel;

	int _poolCount = 80;
	vector<shared_ptr<class Ball>> _ballPool;
	float _delayTime = 0.1f;
	float _fireTime = 0.0f;

};

