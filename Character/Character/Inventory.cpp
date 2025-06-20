#include "Inventory.h"

Inventory* Inventory::iveninstance = nullptr;

Character* character = Character::GetInstance();

Inventory* Inventory::GetInstance(string name)
{
    if (iveninstance == nullptr)
    {
        iveninstance = new Inventory(); //�κ��丮 �������ֱ�
    }

    return iveninstance;
}

void Inventory::ClassificationItem(Item* item, int num)
{
    if (dynamic_cast<HealingPotion*>(item))
    {
        potionValue[item] = num;
    }
    if (dynamic_cast<Weapon*>(item))
    {
        weaponValue.push_back(item);
    }
    if (dynamic_cast<Armor*>(item))
    {
        armorValue.push_back(item);
    }
}

void Inventory::DisplayInventory()
{
    int category;

    cout << "Ȯ���� �κ��丮�� ī�װ� ��ȣ�� �Է����ּ���." << endl;
    cout << "1. �Ҹ��� ������" << endl;
    cout << "2. ����" << endl;
    cout << "3. ��" << endl;
    cin >> category;

    if (category == 1)
    {
        DisplayConsumeItem();
    }
    else if (category == 2)
    {
        DisplayWeapon();
    }
    else if (category == 3)
    {
        DisplayArmor();
    }
}

void Inventory::DisplayConsumeItem()
{
    //�����ϰ� �ִ� �Һ�������� ���� ��
    if (potionValue.empty())
    {
        cout << "�����ϰ� �ִ� �Һ������ �����ϴ�." << endl;
        return;
    }

    for (unordered_map<Item*, int>::value_type& p : potionValue)
    {
        cout << "������ �̸�" << p.first->name << "" << p.second << "��" << endl;
    }

    string key;
    cout << "����� �������� �̸��� �Է��� �ּ���: (����ϱ� 'p' �Է�)" << key << endl;
    if (key  == "p")
    {
        cout << "����߽��ϴ�." << endl;
    }
    else if (key != "p")
    {
        for (unordered_map<Item*, int>::value_type& p : potionValue)
        {
            if (p.first->name == key) {
                p.first->Use(character);
            }
        }
    }
}

void Inventory::DisplayWeapon()
{
    //�����ϰ� �ִ� ���Ⱑ ���� ��
    if (weaponValue.size() == 0) {
        cout << "�����ϰ� �ִ� ���Ⱑ �����ϴ�." << endl;
        return;
    }

    for (int i = 0; i < weaponValue.size(); i++) {
        cout << i + 1 <<".���� �̸�: " << weaponValue[i]->name << endl;
    }
    int num = 0;
    cout << "���⸦ �����Ϸ��� ���ϴ� ������ ���ڸ� �Է��� �ּ���(����ϱ� '0' �Է�): " << num << endl;

    if (num == 0)
    {
        cout << "����߽��ϴ�." << endl;
    }
    //��� ������ ��
    else if (num != 0) {
        EquipWeapon(weaponValue[num - 1]);
    }
}

void Inventory::DisplayArmor()
{
    //�����ϰ� �ִ� ���� ���� ��
    if (armorValue.size() == 0) {
        cout << "�����ϰ� �ִ� ���� �����ϴ�." << endl;
        return;
    }

    for (int i = 0; i < armorValue.size(); i++) {
        cout << i + 1 << ".�� �̸�: " << armorValue[i]->name << endl;
    }
    int num = 0;
    cout << "���� �����Ϸ��� ���ϴ� ���� ���ڸ� �Է��� �ּ���(����ϱ� '0' �Է�): " << num << endl;

    if (num == 0)
    {
        cout << "����߽��ϴ�." << endl;
    }
    //��� ������ ��
    else if (num != 0) {
        EquipArmor(armorValue[num - 1]);
    }
}



void Inventory::EquipWeapon(Item* weapon)
{
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
void Inventory::EquipArmor(Item* armor)
{
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
void Inventory::UnEquipWeapon()
{
    character->GetEquipWeapon()->equip = false;
}
void Inventory::UnEquipArmor()
{
    character->GetEquipArmor()->equip = false;
}

void Inventory::ReleaseInstance()
{
    delete iveninstance;
    iveninstance = nullptr;
}