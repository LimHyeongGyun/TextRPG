#include "Item.h"
#include "Character.h"






class HealingPotion :public Item {
	int itemnum = 1;
	bool expendables = true;
	std::string getName() const override {return "Healing Potion"; }//이름 반환
	void Use(Character* character) override
	{
		if (character)		//사용 조건 체크 및 효과 적용

		{
				character->RecoveryHP(50);//체력 50회복
		}
	}
};

class GreateHealingPotion :public Item {

	bool expendables = true;
	int itemnum = 2;

	std::string getName() const override { return "Greate Healing Potion"; }//이름 반환

	void Use(Character* character) override
	{

		if (character)		//사용 조건 체크 및 효과 적용

		{
			character->RecoveryHP(100);//채력 100회복

		}
	}
};

class Armor:public Item {
public:
	bool isequip = false;
	int df; // 모든 갑옷이 공통으로 가질 방어력 값

	// Armor의 생성자: df 값을 받아 초기화합니다.
	Armor(int defense_value = 0) : df(defense_value) {}
	std::string getName() const override { return "갑옷"; }//이름 반환
	void Use(Character* character) override {}
};

class woodArmor :public Armor {
	woodArmor() : Armor(10) {}
	std::string getName() const override { return "나무갑옷"; }

};
class IronArmor :public Armor {
	IronArmor() : Armor(50) {}
	std::string getName() const override { return "철갑옷"; }

};
class DiamondArmor :public Armor {
	DiamondArmor() : Armor(100) {}
	std::string getName() const override { return "다이아몬드갑옷"; }

};

class Weapon : public Item {
public:
	bool isequip = false;
	std::string getName() const override { return "무기"; }
	void Use(Character* character) override {}


};

