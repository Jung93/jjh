#pragma once
class Archer : public Player
{
public:
	Archer();
	Archer(string name, int hp, int atk, float criRate);
	~Archer();

	//virtual void Attack(class Creature* creature) override;
	virtual void Attack(shared_ptr<Creature> creature) override;

};

