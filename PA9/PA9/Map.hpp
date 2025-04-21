#pragma once
#include "ourLibrary.h"

class Map {
public:
	Map() {};
	~Map() {};

	void createTest(size_t width, size_t height) {
		grid = vector(width, vector(height, 1));
		int last = 0;
		for (auto& column : grid) {
			for (auto& cell : column) {
				last = cell = ~last;
			}
			if (width % 2 == 0) {
				last = ~last;
			}
		}
	}
	void Draw(RenderWindow& window) {
		int x = 0;
		for (const auto& column : grid) {
			int y = 0;
			for (const auto& cell : column) {
				if (cell) {
					sf::RectangleShape tile;
					tile.setSize(sf::Vector2f(tileSize, tileSize)); // You had a typo: "tileSiz"
					tile.setFillColor(sf::Color::Blue);
					tile.setPosition(sf::Vector2f(x * tileSize, y * tileSize));
					window.draw(tile);
				}
				y++;
			}
			x++;
		}
	}
	void LoadFromImage(sf::Image& image) {
		grid.clear();
		grid = vector(image.getSize().x, vector(image.getSize().y, 0));
		
		for (float x = 0; x < grid.size(); x++) {
			for (size_t y = 0; y < grid[x].size(); y++) {
				Color colorPixel = image.getPixel(sf::Vector2u(x, y));
				if (colorPixel == Color::Black) { grid[x][y] = 1; } // 1 for block
			}
		}
	}
private:
	vector <vector<int>> grid;
	const float tileSize = 32;
};