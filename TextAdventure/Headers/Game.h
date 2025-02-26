#pragma once
#include "Player.h"
#include "Room.h"

class Game {
public:
	Game();
	~Game();
	void run();
private:
	Room rooms[20][20] = {};
	Player* player;

	std::string descriptions[4] = {"The room is", "Big room", "Small room", "No room"};
};