#pragma once
class BossGoblin : public Goblin
{
public:
	BossGoblin();
	BossGoblin(string name, int hp, int atk, float criRate);
	~BossGoblin();

	void SetDealAmounts(string key, int value);
	unordered_map<string, int> GetDealAmounts();
	void DeleteDealAmounts(shared_ptr<Creature> creature);
	vector<pair<string, int>> SortByDealAmounts();


private:
	unordered_map<string, int> dealAmounts;
};

