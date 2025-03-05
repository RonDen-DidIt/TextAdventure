#include "Headers/BoxOfDonuts.h"
#include "Headers/Lamp.h"
#include "Headers/Cat.h"
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
	std::cout << "\n";
}

void Game::SetRandomMembers(Room& room) {
	int itemNumber = (rand() % (totalItems + 3));
	
	room.SetDescription(descriptionsArray[rand() % (descriptionsArray.size())]);

	switch (itemNumber) {
	case 0:
		itemsVector.push_back(new BoxOfDonuts);
		break;
	case 1:
		itemsVector.push_back(new Lamp);
		break;
	case 2:
		itemsVector.push_back(new Cat);
		break;
	default:
		return;
	}
	room.SetItem(itemsVector.back());
}

void Game::Run() {
	std::string nextOutput;
	while (true) {
		system("cls");
		DrawMap();
		Room& playerRoom = rooms[player->GetX()][player->GetY()];
		playerRoom.Description();
		if (playerRoom.item != nullptr) {
			playerRoom.item->Description();
		}
		std::cout << nextOutput << "\n";
		nextOutput = "";
		std::string command = player->GetCommand();
		if (command.length() <= 0) {
			continue;
		}
		if (command == "grab") {
			std::cout << playerRoom.item;
			if (playerRoom.item == nullptr) {
				nextOutput = "This room has no item";
				continue;
			}
			else {
				player->inventoryInsert(playerRoom.item);
				playerRoom.SetItem(nullptr);
			}
		}
	}
}



