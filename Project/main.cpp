// Library Headers
#include "sdl.h"

// Project Headers
#include "world.h"



// Global Variables
World world;

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return 1;
	}

	world.Init();
	world.Run();
	world.Quit();

	SDL_Quit();

	return 0;
}