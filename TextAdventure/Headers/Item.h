#pragma once
#include <string>


class Item {
public:
	std::string name; // Name
	virtual void Description() const = 0; // Outputs item description
	virtual void Use() = 0; // Uses the item
};

