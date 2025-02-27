#include "Headers/Game.h"
#include <time.h>
#include <iostream>

Game::Game() {
	srand(time(NULL));
	for (int i = 0; i < 5; i++) { // Switch to looping throuhg whole array
		rooms[rand() % rows][rand() % columns].SetMembers(descriptions[rand() % descriptions.size()], items[rand() % items.size()]);
	}
}
Game::~Game() {}

void Game::run() {
	while (true) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				std::string out = (rooms[i][j].empty) ? "[ ]" : "[O]";
				std::cout << out;
			}
			std::cout << "\n";
		}
		break;
		//print room description
		//prompt input
		//process input
	}
}
