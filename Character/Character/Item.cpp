#include "Item.h"
#include "Character.h"






class HealingPotion :public Item {
	int itemnum = 1;
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
	int itemnum = 2;

	std::string getName() const override { return "Greate Healing Potion"; }//�̸� ��ȯ

	void Use(Character* character) override
	{

		if (character)		//��� ���� üũ �� ȿ�� ����

		{
			character->RecoveryHP(100);//ä�� 100ȸ��

		}
	}
};

class Armor:public Item {
public:
	bool isequip = false;
	int df; // ��� ������ �������� ���� ���� ��

	// Armor�� ������: df ���� �޾� �ʱ�ȭ�մϴ�.
	Armor(int defense_value = 0) : df(defense_value) {}
	std::string getName() const override { return "����"; }//�̸� ��ȯ
	void Use(Character* character) override {}
};

class woodArmor :public Armor {
	woodArmor() : Armor(10) {}
	std::string getName() const override { return "��������"; }

};
class IronArmor :public Armor {
	IronArmor() : Armor(50) {}
	std::string getName() const override { return "ö����"; }

};
class DiamondArmor :public Armor {
	DiamondArmor() : Armor(100) {}
	std::string getName() const override { return "���̾Ƹ�尩��"; }

};

class Weapon : public Item {
public:
	bool isequip = false;
	std::string getName() const override { return "����"; }
	void Use(Character* character) override {}


};

