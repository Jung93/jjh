#pragma once
class Creature
{
public:
	Creature();
	Creature(string name, int hp, int atk, float criRate);
	~Creature();

	void TakeDamage(int atk);
	//virtual void Attack(class Creature* creature);
	virtual void Attack(shared_ptr<Creature> creature);

	string GetName();
	int GetHp();
	int GetMaxHp();
	int GetAtk();
	float GetCriRate();

	float GetDamageRange();
	bool CheckCritical();
	bool IsHalfHp();
	bool IsDead();

	void PrintInfo();

private:
	string _name;
	int _hp;
	int _maxHp;
	int _atk;
	float _criRate;

};

