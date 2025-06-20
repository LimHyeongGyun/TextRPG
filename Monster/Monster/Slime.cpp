#include "Monster.h"
#include <vector>

Slime::Slime(int level) {
	name = "Slime";

	int baseMinHp = level * 20;
	int baseMaxHp = level * 30;

	int baseMinAtk = level * 5;
	int baseMaxAtk = level * 10;

	health = getRandomInRange(baseMinHp, baseMaxHp);
	attack = getRandomInRange(baseMinAtk, baseMaxAtk);

	expDrop = 50;
	goldDrop = getRandomInRange(10, 20);

	vector<string> possibleItems = { "끈적한 점액", "구겨진 동전 주머니(1G)" };
	itemDrop = possibleItems[getRandomInRange(0, possibleItems.size() - 1)];
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

int Slime::getExpDrop() const {
	return expDrop;
}

int Slime::getGoldDrop() const {
	return goldDrop;
}

string Slime::getItemDrop() const {
	return itemDrop;
}