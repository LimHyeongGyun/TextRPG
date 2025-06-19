#pragma once

#include <string>
#include <vector>

#include "Item.h"

using namespace std;

class Character {
private:
	static Character* instance;
	string name; //플레이어 이름
	int level = 0; //레벨
	int health = 0; //현재 체력
	int maxHealth = 0; //최대 체력
	int attack = 0; //공격력
	int experience = 0; //경험치
	int gold = 0; //소지 골드
	vector<Item*> inventory; //아이템 저장할 인벤토리
public:
	static Character* GetInstance(string name = " ");
	void DisplayStatus();
	void LevelUp();
	void UseItem(int index);
	void VisitShop(); //Shop과 상호작용
};