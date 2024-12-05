#pragma once
class Line 
{
public:
	Line(Vector start, Vector end);
	~Line();

	Vector& End() { return _end; }

	void Update();
	void Render(HDC hdc);

	void SetRed() { _curColor = 0; }
	void SetGreen() { _curColor = 1; }

	bool IsCollision(shared_ptr<Line> other);


public:
	Vector _start;
	Vector _end;
	Vector _cross;

	HPEN _colors[2];
	int _curColor = 1;
};

