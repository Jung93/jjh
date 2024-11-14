#pragma once
class Player : public Creature
{
public:
	Player();
	Player(string name, int hp, int atk, float criRate);
	~Player();

};

