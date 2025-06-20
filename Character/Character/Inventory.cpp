#include "Inventory.h"

Inventory* Inventory::iveninstance = nullptr;

Character* character = Character::GetInstance();

Inventory* Inventory::GetInstance(string name) {
    if (iveninstance == nullptr)
    {
        iveninstance = new Inventory(); //캐릭터 생성해주기
    }

    return iveninstance;
}

void Inventory::ClassificationItem(Item* item, int num) {

}

void Inventory::EquipWeapon(Item* weapon) {
    weapon->equip = true;

    //무기가 비어있을 때
    if (character->GetEquipWeapon() == nullptr)
    {
        character->SetEquipWeapon(weapon);
        character->EquipStatus(weapon->attack, 0);
    }
    else
    {
        //기본 무기해제
        UnEquipWeapon();
        character->UnEquipStatus(character->GetEquipWeapon()->attack, 0);

        //새로운 무기 장착
        character->SetEquipWeapon(weapon);
        character->EquipStatus(weapon->attack, 0);
    }
}
void Inventory::EquipArmor(Item* armor) {
    armor->equip = true;
    //방어구가 비어있을 때
    if (character->GetEquipArmor() == nullptr)
    {
        character->SetEquipArmor(armor);
        character->EquipStatus(0, armor->health);
    }
    else
    {
        //기존 방어구 해제
        UnEquipArmor();
        character->UnEquipStatus(0, character->GetEquipArmor()->health); //기존 장비 해제 스탯변경

        //새로운 방어구 장착
        character->SetEquipArmor(armor);
        character->EquipStatus(0, armor->health);
    }
}
void Inventory::UnEquipWeapon() {
    character->GetEquipWeapon()->equip = false;
}
void Inventory::UnEquipArmor() {
    character->GetEquipArmor()->equip = false;
}