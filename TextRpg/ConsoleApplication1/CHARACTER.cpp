#include "Character.h"
#include<iostream>

Character * Character::instance = nullptr;

Character::Character() {
    name = name;
    level = 1;
    maxLevel = 10;
    maxHealth = 200;
    health = maxHealth;
    attack = 30;
    experience = 0;
    needExperience = 100;
    gold = 0;
}

Character* Character::GetInstance(string name)
{
    //���� instance�� �������� �ʾҴٸ�
    if (instance == nullptr)
    {
        instance = new Character(); //ĳ���� �������ֱ�
    }

    instance->name = name;

    return instance;
}

void Character::DisplayStatus()
{
    cout << "�÷��̾� ĳ���� �̸�: " << name << endl;
    cout << "�÷��̾� ����: " << level << endl;
    cout << "�÷��̾� ����ü��/�ִ�ü��: " << health << "/" << maxHealth << endl;
    cout << "�÷��̾� ���ݷ�: " << attack << endl;
    cout << "�÷��̾� ���� ����ġ/�������� �ʿ��� ����ġ: " << experience << "/" << needExperience << endl;
    cout << "�÷��̾� ���� ���: " << gold << endl;
}

void Character::RecoveryHP(int recoveryHp)
{
    health += recoveryHp; //ü�� ȸ��

    //���� ȸ���� �� ü���� �ִ� ü���� �Ѵ´ٸ�
    if (health > maxHealth) {
        health = maxHealth; //ü���� �ִ�ü������ ����
    }
}

void Character::UpgradeStatus()
{
    maxHealth += level * 20; //�ִ� ü�� ����
    attack = attack + level * 5; //���ݷ� ����

    RecoveryHP(maxHealth); //ü�� ȸ��
}

void Character::LevelUp()
{
    if (level < maxLevel) {
        level += 1;
    }
    UpgradeStatus();
}

void Character::GetExperience(int getExperience)
{
    experience += getExperience;

    while (experience >= needExperience)
    {
        experience -= needExperience; //�������� �ʿ��� ����ġ��ŭ ����
        LevelUp();
    }
}

void Character::GetItem(Item* getItem)
{
    inventory.push_back(getItem); //������ ȹ��
}

void Character::UseItem(int index)
{
    for (int i = 0; inventory.size(); i++)
    {
        if (inventory[i]->itemnum == index)
        {
            inventory[i]->Use(instance);
            break;
        }
    }
}

void Character::VisitShop()
{
}

void Character::ReleaseInstance()
{
    delete instance;
    instance = nullptr;
}

int main()
{
    string playerName;
    cout << "����� ĳ���� �̸��� �Է� �� �ּ���: ";
    cin >> playerName;

    Character* character = Character::GetInstance(playerName);
    character->DisplayStatus();

    character->GetExperience(300);
    character->DisplayStatus();



    Character::ReleaseInstance(); //�޸� ����

    return 0;
}