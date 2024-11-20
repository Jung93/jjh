#pragma once
class BoxCollider : public Collider
{
public:
	BoxCollider(Vector center, Vector size);
	~BoxCollider();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	int Left() { return _center.x - _halfSize.x; }
	int Right() { return _center.x + _halfSize.x; }
	int Top() { return _center.y - _halfSize.y; }
	int Bottom() { return _center.y + _halfSize.y; }


	virtual bool IsCollision(const Vector& pos) const override;
	virtual bool IsCollision(shared_ptr<class CircleCollider> other) const override;
	virtual bool IsCollision(shared_ptr<BoxCollider> other) const override;


private:
	//Vector _dot1;
	//Vector _dot2;


	Vector _halfSize;

};

