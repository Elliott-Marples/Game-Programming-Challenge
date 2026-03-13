// Related Header
#include "world.h"

#include "grid.h"



// Global Variables
Grid grid;

World::World() {
	click = false;
}

void World::Init() {
	window = SDL_CreateWindow("Conway's Game of Life", 250, 250, 800, 600, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	grid.Init(400-125, 300-125, 250, 250);
}

void World::Run() {
	while (!done) {
		timer.Reset();

		Input();
		Update();
		Render();

		if (timer.Get() < DELTA_TIME) {
			SDL_Delay(DELTA_TIME - timer.Get());
		}
	}
}

void World::Input() {
	while (SDL_PollEvent(&_event)) {
		if (_event.type == SDL_QUIT) {
			done = true;
		}

		if (_event.type == SDL_KEYDOWN && _event.key.repeat == 0) {
			switch (_event.key.keysym.sym) {
			case SDLK_ESCAPE:
				done = true;
				break;
			}
		}
	}
}

void World::Update() {

}

void World::Render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 20, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);

	grid.Render(renderer);
}

void World::Destroy() {
	if (renderer) {
		SDL_DestroyRenderer(renderer);
	}
	if (window) {
		SDL_DestroyWindow(window);
	}
}

void World::Quit() {
	grid.Destroy();
	Destroy();
}