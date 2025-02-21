#pragma once
#include "Player.h"
#include "Room.h"

class Game {
public:
	Game();
	~Game();
	void run();
private:
	Room rooms[20][20];
	Player* player;
};