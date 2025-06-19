#include <iostream>
#include "Character.h"

Character* Character::instance = nullptr;

Character::Character() {
    name = name;
    level = 1;
    maxHealth = 200;
    health = maxHealth;
    attack = 30;
    experience = 0;
    needExperience = 100;
    gold = 0;
}

Character* Character::GetInstance(string name)
{
    //만약 instance가 생성되지 않았다면
    if (instance == nullptr)
    {
        instance = new Character(); //캐릭터 생성해주기
    }
    
    instance->name = name;

    return instance;
}

void Character::DisplayStatus()
{
    cout << "플레이어 캐릭터 이름: " << name << endl;
    cout << "플레이어 레벨: " << level << endl;
    cout << "플레이어 현재체력/최대체력: " << health << "/" << maxHealth << endl;
    cout << "플레이어 공격력: " << attack << endl;
    cout << "플레이어 현재 경험치/레벨업에 필요한 경험치: " << experience << "/" << needExperience << endl;
    cout << "플레이어 소지 골드: " << gold << endl;
}

void Character::RecoveryHP(int health)
{
    instance->health += health; //체력 회복

    //만약 회복한 후 체력이 최대 체력을 넘는다면
    if (instance->health > instance->maxHealth) {
        instance->health = instance->maxHealth; //체력을 최대체력으로 조정
    }
}

void Character::UpgradeStatus()
{
    instance->maxHealth += instance->level * 20; //최대 체력 증가
    instance->attack = instance->attack + instance->level * 5; //공격력 증가

    RecoveryHP(instance->maxHealth); //체력 회복
}

void Character::LevelUp()
{
    instance->level += 1;
    UpgradeStatus();
}

void Character::GetExperience(int experience)
{
    instance->experience += experience;

    while(instance->experience >= needExperience)
    {
        instance->experience -= needExperience; //레벨업에 필요한 경험치만큼 제거
        LevelUp();
    }
}

void Character::UseItem(int index)
{
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
    cout << "사용할 캐릭터 이름을 입력 해 주세요: ";
    cin >> playerName;

    Character* character = Character::GetInstance(playerName);
    character->DisplayStatus();

    Character::ReleaseInstance();

    return 0;
}