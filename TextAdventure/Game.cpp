#include "Headers/Beyblade.h"
#include "Headers/Game.h"
#include <iostream>
#include <time.h>

Game::Game() {
	player = new Player;

	srand(time(NULL));
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			bool notEmpty = (rand() % 4 == 1);
			if (notEmpty) {
				SetRandomMembers(rooms[j][i]);
			}
		}
	}
}

Game::~Game() {}

void Game::DrawMap() {
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			std::string out = (rooms[j][i].empty) ? "[ ]" : "[O]";
			if (player->GetX() == j && player->GetY() == i) {
				out = "[X]";
			}
			std::cout << out;
		}
		std::cout << "\n";
	}
}

void Game::SetRandomMembers(Room& room) {
	int itemNumber = (rand() % totalItems);

	switch (itemNumber) {
	case 0:
		itemsVector.push_back(new Beyblade);
	}
	room.SetMembers(descriptionsArray[rand() % (descriptionsArray.size())], itemsVector.back());
}

void Game::Run() {
	while (true) {
		DrawMap();
		break;
		//print room description
		//prompt input
		//process input
	}
}



