#include "Monster.h"

BossMonster::BossMonster(int level) {
	name = "BossMonster";

	health = getRandomInRange(level * 20, level * 30) * 1.5;
	attack = getRandomInRange(level * 5, level * 10) * 1.5;
}
string BossMonster::getName() const {
	return name;
}

int BossMonster::getHealth() const {
	return health;
}

int BossMonster::Attack() const {
	return attack;
}

void BossMonster::takeDamage(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}