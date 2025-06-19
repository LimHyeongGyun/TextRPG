#pragma once
#include "Item.h"
#include<vector>
#include<iostream>
class Inventory
{
protected:
	std::vector<Item>Itemlist;


public:
	void AddItem();
	void DelItem();
	void GetAll();
	void UseItem();

};


