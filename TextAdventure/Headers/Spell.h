#pragma once
#include <string>
class Spell {
public:
	std::string name;
	int damage;

	Spell(std::string name, int damage);
	void Cast();
	static bool Compare(Spell a, Spell b);
};