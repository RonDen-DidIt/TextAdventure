#include "Headers/Lamp.h"
#include <iostream>

Lamp::Lamp() {
	this->name = "lamp";
}

void Lamp::Description() const {
	std::cout << "You see an item! It says: I am a lamp\n";
}

void Lamp::Use() {
	std::cout << "I am on\n";
}
