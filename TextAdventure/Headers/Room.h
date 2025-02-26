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
	void SetDescription(std::string descript);

private:
	std::string description;
};


