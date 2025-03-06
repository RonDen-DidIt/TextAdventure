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

	void DrawMap(); // Draws the map to the screen
	void SetRandomMembers(Room& room); // Setting a random item and description for room
	void Run(); // Main game loop
private:
	static const int rows = 6;
	static const int columns = 6;
	static const int totalItems = 3;

	Room rooms[rows][columns] = {};

	std::array<std::string, 4> descriptionsArray = {"It's a dark room", "It's a large room", "It's just another room", "It's a room"};
	std::vector<Item*> itemsVector = {};

	Player* player;
};

