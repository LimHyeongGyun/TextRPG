#include "Monster.h"

Orc::Orc(int level) {
	name = "Orc";

	health = getRandomInRange(level * 20, level * 30);
	attack = getRandomInRange(level * 5, level * 10);
}
string Orc::getName() const {
	return name;
}

int Orc::getHealth() const {
	return health;
}

int Orc::Attack() const {
	return attack;
}

void Orc::takeDamage(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}