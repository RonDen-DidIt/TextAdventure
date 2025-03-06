#include "Headers/Room.h"
#include <iostream>

Room::Room() : item(nullptr), description("Empty space"), empty(true) {}
Room::Room(std::string descript, Item* item) : description(descript), item(item), empty(false) {}
Room::~Room() {}

void Room::Description() const {
	std::cout << description << "\n\n";
}

void Room::SetDescription(std::string descript) {
	description = descript;
	empty = false;
}

void Room::SetItem(Item* item_ptr) {
	item = item_ptr;
}
