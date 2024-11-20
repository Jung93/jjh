#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
    _pens.reserve(3);
    {
        _pens.push_back(CreatePen(3, 3, RGB(255, 0, 0)));
        _pens.push_back(CreatePen(3, 3, RGB(0, 255, 0)));
        _pens.push_back(CreatePen(3, 3, RGB(0, 0, 255)));

    }

    _brushes.reserve(3);
    {
        _brushes.push_back(CreateSolidBrush(RGB(255, 0, 0)));
        _brushes.push_back(CreateSolidBrush(RGB(0, 255, 0)));
        _brushes.push_back(CreateSolidBrush(RGB(0, 0, 255)));
    }

    myCircle->SetRed();
    myBox->SetGreen();

}

PaintScene::~PaintScene()
{
    for (auto pen : _pens)
        DeleteObject(pen);

    for (auto brush : _brushes)
        DeleteObject(brush);
}


void PaintScene::Update()
{
    myBox->Center() = LinearInterpolation(myBox->Center(), mousePos, 0.1f);


    myCircle->Update();
    myBox->Update();
    myLine->Update();
}

void PaintScene::Render(HDC hdc)
{
    SelectObject(hdc, _pens[_curColor]);
    //SelectObject(hdc, _brushes[_curColor]);

    ////타원
//Ellipse(hdc, 0, 0, 100, 100);
//myCircle->Center() = mousePos;
    myCircle->Render(hdc);



    ////사각형
    //Rectangle(hdc, 0, 0, 100, 100);
    myBox->Render(hdc);
    //선형 보관. 애니메이션을 만드는 기법 중 하나
    //myBox->Center() = myBox->Center() + (mousePos - myBox->Center()) * 0.1f;

    //myBox->Center() = mousePos;
    myBox->Render(hdc);


    ////선
    //MoveToEx(hdc, 500, 500, nullptr);
    //LineTo(hdc, 700, 700);
    //myLine->End() = mousePos;
    myLine->Render(hdc);
}
