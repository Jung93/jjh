#pragma once
class BoxCollider
{
public:
	BoxCollider(Vector dot1, Vector dot2);
	~BoxCollider();

	void Update();
	void Render(HDC hdc);

private:
	Vector _dot1;
	Vector _dot2;
};

