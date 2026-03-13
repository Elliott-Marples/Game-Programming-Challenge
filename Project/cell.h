#ifndef PROJECT_CELL_H
#define PROJECT_CELL_H

#include "SDL.h"

class Grid;

class Cell {
public:
	Cell();
	~Cell();

	void Init(int x, int y, int w, int h);
	void Update();
	void Render(SDL_Renderer* renderer);

	SDL_Rect rect;
	bool isLive;

	Grid* parent;
};

#endif // !PROJECT_CELL_H
