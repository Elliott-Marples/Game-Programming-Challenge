// Define Guard
#ifndef PROJECT_WORLD_H
#define PROJECT_WORLD_H

// Library Headers
#include "SDL.h"

// Project Headers
#include "timer.h"



// Definitions
#define FRAME_RATE 1

// Declarations
class World {
private:
	Timer timer;
	const int DELTA_TIME = 1000 / FRAME_RATE;
	bool done = false;

public:
	// Constructor
	World();

	// SDL Properties
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event _event;

	// Other Properties
	bool click;

	// Pre Game Loop
	void Init();
	void Run();

	// Game Loop
	void Input();
	void Update();
	void Render();

	// Post Game Loop
	void Destroy();
	void Quit();
};

#endif // !PROJECT_WORLD_H
