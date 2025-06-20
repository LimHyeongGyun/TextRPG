#include "Monster.h"

Goblin::Goblin(int level) {
	name = "Goblin";

	health = getRandomInRange(level * 20, level * 30);
	attack = getRandomInRange(level * 5, level * 10);
}
string Goblin::getName() const {
	return name;
}

int Goblin::getHealth() const {
	return health;
}

int Goblin::Attack() const {
	return attack;
}

void Goblin::takeDamage(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}