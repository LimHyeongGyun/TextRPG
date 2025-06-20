#include "Item.h"
#include "Character.h"




class MonsterItem :public Item {
public:
	std::string name;
	MonsterItem(const std::string& name, int value) :name(name)
	{
		this->value = value;
		//가격 결정
	}
	std::string getName() const override { return name; }

	void Use(Character* character) override {
		// 구현부
	}
};

class HealingPotion :public Item {
protected:
	int heal;
	std::string name;
public:
	HealingPotion(const std::string& name, int heal, int value) :name(name), heal(heal) {
		this->value = value;
	};

	std::string getName() const override { return name; }//이름 반환

	void Use(Character* character) override
	{
		if (character)		//사용 조건 체크 및 효과 적용

		{
			character->RecoveryHP(heal);//체력 회복
		}
	}
};

class Armor : public Item {
public:
	bool equip = false;
	int health;
	std::string name;

	Armor(const std::string& armor_name, int defense_value, int value)
		: name(armor_name), health(defense_value) {
		this->value = value;
	}

	std::string getName() const override { return name; }
	void Use(Character* character) override {
		// 구현부
	}
};

class Weapon : public Item {
public:
	std::string name;
	int attack;
	bool equip = false;
	Weapon(const std::string& weapon_name, int atack_value, int value)
		: name(weapon_name), attack(atack_value) {
		this->value = value;
	};

	std::string getName() const override { return name; }
	void Use(Character* character) override {
		// 구현부
	}

};