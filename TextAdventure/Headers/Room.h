#pragma once
#include "Item.h"
#include <string>


class Room {
public:
	Item* item;
	Room();
	Room(std::string descript, Item* item);
	~Room();

	void Description() const;
	void SetMembers(std::string descript, Item* item_ptr);
	bool empty;
private:
	std::string description;
};


