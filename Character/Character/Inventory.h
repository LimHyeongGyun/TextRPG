#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <iostream>
#include <vector>
#include <unordered_map>

#include "Character.h"
#include "Item.h"

using namespace std;

class Inventory{
private:
	static Inventory* iveninstance;
public:
	static Inventory* GetInstance(string name = " "); //�̱��� �ν��Ͻ�

	unordered_map<Item*, int> potionValue;
	vector<Item*> weaponValue;
	vector<Item*> armorValue;

	//�κ��丮 ����
	void ClassificationItem(Item* item, int num); //ȹ���� �������� �з��ؼ� �κ��丮�� �ֱ�
	void DisplayInventory();
	void DisplayConsumeItem();
	void DisplayWeapon();
	void DisplayArmor();

	//������ ���
	void EquipWeapon(Item* weapon); //���� ����
	void EquipArmor(Item* armor); //�� ����
	void UnEquipWeapon(); //�� ����
	void UnEquipArmor(); //���� ����

	static void ReleaseInstance();
};

#endif

