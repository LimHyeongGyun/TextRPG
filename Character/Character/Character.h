#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string>
#include <vector>

#include "Item.h"

using namespace std;

class Character {
private:
	static Character* instance;

	string name; //플레이어 이름
	int level = 1; //레벨
	int maxLevel = 10;
	int health = 0; //현재 체력
	int maxHealth = 0; //최대 체력
	int attack = 0; //공격력
	int experience = 0; //경험치
	int needExperience = 100;
	int gold = 0; //소지 골드

	vector<Item*> inventory; //아이템 저장할 인벤토리
	Item* equipWeapon;
	Item* equipArmor;

	void UpgradeStatus(); //레벨업 했을 때 스탯 업그레이드
	void LevelUp(); //레벨업

public:
	Character();
	static Character* GetInstance(string name = " "); //싱글턴 인스턴스
	void DisplayStatus(); //플레이어의 현재 스탯 확인

	//전투 관련
	void DecreaseHP(int damage); //피격시
	void RecoveryHP(int health); //체력 회복
	void GetExperience(int experience); //경험치 획득 -> 몬스터 처치시 몬스터의 사망로직에서 호출하여 사용
	void GetItem(Item* item);
	void Die();

	void UseItem(int index); //아이템 사용
	void EquipWeapon(Item* weapon); //무기 장착
	void EquipArmor(Item* armor); //방어구 장착
	void UnEquipWeapon(); //무기 해제
	void UnEquipArmor(); //방어구 해제

	void VisitShop(); //Shop과 상호작용
	static void ReleaseInstance(); //메모리 해제
};

#endif