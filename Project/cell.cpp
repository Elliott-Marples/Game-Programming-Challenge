#include "cell.h"

#include "SDL.h"

#include "grid.h"
#include "world.h"

Cell::Cell() {
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Cell Constructed with Param(%p)", this);
}

Cell::~Cell() {
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Cell Destroyed with Param(%p)", this);
}

void Cell::Init(int x, int y, int w, int h) {
	this->rect.x = x;
	this->rect.y = y;
	this->rect.w = w;
	this->rect.h = h;

	isLive = false;
}

void Cell::Update() {
	isLive = !isLive;
}

void Cell::Render(SDL_Renderer* renderer) {
	switch (isLive) {
	case true:
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	case false:
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	}

	SDL_RenderFillRect(renderer, &rect);
}