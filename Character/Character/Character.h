#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string>
#include <vector>

#include "Item.h"

using namespace std;

class Character {
private:
	static Character* instance;

	string name; //�÷��̾� �̸�
	int level = 1; //����
	int health = 0; //���� ü��
	int maxHealth = 0; //�ִ� ü��
	int attack = 0; //���ݷ�
	int experience = 0; //����ġ
	int needExperience = 100;
	int gold = 0; //���� ���

	vector<Item*> inventory; //������ ������ �κ��丮
public:
	Character();
	static Character* GetInstance(string name = " ");
	void DisplayStatus();
	void LevelUp();
	void UseItem(int index);
	void VisitShop(); //Shop�� ��ȣ�ۿ�
	static void ReleaseInstance();
};

#endif