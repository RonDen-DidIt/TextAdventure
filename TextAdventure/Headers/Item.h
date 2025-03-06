#pragma once
#include <string>


class Item {
public:
	std::string name;
	virtual void Description() const = 0;
	virtual void Use() = 0;
};

