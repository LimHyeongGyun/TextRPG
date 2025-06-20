#include "Monster.h"
#include "Dragon.h"
#include <vector>

Dragon::Dragon(int level) {
	name = "Dragon";
	alive = true;

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
	if (health < 0) {
		health = 0;
		alive = false;
	}
}

int Monster::getExpDrop() const {
	if (alive) return 0;
	return expDrop;
}

int Monster::getGoldDrop() const {
	if (alive) return 0;
	return goldDrop;
}

string Monster::getItemDrop() const {
	if (alive) return "";
	return itemDrop;
}

bool Monster::IsAlive() {
	return alive;
}

float Dragon::getMultiplyHp() const {
	return 1.5;
}

float Dragon::getMultiplyAtk() const {
	return 1.5;
}