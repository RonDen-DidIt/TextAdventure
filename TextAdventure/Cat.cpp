#include "Headers/Cat.h"
#include <iostream>

void Cat::Description() const {
	std::cout << "I am a cat\n";
}

void Cat::Use() {
	std::cout << "It meows\n";
}
