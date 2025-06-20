#include "Monster.h"

Troll::Troll(int level) {
	name = "Troll";

	health = getRandomInRange(level * 20, level * 30);
	attack = getRandomInRange(level * 5, level * 10);
}
string Troll::getName() const {
	return name;
}

int Troll::getHealth() const {
	return health;
}

int Troll::Attack() const {
	return attack;
}

void Troll::takeDamage(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}