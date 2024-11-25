#pragma once
class BoxCollider : public Collider
{
public:
	struct OBB_INFO
	{
		Vector position;
		Vector direction[2]; //가로 세로 벡터
		float length[2];// 가로 세로 길이

	};


	BoxCollider(Vector center, Vector size);
	~BoxCollider();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	int Left() const { return _center.x - _halfSize.x; }
	int Right() const { return _center.x + _halfSize.x; }
	int Top() const { return _center.y - _halfSize.y; }
	int Bottom() const { return _center.y + _halfSize.y; }


	virtual bool IsCollision(const Vector& pos) const override;
	virtual bool IsCollision(shared_ptr<class CircleCollider> other) const override;
	virtual bool IsCollision(shared_ptr<BoxCollider> other) const override;

	OBB_INFO GetOBB() const;
	float SeperaterAxis(Vector seperate, Vector e1, Vector e2) const;


private:
	//Vector _dot1;
	//Vector _dot2;


	Vector _halfSize;

};

