#include "Headers/BoxOfDonuts.h"
#include "Headers/Lamp.h"
#include "Headers/Cat.h"
#include "Headers/Game.h"
#include <cstdlib>
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

Game::~Game() {
	for (int i = 0; i < itemsVector.size(); i++) {
		delete itemsVector[i];
	}
	delete player;
}

void Game::DrawMap() {
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			std::string out = (rooms[j][i].empty) ? "[ ]" : "[\033[38;5;120mO\033[38;5;255m]";
			if (player->GetX() == j && player->GetY() == i) {
				out = "[\033[38;5;196mX\033[38;5;255m]";
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
		if (command == "w") {
			if (player->GetY() - 1 >= 0)
			player->AddY(-1);
		}
		else if (command == "s") {
			if (player->GetY() + 1 < columns) {
				player->AddY(1);
			}
		}
		else if (command == "a") {
			if (player->GetX() - 1 >= 0) {
				player->AddX(-1);
			}
		}
		else if (command == "d") {
			if (player->GetX() + 1 < rows) {
				player->AddX(1);
			}
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
			std::cout << "w: move up\ns: move down\na: move left\nd: move right\ngrab: pick up item\nuse: use item\nclear: clears screen\nspell: check spell\nquit: closes game";
			continue;
		}
		else if (command == "spell") {
			std::string spell;
			std::cout << "Spell: ";
			std::getline(std::cin, spell);

			if (player->FindSpell(spell)) {
				std::cout << "You have that spell";
			}
			else {
				std::cout << "You don't have that spell";
			}
			continue;
		}
		else if (command == "clear") {
		}
		else if (command == "quit") {
			return;
		}
		else {
			count++;
			continue;
		}
		clear = true;
	}
}



