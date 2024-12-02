#pragma once
class Barrel
{
public:
	Barrel();
	~Barrel();

	void Update();
	void Render(HDC hdc);

	void SetCannon(shared_ptr<class Cannon> cannon) { _cannon = cannon; }
	void SetDirection(Vector dir) { _direction = dir; }
	Vector GetDirection() { return _direction; }
	Vector GetEnd() { return _line->End(); }

private:
	shared_ptr<Line> _line;

	float _length = 150.f;
	Vector _direction;

	//�ܺο��� ������ ���� �����ϰ� ���� ���� weak_ptr ����
	weak_ptr<class Cannon> _cannon;
};
