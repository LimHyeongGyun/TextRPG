#include "Item.h"
#include "Character.h"






class HealingPotion :public Item {
	bool expendables = true;
	std::string getName() const override {return "Healing Potion"; }//�̸� ��ȯ
	void Use(Character* character) override
	{
		if (character)		//��� ���� üũ �� ȿ�� ����

		{
				character->RecoveryHP(50);//ü�� 50ȸ��
		}
	}
};

class GreateHealingPotion :public Item {

	bool expendables = true;

	std::string getName() const override { return "Greate Healing Potion"; }//�̸� ��ȯ

	void Use(Character* character) override
	{

		if (character)		//��� ���� üũ �� ȿ�� ����

		{
			character->RecoveryHP(100);//ä�� 100ȸ��

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
		// ������
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
		// ������
	}

};



