#include <iostream>
#include "Character.h"

Character* Character::instance = nullptr;

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

#pragma region 체력관련

void Character::DecreaseHP(int damage)
{
    health -= damage;
    if (health <= 0) {
        health = 0;
        Die();
    }
}

void Character::RecoveryHP(int recoveryHp)
{
    health += recoveryHp; //체력 회복

    //만약 회복한 후 체력이 최대 체력을 넘는다면
    if (health > maxHealth) {
        health = maxHealth; //체력을 최대체력으로 조정
    }
}

void Character::Die()
{
    cout << "플레이어 캐릭터가 사망하였습니다." << endl;
}
#pragma endregion

#pragma region 레벨업관련
void Character::UpgradeStatus()
{
    maxHealth += level * 20; //최대 체력 증가
    attack = attack + level * 5; //공격력 증가

    RecoveryHP(maxHealth); //체력 회복
}

void Character::LevelUp()
{
    if (level < maxLevel) {
        level += 1;
    }
    UpgradeStatus();
}
#pragma endregion

#pragma region 전투 종료시 경험치와 아이템 획득
void Character::GetExperience(int getExperience)
{
    experience += getExperience;

    while(experience >= needExperience)
    {
        experience -= needExperience; //레벨업에 필요한 경험치만큼 제거
        LevelUp();
    }
}

void Character::GetItem(Item* getItem)
{
    inventory.push_back(getItem); //아이템 획득
}
#pragma endregion

#pragma region 아이템 사용 및 상점이용
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

//무기 장착
void Character::EquipWeapon(Item* weapon)
{
    //무기가 비어있을 때
    if (equipWeapon == nullptr) {
        equipWeapon = weapon;
    }
    else {
        UnEquipWeapon();
        equipWeapon = weapon;
    }
}
//방어구 장착
void Character::EquipArmor(Item* armor)
{
    //방어구가 비어있을 때
    if (equipArmor == nullptr) {
        equipArmor = armor;
    }
    else {
        UnEquipArmor();
        equipArmor = armor;
    }
}
//무기 장착
void Character::UnEquipWeapon()
{
}
//무기 해제
void Character::UnEquipArmor()
{
}


void Character::VisitShop()
{
}
#pragma endregion

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

    /*character->GetExperience(300);
    character->DisplayStatus();*/

    
    Character::ReleaseInstance(); //메모리 해제

    return 0;
}