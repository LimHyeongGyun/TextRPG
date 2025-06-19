#include "Item.h"
#include "Character.h"

class HealingPotion :public Item {
	int itemnum = 1;
	std::string getName() const override {return "Healing Potion"; }//�̸� ��ȯ
	void Use(Character* character) override
	{
		//��� ���� üũ �� ȿ�� ����
		if (character)
		{
				character->RecoveryHP(50);
		}
	}
};

class GreateHealingPotion :public Item {
	std::string getName() const override { return "Greate Healing Potion"; }//�̸� ��ȯ
	int itemnum = 2;
	void Use(Character* character) override
	{
		//��� ���� üũ �� ȿ�� ����

		if (character)
		{
			character->RecoveryHP(100);

		}
	}
};

