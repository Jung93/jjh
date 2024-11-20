#pragma once
class Line
{
public:
	Line(Vector start, Vector end);
	~Line();

	Vector& End() { return _end; }

	void Update();
	void Render(HDC hdc);

public:
	Vector _start;
	Vector _end;
};

