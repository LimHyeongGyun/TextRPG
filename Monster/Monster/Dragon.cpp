#include "Monster.h"
#include <vector>

Dragon::Dragon(int level) {
	name = "Dragon";

	int baseMinHp = level * 20;
	int baseMaxHp = level * 30;

	int baseMinAtk = level * 5;
	int baseMaxAtk = level * 10;

	health = getRandomInRange(baseMinHp, baseMaxHp) * 1.5;
	attack = getRandomInRange(baseMinAtk, baseMaxAtk) * 1.5;

	expDrop = 50;
	goldDrop = getRandomInRange(10, 20);
	
	vector<string> possibleItems = { "드래곤 심장", "전설의 금화 상자(1000G)" };
	itemDrop = possibleItems[getRandomInRange(0, possibleItems.size() - 1)];
}
string Dragon::getName() const {
	return name;
}

int Dragon::getHealth() const {
	return health;
}

int Dragon::Attack() const {
	return attack;
}

void Dragon::takeDamage(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}

int Dragon::getExpDrop() const {
	return expDrop;
}

int Dragon::getGoldDrop() const {
	return goldDrop;
}

string Dragon::getItemDrop() const {
	return itemDrop;
}