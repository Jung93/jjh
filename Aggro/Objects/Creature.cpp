#include "../Framework.h"
#include "Creature.h"


Creature::Creature() : _name(""), _hp(0), _maxHp(0) , _atk(0), _criRate(0.0f) {}
Creature::Creature(string name, int hp, int atk, float criRate) : _name(name), _hp(hp), _maxHp(hp), _atk(atk), _criRate(criRate) {}
Creature::~Creature() {}

string Creature::GetName() { return _name; }
int Creature::GetHp() { return _hp; }
int Creature::GetMaxHp() { return _maxHp; }
int Creature::GetAtk() { return _atk; }
float Creature::GetCriRate() { return _criRate; }


void Creature::TakeDamage(int atk)
{
	_hp -= atk;
	if (_hp <= 0) _hp = 0;
}

//void Creature::Attack(class Creature* creature)
//{
//	creature->TakeDamage(_atk);
//}

void Creature::Attack(shared_ptr<Creature> creature)
{
	creature->TakeDamage(_atk);
}


float Creature::GetDamageRange() 
{
	float damageRange = (((rand() % 11) + 5) / static_cast<float>(100)) + 0.9f;

	return damageRange;
}

bool Creature::CheckCritical() 
{
	float criticalRange = ((rand() % 11) / static_cast<float>(10));

	if (_criRate >= criticalRange)
		return true;
	return false;
}

bool Creature::IsHalfHp()
{
	if (_hp / (float)_maxHp <= 0.5f)
		return true;
	return false;
}

bool Creature::IsDead()
{
	if (_hp <= 0)
		return true;
	return false;
}


void Creature::PrintInfo() 
{
	cout << "Name : " << _name << ", Hp : " << _hp << ", MaxHp : " << _maxHp << ", Atk : " << _atk << ", CriRate : " << _criRate << endl;
}
