#include "Game.h"

int main(int argc, char** argv) {
	Game game;
	bool success = game.Initialize();
	if (success) {
		game.Run(); //ŠJn
	}
	game.Shutdown(); //I—¹
	return 0;
}