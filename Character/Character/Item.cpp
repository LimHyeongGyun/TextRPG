#include "Item.h"
#include "Character.h"






class HealingPotion :public Item {
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

	std::string getName() const override { return "Greate Healing Potion"; }//이름 반환

	void Use(Character* character) override
	{

		if (character)		//사용 조건 체크 및 효과 적용

		{
			character->RecoveryHP(100);//채력 100회복

		}
	}
};

class Armor : public Item {
public:
	bool isequip = false;
	int df;
	std::string name;

	Armor(const std::string& armor_name, int defense_value)
		: name(armor_name), df(defense_value) {
	}

	std::string getName() const override { return name; }
	void Use(Character* character) override {
		// 구현부
	}
};

class Weapon : public Item {
public:
	std::string name;
	int at;
	bool isequip = false;
	Weapon(const std::string& weapon_name,int atack_value)
		: name(weapon_name),at(atack_value) {
	};

	std::string getName() const override { return name; }
	void Use(Character* character) override {
		// 구현부
	}

};



