#include "framework.h"
#include "LineScene.h"

LineScene::LineScene()
{
	_line1 = make_shared<Line>(Vector(100, 100), Vector(0, 0));
	_line3 = make_shared<Line>(Vector(100, 400), Vector(800, 100));
}

LineScene::~LineScene()
{
}

void LineScene::Update()
{
	_line1->_end = mousePos;

	_line1->Update();
	_line3->Update();
	
	if (_line3->IsCollision(_line1))
	{
		_line3->SetRed();
	}
	else
	{
		_line3->SetGreen();
	}
}

void LineScene::Render(HDC hdc)
{
	_line1->Render(hdc);
	_line3->Render(hdc);
}
