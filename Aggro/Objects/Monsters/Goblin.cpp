#include "../../Framework.h"
#include "Goblin.h"

Goblin::Goblin(){}

Goblin::Goblin(string name, int hp, int atk, float criRate) : Monster(name, hp, atk, criRate) {}

Goblin::~Goblin() {}