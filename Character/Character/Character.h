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
	int maxLevel = 10;
	int health = 0; //���� ü��
	int maxHealth = 0; //�ִ� ü��
	int attack = 0; //���ݷ�
	int experience = 0; //����ġ
	int needExperience = 100;
	int gold = 0; //���� ���

	vector<Item*> inventory; //������ ������ �κ��丮
	Item* equipWeapon;
	Item* equipArmor;

	void UpgradeStatus(); //������ ���� �� ���� ���׷��̵�
	void LevelUp(); //������

public:
	Character();
	static Character* GetInstance(string name = " "); //�̱��� �ν��Ͻ�
	void DisplayStatus(); //�÷��̾��� ���� ���� Ȯ��

	//���� ����
	void DecreaseHP(int damage); //�ǰݽ�
	void RecoveryHP(int health); //ü�� ȸ��
	void GetExperience(int experience); //����ġ ȹ�� -> ���� óġ�� ������ ����������� ȣ���Ͽ� ���
	void GetItem(Item* item);
	void Die();

	void UseItem(int index); //������ ���
	void EquipWeapon(Item* weapon); //���� ����
	void EquipArmor(Item* armor); //�� ����
	void UnEquipWeapon(); //���� ����
	void UnEquipArmor(); //�� ����

	void VisitShop(); //Shop�� ��ȣ�ۿ�
	static void ReleaseInstance(); //�޸� ����
};

#endif