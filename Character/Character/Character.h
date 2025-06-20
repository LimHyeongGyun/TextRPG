#pragma once

using namespace std;

class Item;

class Character {
private:
	static Character* charInstance;

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
	static Character* Get(string name = " "); //�̱��� �ν��Ͻ�

	//�÷��̾� ����
	void DisplayStatus() const; //�÷��̾��� ���� ���� Ȯ��
	string GetName() const; //�÷��̾� �̸�

	//���� ����
	int Attack();
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

	//��� ����
	void GetGold(int getGold);
	void ConsumeGold(int consumeGold);
	void VisitShop(); //Shop�� ��ȣ�ۿ�

	~Character();
};