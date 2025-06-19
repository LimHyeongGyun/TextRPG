#include "Item.h"
#include "Character.h"

class HealingPotion :public Item {
	int itemnum = 1;
	std::string getName() const override {return "Healing Potion"; }//이름 반환
	void Use(Character* character) override
	{
		//사용 조건 체크 및 효과 적용
		if (character)
		{
				character->RecoveryHP(50);
		}
	}
};

class GreateHealingPotion :public Item {
	std::string getName() const override { return "Greate Healing Potion"; }//이름 반환
	int itemnum = 2;
	void Use(Character* character) override
	{
		//사용 조건 체크 및 효과 적용

		if (character)
		{
			character->RecoveryHP(100);

		}
	}
};

