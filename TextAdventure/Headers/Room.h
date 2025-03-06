#pragma once
#include "Item.h"
#include <string>


class Room {
public:
	Item* item;
	Room();
	Room(std::string descript, Item* item);
	~Room();

	void Description() const; // Outputs the objects description to the console
	void SetDescription(std::string descript); // Sets the objects description
	void SetItem(Item* item_ptr); // Sets the objects item
	bool empty;
private:
	std::string description;
};


