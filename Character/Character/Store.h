#pragma once
#include "Item.h"
#include <vector>
class Store
{
	std::vector<Item> StoreList;
public:
	void SetItemList();
	void DisplayItem();
	Item* BuyItem(int index);
	void SellItem() {};
};
