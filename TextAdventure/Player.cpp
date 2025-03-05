#include <iostream> 
#include "Headers/Player.h"


Player::Player() : spells{ "Eclipse", "Eruption", "Frostbite", "Levitate", "Mirage", "Petrify", "Polymorph", "Teleport", "Thunderwave", "Vortex" } {
	
}

Player::~Player() {

}


int Player::GetX() {
	return x;
}

int Player::GetY() {
	return y;
}

void Player::SetPos(int sx, int sy) {
	x = sx;
	y = sy;
}

std::string Player::GetCommand() {
	std::cout << "Type command:";
	std::string command;
	std::getline(std::cin, command);
	for (int i = 0; i < command.size(); i++) {
		if (command[i] >= 'A' && command[i] <= 'Z') {
			command[i] += 'a' - 'A';
		}
	}

	if (command == "w") {
		y -= 1;
	}
	else if (command == "s") {
		y += 1;
	}
	else if (command == "a") {
		x -= 1;
	}
	else if (command == "d") {
		x += 1;
	}
	else {
		return command;
	}
	return "";
}



void Player::inventoryInsert(Item* item_ptr) {
	inventory.push_back(item_ptr);
};
