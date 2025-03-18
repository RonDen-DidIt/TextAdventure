#include "Headers/Player.h"
#include <cstring>
#include <iostream> 

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
void Player::AddX(int add) {
	x += add;
}

void Player::AddY(int add) {
	y += add;
}


void Player::SetPos(int sx, int sy) {
	x = sx;
	y = sy;
}

std::string Player::GetCommand() {
	std::cout << "\nw,a,s,d to move. Type help for list of commands\nType command:";
	std::string command;
	std::getline(std::cin, command);
	for (int i = 0; i < command.size(); i++) {
		if (command[i] >= 'A' && command[i] <= 'Z') {
			command[i] += 'a' - 'A';
		}
	}

	return command;
}

void Player::Use() {
	for (int i = 0; i < inventory.size(); i++) {
		std::cout << i + 1 << ": " << inventory[i]->name << "\n";
	}
	std::cout << "\n";
	std::cout << "Type number: ";
	std::string number;
	std::getline(std::cin, number);
	if (number.size() < 1 || number[0] < 48 || number[0] > 57) {
		std::cout << "Invalid number\n";
		return;
	}
	int index = std::stoi(number);
	if (index < 1 || index > inventory.size()) {
		std::cout << "No item for that number\n";
		return;
	}
	inventory[index - 1]->Use();
}

bool Player::FindSpell(std::string spell) {
	int left = 0;
	int right = spells.size() - 1;
	

	while (left <= right) {
		int middle = (left + right) / 2;
		int compared = strcmp(spell.c_str(), spells[middle].c_str());
		
		if (compared == -1) {
			right = middle - 1;
		}
		else if (compared == 1) {
			left = middle + 1;
		}
		else {
			return true;
		}
	}
	return false;
}

void Player::InventoryInsert(Item* item_ptr) {
	inventory.push_back(item_ptr);
}
