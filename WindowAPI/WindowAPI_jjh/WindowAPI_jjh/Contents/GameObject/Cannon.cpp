#include "framework.h"
#include "Cannon.h"

Cannon::Cannon()
	:_barrelAngle(0.0f)
{
	_body = make_shared<CircleCollider>(Vector(350, 350), 50);
	_barrel = make_shared<Line>(_body->Center(), _body->Center() + Vector(150, 0));
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	InputMove();
	InputBarrelRotation();

	// �ѽ� ����
	_barrel->_start = _body->Center();
	//_barrel->_end = _body->Center() + Vector(150, 0);

	_body->Update();
	_barrel->Update();
}

void Cannon::Render(HDC hdc)
{
	_barrel->Render(hdc);
	_body->Render(hdc);
}

void Cannon::InputMove()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8001)
	{
		_body->Center().x -= 3;
		_barrel->_end = _barrel->_end - Vector(3, 0);
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
	{
		_body->Center().x += 3;
		_barrel->_end = _barrel->_end + Vector(3, 0);
	}
}

void Cannon::InputBarrelRotation()
{
	// TODO : ����Ű ���� ������ �ѽ��� ������ +�� �ǰ�
	// ����Ű �Ʒ��� ������ �ѽ��� ������ -�� �ǰ��ϱ�.
	if (GetAsyncKeyState(VK_UP) & 0x8001)
	{
		_barrelAngle -= 0.01f;
		Vector newEnd = Vector(cos(_barrelAngle), sin(_barrelAngle)) * 150;
		_barrel->_end = _body->Center() + newEnd;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8001)
	{
		_barrelAngle += 0.01f;
		Vector newEnd = Vector(cos(_barrelAngle), sin(_barrelAngle)) * 150;
		_barrel->_end = _body->Center() + newEnd;
	}
}