#pragma once
class Knight : public Player
{
public:
	Knight();
	Knight(string name, int hp, int atk, float criRate);
	~Knight();

	//virtual void Attack(class Creature* creature) override;
	virtual void Attack(shared_ptr<Creature> creature) override;



};

