#pragma once
#include <string>
#include <vector>

class Player {
public:
	Player();
	~Player();


	bool FindSpell(std::string spell);
	int GetX();
	int GetY();
	void SetPos(int x, int y);
	
	void GetCommand();
private:
	std::vector<std::string> spells;
	int health = 100;
	int x = 0;
	int y = 0;

};
