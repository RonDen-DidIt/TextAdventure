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
			if (notEmpty and player->GetX() != j and player->GetY() != i) {
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
	bool clear = true;
	int count = 0;
	while (true) {
		Room& playerRoom = rooms[player->GetX()][player->GetY()];
		if (clear || count > 3) {
			system("cls");
			DrawMap();
			playerRoom.Description();
			clear = false;
			count = 0;
		};


		if (playerRoom.item != nullptr) {
			playerRoom.item->Description();
			std::cout << "\nUse 'grab' to pick it up\n\n";
		}
		
		std::string command = player->GetCommand();
		count++;
		if (command == "w") {
			player->AddY(-1);
		}
		else if (command == "s") {
			player->AddY(1);
		}
		else if (command == "a") {
			player->AddX(-1);
		}
		else if (command == "d") {
			player->AddX(1);
		}
		else if (command == "use") {
			player->Use();
			continue;
		}
		else if (command == "grab") {
			if (playerRoom.item == nullptr) {
				std::cout << "This room has no item\n";
				continue;
			}
			else {
				player->InventoryInsert(playerRoom.item);
				std::cout << "You picked up a " << playerRoom.item->name << "\n";
				playerRoom.SetItem(nullptr);
				continue;
			}
		}
		else if (command == "help") {
			std::cout << "w: move up\ns: move down\na: move left\nd: move right\ngrab: pick up item\nuse: use item\nclear: clears screen";
			continue;
		}
		else if (command == "clear") {
		}
		else {
			continue;
		}
		clear = true;
	}
}



