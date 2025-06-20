#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string>
#include <vector>

#include "Inventory.h"

using namespace std;

class Character {
private:
	static Character* charinstance;

	string name; //�÷��̾� �̸�
	int level = 1; //����
	int maxLevel = 10;
	int health = 0; //���� ü��
	int maxHealth = 0; //�ִ� ü��
	int attack = 0; //���ݷ�
	int experience = 0; //����ġ
	int needExperience = 100;
	int gold = 0; //���� ���

	Item* equipWeapon;
	Item* equipArmor;

	void UpgradeStatus(); //������ ���� �� ���� ���׷��̵�
	void LevelUp(); //������

public:
	Character();
	static Character* GetInstance(string name = " "); //�̱��� �ν��Ͻ�
	void DisplayStatus(); //�÷��̾��� ���� ���� Ȯ��

	//���� ����
	void Attack();
	void TakeDamage(int damage); //�ǰݽ�
	void RecoveryHP(int health); //ü�� ȸ��
	void GetExperience(int experience); //����ġ ȹ�� -> ���� óġ�� ������ ����������� ȣ���Ͽ� ���
	void GetItem(Item* item, int num);
	void Die();

	//������ ����
	void UseItem(int index); //������ ���
	Item* GetEquipWeapon(); //���� ���� ���� ��ȯ
	Item* GetEquipArmor(); //���� ���� �� ��ȯ
	void SetEquipWeapon(Item* weapon); //���� ����
	void SetEquipArmor(Item* armor); //�� ����
	void EquipStatus(int getAttack, int getHealth); //��� ������ ���� ��ȯ
	void UnEquipStatus(int getAttack, int getHealth); //��� ������ ���� ��ȯ

	void VisitShop(); //Shop�� ��ȣ�ۿ�
	static void ReleaseInstance(); //�޸� ����
};

#endif