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
	virtual string getName() const = 0;
	virtual int getHealth() const = 0;
	virtual int Attack() const = 0;
	virtual void takeDamage(int damage) = 0;

	virtual ~Monster() {};
};

class Goblin : public Monster {
private:
	string name;
	int health;
	int attack;
public:
	Goblin(int level);
	string getName() const override;
	int getHealth() const override;
	int Attack() const override;
	void takeDamage(int damage) override;
};

class Orc : public Monster {
private:
	string name;
	int health;
	int attack;
public:
	Orc(int level);
	string getName() const override;
	int getHealth() const override;
	int Attack() const override;
	void takeDamage(int damage) override;
};

class Troll : public Monster {
private:
	string name;
	int health;
	int attack;
public:
	Troll(int level);
	string getName() const override;
	int getHealth() const override;
	int Attack() const override;
	void takeDamage(int damage) override;
};

class Slime : public Monster {
private:
	string name;
	int health;
	int attack;
public:
	Slime(int level);
	string getName() const override;
	int getHealth() const override;
	int Attack() const override;
	void takeDamage(int damage) override;
};

class BossMonster : public Monster {
private:
	string name;
	int health;
	int attack;
public:
	BossMonster(int level);
	string getName() const override;
	int getHealth() const override;
	int Attack() const override;
	void takeDamage(int damage) override;
};

#endif
