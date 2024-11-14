#include "../../Framework.h"
#include "Monster.h"

Monster::Monster(): Creature() {}

Monster::Monster(string name, int hp, int atk, float criRate): Creature(name, hp, atk, criRate) {}

Monster::~Monster() {}


