#pragma once
#include <array>
#include "Item.h"
#include <utility>
#include "Player.h"
#include "Room.h"

class Game {
public:
	Game();
	~Game();

	void DrawMap();
	void SetRandomMembers(Room& room);
	void Run();
private:
	static const int rows = 6;
	static const int columns = 6;
	static const int totalItems = 3;

	Room rooms[rows][columns] = {};

	std::array<std::string, 4> descriptionsArray = {"The room is", "Big room", "Small room", "No room"};
	std::vector<Item*> itemsVector = {};

	Player* player;
};

