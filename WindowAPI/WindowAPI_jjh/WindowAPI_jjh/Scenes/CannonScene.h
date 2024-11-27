#pragma once
class CannonScene : public Scene
{
public:
	CannonScene();
	~CannonScene();

	void Update();
	void Render(HDC hdc);

private:
	shared_ptr<Cannon> _cannon;

};

