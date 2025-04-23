#pragma once
#include "ourLibrary.h"

class Map {
public:
	Map() {};
	~Map() {};

	void Draw(RenderWindow& window) {
		int x = 0;
		for (const auto& column : grid) {
			int y = 0;
			for (const auto& cell : column) {
				if (cell) {
					sf::RectangleShape tile;
					tile.setSize(sf::Vector2f(tileSize, tileSize));
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
		
		for (size_t x = 0; x < grid.size(); x++) {
			for (size_t y = 0; y < grid[x].size(); y++) {
				Color colorPixel = image.getPixel(sf::Vector2u(x, y));
				if (colorPixel == Color::Black) { grid[x][y] = 1; } // 1 for block
			}
		}
	}
	bool isColliding(const sf::FloatRect& bounds) const {
		for (size_t x = 0; x < grid.size(); x++) {
			for (size_t y = 0; y < grid[x].size(); y++) {
				if (grid[x][y] >= 1) {
					sf::FloatRect tileRect(sf::Vector2f(x * tileSize, y * tileSize), sf::Vector2f(tileSize, tileSize));
					if (bounds.findIntersection(tileRect)) {
						return true;
					}
				}
			}
		}
		return false;
	}
private:
	vector <vector<int>> grid;
	const float tileSize = 60;
};