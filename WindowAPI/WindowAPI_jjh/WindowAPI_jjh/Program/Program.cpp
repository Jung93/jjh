#include "framework.h"
#include "Program.h"

#include "Scenes/PaintScene.h"
#include "Scenes/CollisionScene.h"
#include "Scenes/CannonScene.h"
#include "Scenes/LineScene.h"

Program::Program()
{
    _sceneTable["PaintScene"] = make_shared<PaintScene>();
    _sceneTable["CollisionScene"] = make_shared<CollisionScene>();
    _sceneTable["CannonScene"] = make_shared<CannonScene>();
    _sceneTable["LineScene"] = make_shared<LineScene>();

    //_curScene = "PaintScene";
    _curScene = "LineScene";
}

Program::~Program()
{
}

void Program::Update()
{
    _sceneTable[_curScene]->Update();


}

void Program::Render(HDC hdc)
{
    _sceneTable[_curScene]->Render(hdc);



}
