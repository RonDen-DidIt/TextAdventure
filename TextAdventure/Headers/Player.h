#pragma once
#include "Item.h"
#include <string>
#include <vector>

class Player {
public:
	Player();
	~Player();


	int GetX();
	int GetY();
	void AddX(int add); // x+=add
	void AddY(int add); // y+=add
	void SetPos(int x, int y);
	
	std::string GetCommand(); // Gets user input and converts to lowercase
	void InventoryInsert(Item* item_ptr); // Adds item_ptr to the spells vector
	void Use(); // Uses an item
	bool FindSpell(std::string spell); // Prompts for a spell and binary searches that spell
private:
	std::vector<std::string> spells;
	std::vector<Item*> inventory;
	int health = 100;
	int x = 0;
	int y = 0;

};
