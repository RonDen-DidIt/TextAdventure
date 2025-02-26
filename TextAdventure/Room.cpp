#include "Headers/Room.h"
#include <iostream>

Room::Room(): item(nullptr), description("Empty room") {}
Room::Room(std::string descript, Item* item) : description(descript), item(item) {}
Room::~Room() {}

void Room::Description() const {
	std::cout << description << "\n";
}

void Room::SetDescription(std::string descript) {
	description = descript;
}
