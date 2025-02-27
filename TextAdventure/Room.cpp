#include "Headers/Room.h"
#include <iostream>

Room::Room() : item(nullptr), description("Empty space"), empty(true) {}
Room::Room(std::string descript, Item* item) : description(descript), item(item) {}
Room::~Room() {}

void Room::Description() const {
	std::cout << description << "\n";
}

void Room::SetMembers(std::string descript, Item* item_ptr) {
	description = descript;
	item = item_ptr;
	empty = false;
}
