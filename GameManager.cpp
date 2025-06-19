#include "GameManager.h" 
#include "Slime.h" // 슬라임
#include "Orc.h" // 오크
#include "Troll.h" // 트롤 
#include "Goblin.h" // 고블린 
#include "Item.h" // 아이템
#include <iostream>

using namespace std;

// 만들어야 하는 것
// 1. 게임 캐릭터를 생성하는 코드
// 2. 몬스터 생성 로직
// 3. 전투에 대한 로직
// 4. 아이템 로직

Monster* GameManager::GenerateMonster(int level) { // 몬스터 스폰 

    Monster* spawn;

    if (level <= 3) { spawn = new Slime(); } // 슬라임 스폰
    else if (level <= 6) { spawn = new Orc(); } // 오그 스폰
    else if (level <= 9) { spawn = new Troll(); } // 트롤 스폰
    else { spawn = new Goblin(); } // 고블린 스폰
    return spawn;
}

void GameManager::Battle(Character* character, Monster* monster) // 몬스터와 전투 (몬스터를 잡을 시 경험치 및 보상 구현)
{
    while (character->isAlive() && monster->isAlive()) // 플레이어와 몬스터가 둘다 살아있다면 실행
    {
        int damage = character->getAttack(); // 플레이어 턴
        monster->takeDamage(damage);
        cout << character->getName() << "이(가) " << monster->getName() << "에게 " << damage << "의 데미지를 입혔습니다!" << endl;
        cout << monster->getName() << " HP: " << monster->getHP() << endl;

        if (monster->isAlive()) // 몬스터 턴 – 살아있을 때
        {
            damage = monster->getAttack();
            character->takeDamage(damage);
            cout << monster->getName() << "이(가) " << character->getName() << "에게 " << damage << "의 반격 데미지를 입혔습니다!" << endl;
            cout << character->getName() << " HP: " << character->getHP() << endl;
        }
    }

    if (character->isAlive()) { // 전투 결과
        cout << "전투 종료!" << endl;
        cout << monster->getName() << " 처치 성공!" << endl;

        Item* item = monster->DropItem(); // 몬스터에게서 아이템 드롭
        character->AddItem(item); // 캐릭터 인벤토리에 아이템 저장
        cout << "획득 아이템:" << item->getName() << endl; // 획은한 아이템에 대한 이름 출력
    }
    else {
        cout << endl;
        cout << character->getName() << "이(가) 전투에서 패배했습니다..." << endl;
    }
}

void GameManager::DisplayInventory(Character* character) { // 인벤토리 보이기
    character->ShowInventory();
}

void Inventory::AddItem(Item* item) { // 인벤토리에 아이템 추가
    this->item.push_back(item);
}

void Inventory::ShowInventory() { // 인벤토리에 있는 아이템을 콘솔에 보여줌
    for (Item* i : item) {
        cout << " " << i->getName() << endl;
    }
}

void GameManager::Run() { // RPG 메인 루프 역할
    player = new Character("용사", 100, 20); // 플레이어 캐릭터 생성

    cout << endl;
    while (player->isAlive()) {
        cout << endl << "[레벨: " << player->getLevel() << "] 전투를 시작합니다." << endl;
        Monster* monster = GenerateMonster(player->getLevel()); // 레벨에 따라 몬스터 생성
        Battle(player, monster); // 몬스터와 전투
        DisplayInventory(player); // 플레이어의 인벤토리 출력

        char cont;
        cout << endl << "계속 하시겠습니까? (y/n): ";
        cin >> cont;
        if (cont != 'y' && cont != 'Y') break;
    }

    cout << endl << "게임 종료. 수고하셨습니다!" << endl;
}

int main() {





}


// 현재 가상 출력 시 결과
//구간	내용
//1 – 3 레벨 슬라임 반복 처치, EXP + 10씩 → 레벨 4 도달
//4 – 5 레벨 오크 등장, EXP + 20씩 획득 → 레벨 5 중반까지 진행
//레벨 5 오크의 공격력이 커서 3번째 오크 전투에서 HP 0 → 사망
//최종
//도달 레벨 : 5
//인벤토리 : 슬라임 젤리 × 6, 오크 송곳니 × 2