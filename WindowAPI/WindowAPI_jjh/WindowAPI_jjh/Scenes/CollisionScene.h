#pragma once
class CollisionScene : public Scene
{
public:
	CollisionScene();
	~CollisionScene();

	void Update() override;
	void Render(HDC hdc) override;

private:
	shared_ptr<Collider> _myCircle;
	shared_ptr<Collider> _myMovingCircle;

	shared_ptr<Collider> _myBox;
};

