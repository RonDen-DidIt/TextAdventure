#pragma once
#include <list>
#include <string>

class Player {
public:
	Player();
	~Player();

	bool FindSpell(std::string spell);
private:
	std::string spells[5];
};