#pragma once

#include "Monster.h"

class Dragon : public Monster {
public:
	Dragon(int level);
	bool IsAlive();
	float getMultiplyHp() const override { return 1.5f; };
	float getMultiplyAtk() const override { return 1.5f; };
};