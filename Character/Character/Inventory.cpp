#include "Inventory.h"

Inventory* Inventory::iveninstance = nullptr;

Character* character = Character::GetInstance();

Inventory* Inventory::GetInstance(string name) {
    if (iveninstance == nullptr)
    {
        iveninstance = new Inventory(); //ĳ���� �������ֱ�
    }

    return iveninstance;
}

void Inventory::ClassificationItem(Item* item, int num) {

}

void Inventory::EquipWeapon(Item* weapon) {
    weapon->equip = true;

    //���Ⱑ ������� ��
    if (character->GetEquipWeapon() == nullptr)
    {
        character->SetEquipWeapon(weapon);
        character->EquipStatus(weapon->attack, 0);
    }
    else
    {
        //�⺻ ��������
        UnEquipWeapon();
        character->UnEquipStatus(character->GetEquipWeapon()->attack, 0);

        //���ο� ���� ����
        character->SetEquipWeapon(weapon);
        character->EquipStatus(weapon->attack, 0);
    }
}
void Inventory::EquipArmor(Item* armor) {
    armor->equip = true;
    //���� ������� ��
    if (character->GetEquipArmor() == nullptr)
    {
        character->SetEquipArmor(armor);
        character->EquipStatus(0, armor->health);
    }
    else
    {
        //���� �� ����
        UnEquipArmor();
        character->UnEquipStatus(0, character->GetEquipArmor()->health); //���� ��� ���� ���Ⱥ���

        //���ο� �� ����
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