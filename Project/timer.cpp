// Related Header
#include "timer.h"

// Library Headers
#include "SDL.h"



Timer::Timer() {
	start = 0;
}

void Timer::Reset() {
	start = SDL_GetTicks();
}

int Timer::Get() {
	return (SDL_GetTicks() - start);
}