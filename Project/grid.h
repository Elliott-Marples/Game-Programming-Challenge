#ifndef PROJECT_GRID_H
#define PROJECT_GRID_H

// Library Headers
#include "SDL.h"

// Project Headers
#include "world.h"
#include "cell.h"

#define GRID_SIZE_X 96
#define GRID_SIZE_Y 96

class World;

class Grid {
private:
	int columns = GRID_SIZE_X;
	int rows = GRID_SIZE_Y;

public:
	Grid();
	~Grid();

	int width;
	int height;
	int posX;
	int posY;

	Cell* cells[GRID_SIZE_X][GRID_SIZE_Y];

	void Init(int posX, int posY, int width, int height);
	void Update();
	void Render(SDL_Renderer* renderer);
	void Destroy();

	World* parent;
};

#endif // !PROJECT_GRID_H
