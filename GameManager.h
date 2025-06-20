#pragma once

class Character;
class Monster;
class BossMonster;
class Shop;

class GameManager {
public:
    GameManager();
    Character* player;
    Shop* shop;

    Monster* GenerateMonster(int level);
    BossMonster* GenerateBossMonster(int level);

    void Battle(Character* player, Monster* monster);
    void visitShop(Character* player);
    void DisplayInventory(Character* player);
    void Run();
};