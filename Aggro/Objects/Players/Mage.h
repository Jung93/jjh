#pragma once
class Mage : public Player
{
public:
	Mage();
	Mage(string name, int hp, int atk, float criRate);
	~Mage();

	//virtual void Attack(class Creature* creature) override;
	virtual void Attack(shared_ptr<Creature> creature) override;


};

