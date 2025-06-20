#include "Monster.h"
#include "Orc.h"
#include <vector>

Orc::Orc(int level) {
	name = "Orc";

	int baseMinHp = level * 20;
	int baseMaxHp = level * 30;

	int baseMinAtk = level * 5;
	int baseMaxAtk = level * 10;

	health = getRandomInRange(baseMinHp, baseMaxHp);
	attack = getRandomInRange(baseMinAtk, baseMaxAtk);

	expDrop = 50;
	goldDrop = getRandomInRange(10, 20);

	vector<string> possibleItems = { "오크족 전투 휘장", "무게감 있는 주머니(3G)"};
	itemDrop = possibleItems[getRandomInRange(0, possibleItems.size() - 1)];
}
string Monster::getName() const {
	return name;
}

int Monster::getHealth() const {
	return health;
}

int Monster::Attack() const {
	return attack;
}

void Monster::takeDamage(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}

int Monster::getExpDrop() const {
	return expDrop;
}

int Monster::getGoldDrop() const {
	return goldDrop;
}

string Monster::getItemDrop() const {
	return itemDrop;
}

bool Monster::IsAlive() {
	if (health > 0) return true;
	else return false;
}