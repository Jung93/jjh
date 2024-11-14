#include "../../Framework.h"
#include "Player.h"

Player::Player() : Creature(){}

Player::Player(string name, int hp, int atk, float criRate) : Creature(name, hp, atk, criRate) {}

Player::~Player() {}