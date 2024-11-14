#include "Framework.h"

int main()
{
	srand(time(NULL));


	vector<shared_ptr<Creature>> vPlayers;

	for (int i = 0; i < 10; i++)
	{
		int playerSelect = rand() % 3;
		
		switch (playerSelect)
		{
			case 0:
			{
				//Knight* knight = new Knight("knight" + to_string(i + 1), 350, 150, 0.5f);
				shared_ptr<Creature> knight = make_shared<Knight>("knight" + to_string(i + 1), 350, 150, 0.5f);
				vPlayers.push_back(knight);
				break;
			}

			case 1:
			{
				//Mage* mage = new Mage("mage" + to_string(i + 1), 150, 300, 0.2f);
				shared_ptr<Creature> mage = make_shared<Mage>("mage" + to_string(i + 1), 150, 300, 0.2f);
				vPlayers.push_back(mage);
				break;
			}

			case 2:
			{
				//Archer* archer = new Archer("archer" + to_string(i + 1), 100, 300, 0.8f);
				shared_ptr<Creature> archer = make_shared<Archer>("archer" + to_string(i + 1), 100, 300, 0.8f);
				vPlayers.push_back(archer);
				break;
			}
		}
	}


	//BossGoblin* bobo = new BossGoblin("bobo", 13000, 100, 0.0f);

	shared_ptr<BossGoblin> bobo = make_shared<BossGoblin>("bobo", 13000, 100, 0.0f);

	bool isEnd = false;
	while (true) 
	{
	
		for (int i = 0; i < vPlayers.size(); i++)
		{
			if (!vPlayers[i]->IsDead())
			{
				vPlayers[i]->Attack(bobo);
				std::cout << "bobo's remain Hp : " << bobo->GetHp() << endl;
				std::cout << endl;
			}
			else
			{
				bobo->DeleteDealAmounts(vPlayers[i]);
			}
		}



		vector<pair<string, int>> vv = bobo->SortByDealAmounts();
		//for (int i = 0; i < vv.size(); i++)
		//{
		//	cout << vv[i].first << ", " << vv[i].second << endl;
		//}


		for (int i = 0; i < 4; i++)
		{
			if (i >= vv.size())
				break;

			string playerName = vv[i].first;

			vector<shared_ptr<Creature>>::iterator iter = find_if(vPlayers.begin(), vPlayers.end(), [playerName](shared_ptr<Creature> p)->bool
				{
					if (p->GetName() == playerName)
						return true;
					return false;
				});

			std::cout << "No." << (i + 1) << " Dealer : " << vv[i].first << ", Total Deal : " << vv[i].second << endl;
			
			//shared_ptr<Creature> c = make_shared<Creature>(*iter);


			//bobo->Attack(make_shared<Creature>(*iter));
		}

		std::cout << "bobo's attack!" << endl;

		for (int i = 0; i < vPlayers.size(); i++)
		{
			vPlayers[i]->PrintInfo();
		}


		std::cout << "----------------------------" << endl;

		isEnd = all_of(vPlayers.begin(), vPlayers.end(), [](shared_ptr<Creature> player)->bool
			{
				if (player->IsDead())
					return true;
				return false;

			});

		if(isEnd) break;
		if (bobo->IsDead()) break;

	}

	



	for (int i = 0; i < vPlayers.size(); i++)
		vPlayers[i]->PrintInfo();

	bobo->PrintInfo();


	//delete bobo;
	//
	//for (int i = 0; i < vPlayers.size(); i++)
	//	delete vPlayers[i];


}

