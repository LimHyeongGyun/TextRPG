#include "Item.h"
#include "Character.h"


class MonsterItem :public Item {
public:
	std::string name;
	MonsterItem(const std::string& name, int value) :name(name)
	{
		this->value = value;
		//���� ����
	}
	std::string getName() const override { return name; }

	void Use(Character* character) override {
		// ������
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

	std::string getName() const override { return name; }//�̸� ��ȯ

	void Use(Character* character) override
	{
		if (character)		//��� ���� üũ �� ȿ�� ����

		{
			character->RecoveryHP(heal);//ü�� ȸ��
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
		// ������
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
		// ������
	}

};

