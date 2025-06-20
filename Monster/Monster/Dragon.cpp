#include "Monster.h"
#include "Dragon.h"
#include <vector>

Dragon::Dragon(int level) {
	name = "Dragon";

	int baseMinHp = level * 20;
	int baseMaxHp = level * 30;

	int baseMinAtk = level * 5;
	int baseMaxAtk = level * 10;

	health = getRandomInRange(baseMinHp, baseMaxHp) * getMultiplyHp();
	attack = getRandomInRange(baseMinAtk, baseMaxAtk) * getMultiplyAtk();

	expDrop = 50;
	goldDrop = getRandomInRange(10, 20);
	
	vector<string> possibleItems = { "드래곤 심장", "전설의 금화 상자(1000G)" };
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

float Dragon::getMultiplyHp() const {
	return 1.5;
}

float Dragon::getMultiplyAtk() const {
	return 1.5;
}