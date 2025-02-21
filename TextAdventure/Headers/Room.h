#pragma once
#include "Item.h"
#include <string>


class Room {
public:
	Item* item;
	Room(std::string descript, Item* item);
	~Room();
	void Description() const;

private:
	std::string description;
};


