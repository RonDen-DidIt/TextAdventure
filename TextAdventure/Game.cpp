#include "Headers/Game.h"
#include <time.h>

Game::Game() {
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		int row = rand() % rows;
		int column = rand() % columns;
		rooms[row][column].SetDescription(descriptions[rand()%descriptions.size()]);
		rooms[row][column].item = items[rand()%items.size()];
	}

}
Game::~Game() {}

void Game::run() {
	while (true) {
		//draw map
		//print room description
		//prompt input
		//process input
	}
}
