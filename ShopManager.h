#pragma once

#include <string>
#include <vector>

using namespace std;

class Character;
class Monster;
class Item;

class GameManager {
public:
	Character* player;
	Monster* GenerateMonster(int level);
	void Battle(Character* character, Monster* monster);
	void DisplayInventory(Character* character);

};

class Inventory {
private:
	vector<Item*>item;


public:
	void AddItem(Item* item);
	void ShowInventory();
};