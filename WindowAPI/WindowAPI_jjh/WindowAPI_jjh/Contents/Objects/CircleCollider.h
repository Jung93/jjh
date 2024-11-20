#pragma once

//1. 색
//2. 상속관계 정의
//3. 충돌처리(AABB, OBB)
class BoxCollider;

class CircleCollider : public Collider
{
public:
	CircleCollider(Vector center, float radius);
	~CircleCollider();

	//void SetCenter(Vector pos) { _center = pos; }
	//Vector GetCenter() { return _center; }
	float& Radius() { return _radius; }

	virtual void Update() override;
	virtual void Render(HDC hdc) override;



	virtual bool IsCollision(const Vector& pos) const override;
	virtual bool IsCollision(shared_ptr<CircleCollider> other) const override;
	virtual bool IsCollision(shared_ptr<BoxCollider> other) const override;

private:

	float _radius;
};

