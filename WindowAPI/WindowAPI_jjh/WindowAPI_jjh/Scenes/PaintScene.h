#pragma once
class PaintScene : public Scene
{
public:
	PaintScene();
	~PaintScene();

	void Update() override;
	void Render(HDC hdc) override;

private:
	int _curColor = 0;

	vector<HPEN> _pens;
	vector<HBRUSH> _brushes;

	shared_ptr<CircleCollider> myCircle = make_shared<CircleCollider>(Vector(100, 100), 70);
	shared_ptr<BoxCollider> myBox = make_shared<BoxCollider>(Vector(200, 200), Vector(140, 140));
	shared_ptr<Line> myLine = make_shared<Line>(Vector(500, 500), Vector(700, 700));
};

