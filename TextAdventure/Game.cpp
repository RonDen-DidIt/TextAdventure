#include "Headers/Game.h"

Game::Game() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			rooms[i][j].SetDescription(descriptions[0]);
		}
	}
}
Game::~Game() {}

void Game::run() {

}
