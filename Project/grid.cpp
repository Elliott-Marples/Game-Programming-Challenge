// Related Header
#include "grid.h"

// Standard Headers
#include <vector>



// Global Variables
std::vector<Cell*> cellsList;

Grid::Grid() {
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Grid Constructed with Param(%p)", this);
}

Grid::~Grid() {
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Grid Destroyed with Param(%p)", this);
}

void Grid::Init(int posX, int posY, int width, int height) {
	this->width = width;
	this->height = height;
	this->posX = posX;
	this->posY = posY;

	int cellWidth = width / columns;
	int cellHeight = height / rows;

	for (int x = 0; x < columns; x++) {
		for (int y = 0; y < rows; y++) {
			Cell* currentCell = new Cell();
			currentCell->Init(posX + (cellWidth * x+1), posY + (cellHeight * y+1), cellWidth, cellHeight);
		}
	}
}

void Grid::Update() {

}

void Grid::Render(SDL_Renderer* renderer) {
	for (int x = 0; x < columns; x++) {
		for (int y = 0; y < rows; y++) {
			cells[x][y]->Render(renderer);
		}
	}
}

void Grid::Destroy() {
	for (int x = 0; x < columns; x++) {
		for (int y = 0; y < rows; y++) {
			delete cells[x][y];
		}
	}
}