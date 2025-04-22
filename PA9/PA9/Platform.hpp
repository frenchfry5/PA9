#pragma once
#include "Obstacle.hpp"

class Platform : public Obstacle
{
public:
	Platform() {};
	~Platform() {};
	void update(float deltaTime) override {

	}
	void render(RenderWindow& window) override {
		int x = 0;
		for (const auto& column : grid) {
			int y = 0;
			for (const auto& cell : column) {
				if (cell ) {
					sf::RectangleShape tile;
					tile.setSize(sf::Vector2f(tileSize, tileSize));
					switch (cell) {
					case 1: // Normal Block
						tile.setFillColor(sf::Color::Blue);
						break;
					case 2: // Lava
						tile.setFillColor(sf::Color::Red);
						break;
					case 3: // Ice
						tile.setFillColor(sf::Color::Cyan);
						break;
					case 4: // Slime
						tile.setFillColor(sf::Color::Green);
						break;
					default:
						tile.setFillColor(sf::Color::White);
						break;
					}

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
				if (colorPixel == Color::Black) { 
					grid[x][y] = 1; // 1 for block
				} 
				if (colorPixel == Color::Red) {
					grid[x][y] = 2; // 2 for lava
				}
				if (colorPixel == Color::Blue) {
					grid[x][y] = 3; // for Ice
				}
				if (colorPixel == Color::Green) {
					grid[x][y] = 4; // for Slime or bouncy
				}
			}
		}
	}
	bool isColliding(const sf::FloatRect& bounds) const {
		for (size_t x = 0; x < grid.size(); x++) {
			for (size_t y = 0; y < grid[x].size(); y++) {
				if (grid[x][y] == 1) {
					sf::FloatRect tileRect(sf::Vector2f(x * tileSize, y * tileSize), sf::Vector2f(tileSize, tileSize));
					if (bounds.findIntersection(tileRect)) {
						return true;
					}
				}
			}
		}
		return false;
	}

	int getTileType(const sf::FloatRect& bounds) const {
		for (size_t x = 0; x < grid.size(); x++) {
			for (size_t y = 0; y < grid[x].size(); y++) {
				if (grid[x][y] > 0) {
					sf::FloatRect tileRect(sf::Vector2f(x * tileSize, y * tileSize), sf::Vector2f(tileSize, tileSize));
					if (bounds.findIntersection(tileRect)) {
						return grid[x][y]; 
					}
				}
			}
		}
		return 0; 
	}
private:
	vector <vector<int>> grid;
	const float tileSize = 45;
};

