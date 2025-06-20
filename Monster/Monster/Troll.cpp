#include "Monster.h"
#include <vector>

Troll::Troll(int level) {
	name = "Troll";

	int baseMinHp = level * 20;
	int baseMaxHp = level * 30;

	int baseMinAtk = level * 5;
	int baseMaxAtk = level * 10;

	health = getRandomInRange(baseMinHp, baseMaxHp);
	attack = getRandomInRange(baseMinAtk, baseMaxAtk);

	expDrop = 50;
	goldDrop = getRandomInRange(10, 20);

	vector<string> possibleItems = { "트롤 가죽", "묵직한 금화 주머니(5G)" };
	itemDrop = possibleItems[getRandomInRange(0, possibleItems.size() - 1)];
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

int Troll::getExpDrop() const {
	return expDrop;
}

int Troll::getGoldDrop() const {
	return goldDrop;
}

string Troll::getItemDrop() const {
	return itemDrop;
}