#pragma once
#include "Item.h"
#include <string>
#include <vector>

class Player {
public:
	Player();
	~Player();


	bool FindSpell(std::string spell);
	int GetX();
	int GetY();
	void SetPos(int x, int y);
	
	std::string GetCommand();
	void inventoryInsert(Item* item_ptr);
private:
	std::vector<std::string> spells;
	std::vector<Item*> inventory;
	int health = 100;
	int x = 0;
	int y = 0;

};
