#include "Character.h"




enum class ItemType {
    MonsterItem,
    HealingPotion,
    Armor,
    Weapon
};

struct Item {
    std::string name;
    ItemType type;
    int value;

    // 추가 속성 (선택적으로 사용)
    int heal = 0;
    int attack = 0;
    int defense = 0;
    bool equipped = false;
};