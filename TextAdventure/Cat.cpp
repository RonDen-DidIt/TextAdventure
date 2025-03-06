#include "Headers/Cat.h"
#include <iostream>

Cat::Cat() {
	this->name = "dog";
}

Cat::~Cat() {}

void Cat::Description() const {
	std::cout << "You see an item! It says: I am a cat\n";
}

void Cat::Use() {
	if (purring) {
		std::cout << "It purrs\n";
		purring = false;
	}
	else {
		std::cout << "It meows\n";
		purring = true;
	}
}
