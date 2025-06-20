#include "Monster.h"
#include <vector>

Goblin::Goblin(int level) {
	name = "Goblin";

	int baseMinHp = level * 20;
	int baseMaxHp = level * 30;

	int baseMinAtk = level * 5;
	int baseMaxAtk = level * 10;

	health = getRandomInRange(baseMinHp, baseMaxHp);
	attack = getRandomInRange(baseMinAtk, baseMaxAtk);

	expDrop = 50;
	goldDrop = getRandomInRange(10, 20);

	vector<string> possibleItems = { "고블린 이빨", "화려한 금화 자루(10G)" };
	itemDrop = possibleItems[getRandomInRange(0, possibleItems.size() - 1)];
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

int Goblin::getExpDrop() const {
	return expDrop;
}

int Goblin::getGoldDrop() const {
	return goldDrop;
}

string Goblin::getItemDrop() const {
	return itemDrop;
}