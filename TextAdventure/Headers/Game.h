#pragma once
#include "Beyblade.h"
#include "Item.h"
#include <array>
#include "Player.h"
#include "Room.h"

class Game {
public:
	Game();
	~Game();
	void run();
private:
	static const int rows = 6;
	static const int columns = 6 ;

	Room rooms[rows][columns] = {};

	std::array<std::string, 4> descriptions = {"The room is", "Big room", "Small room", "No room"};
	std::array<Item*, 1>  items = {
		new Beyblade()
	};
};

