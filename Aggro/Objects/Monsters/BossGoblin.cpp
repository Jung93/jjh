#include "../../Framework.h"
#include "BossGoblin.h"

BossGoblin::BossGoblin() {};

BossGoblin::BossGoblin(string name, int hp, int atk, float criRate): Goblin(name, hp, atk, criRate) {};

BossGoblin::~BossGoblin() {};

void BossGoblin::SetDealAmounts(string key, int value)
{
	if (dealAmounts.find(key) == dealAmounts.end())
	{
		dealAmounts.insert(make_pair(key, value));
	}
	else 
	{
		int deal = dealAmounts.find(key)->second + value;
		dealAmounts.at(key) = deal;
	}
}
unordered_map<string, int> BossGoblin::GetDealAmounts() { return dealAmounts; };

void BossGoblin::DeleteDealAmounts(shared_ptr<Creature> creasture) 
{
	if (creasture->IsDead())
	{
		dealAmounts.erase(creasture->GetName());

	}
}


vector<pair<string, int>> BossGoblin::SortByDealAmounts()
{
	vector<pair<string, int>> vec(dealAmounts.begin(), dealAmounts.end());

	sort(vec.begin(), vec.end(), [](const pair<string, int> pair1, const pair<string, int> pair2)-> bool
		{
			if (pair1.second > pair2.second)
				return true;
			return false;
		});

	return vec;
}
