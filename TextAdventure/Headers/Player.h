#pragma once
#include <string>
#include <vector>

class Player {
public:
	Player();
	~Player();

	bool FindSpell(std::string spell);
private:
	std::vector<std::string> spells;
	int health = 100;
};