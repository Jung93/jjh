#include "../../Framework.h"
#include "Mage.h"

Mage::Mage() {}

Mage::Mage(string name, int hp, int atk, float criRate) : Player(name, hp, atk, criRate) {}

Mage::~Mage() {}

void Mage::Attack(shared_ptr<Creature> creature)
{
	int finalDamage = GetAtk() * GetDamageRange();

	if (CheckCritical()) 
	{
		finalDamage *= 2;
		cout << GetName() << "'s critical attack!!" << endl;
	}
	else 
	{
		cout << GetName() << "'s attack!" << endl;
	}

	if (IsHalfHp())
		finalDamage *= 2;

	creature->TakeDamage(finalDamage);
	shared_ptr<BossGoblin> boss = dynamic_pointer_cast<BossGoblin>(creature);


	boss->SetDealAmounts(GetName(), finalDamage);

}