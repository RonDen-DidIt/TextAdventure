#include "Headers/BoxOfDonuts.h"
#include <iostream>

BoxOfDonuts::BoxOfDonuts() {
	this->name = "boxofdonuts";
}

BoxOfDonuts::~BoxOfDonuts() {}

void BoxOfDonuts::Description() const {
	std::cout << "You see an item! It says: I am a box of donuts\n";
}

void BoxOfDonuts::Use() {
	--count;
	if (count < 1 ) {
		std::cout << "No more donuts remaining";
		return;
	}
	std::cout << "It donut. " << count << " remaining\n";
	
}
