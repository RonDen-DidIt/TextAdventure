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

void Player::GetCommand() {
	std::string command;
	std::cin >> command;
}