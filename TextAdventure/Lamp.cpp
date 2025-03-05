#include "Headers/Lamp.h"
#include <iostream>

void Lamp::Description() const {
	std::cout << "I am a lamp\n";
}

void Lamp::Use() {
	std::cout << "I am on\n";
}
