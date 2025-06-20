#include "Monster.h"

Slime::Slime(int level) {
	name = "Slime";

	health = getRandomInRange(level * 20, level * 30);
	attack = getRandomInRange(level * 5, level * 10);
}
string Slime::getName() const {
	return name;
}

int Slime::getHealth() const {
	return health;
}

int Slime::Attack() const {
	return attack;
}

void Slime::takeDamage(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}