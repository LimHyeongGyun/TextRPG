#pragma once

#ifndef MONSTER_H_
#define MONSTER_H_

#include <string>
#include <random>

using namespace std;

inline int getRandomInRange(int min, int max) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<> dist(min, max);

	return dist(gen);
}

class Monster {
public:
	virtual string getName() const = 0;						// 몬스터 이름
	virtual int getHealth() const = 0;						// 몬스터 체력
	virtual int Attack() const = 0;							// 몬스터 공격력
	virtual void takeDamage(int damage) = 0;				// 몬스터가 받는 피해 (인수: 캐릭터의 대미지)
	virtual int getExpDrop() const = 0;						// 경험치 드랍
	virtual int getGoldDrop() const = 0;					// 골드 드랍
	virtual string getItemDrop() const = 0;					// 아이템 드랍


	virtual ~Monster() {};
};

class Goblin : public Monster {
private:
	string name;
	int health;
	int attack;
	int expDrop;
	int goldDrop;
	string itemDrop;
public:
	Goblin(int level);
	string getName() const override;
	int getHealth() const override;
	int Attack() const override;
	void takeDamage(int damage) override;
	int getExpDrop() const override;
	int getGoldDrop() const override;
	string getItemDrop() const override;

};

class Orc : public Monster {
private:
	string name;
	int health;
	int attack;
	int expDrop;
	int goldDrop;
	string itemDrop;
public:
	Orc(int level);
	string getName() const override;
	int getHealth() const override;
	int Attack() const override;
	void takeDamage(int damage) override;
	int getExpDrop() const override;
	int getGoldDrop() const override;
	string getItemDrop() const override;
};

class Troll : public Monster {
private:
	string name;
	int health;
	int attack;
	int expDrop;
	int goldDrop;
	string itemDrop;
public:
	Troll(int level);
	string getName() const override;
	int getHealth() const override;
	int Attack() const override;
	void takeDamage(int damage) override;
	int getExpDrop() const override;
	int getGoldDrop() const override;
	string getItemDrop() const override;
};

class Slime : public Monster {
private:
	string name;
	int health;
	int attack;
	int expDrop;
	int goldDrop;
	string itemDrop;
public:
	Slime(int level);
	string getName() const override;
	int getHealth() const override;
	int Attack() const override;
	void takeDamage(int damage) override;
	int getExpDrop() const override;
	int getGoldDrop() const override;
	string getItemDrop() const override;
};

class Dragon : public Monster {
private:
	string name;
	int health;
	int attack;
	int expDrop;
	int goldDrop;
	string itemDrop;
public:
	Dragon(int level);
	string getName() const override;
	int getHealth() const override;
	int Attack() const override;
	void takeDamage(int damage) override;
	int getExpDrop() const override;
	int getGoldDrop() const override;
	string getItemDrop() const override;
};

#endif
