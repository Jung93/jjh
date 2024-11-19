#pragma once
class Line
{
public:
	Line(Vector start, Vector end);
	~Line();

	void Update();
	void Render(HDC hdc);

private:
	Vector _start;
	Vector _end;
};

