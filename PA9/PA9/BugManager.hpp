#pragma once
#include "Bug.hpp"

class BugManager {
public:
    void LoadFromImage(const sf::Image& image) {
        const float tileSize = 55;
        bugs.clear();
        for (unsigned int x = 0; x < image.getSize().x; ++x) {
            for (unsigned int y = 0; y < image.getSize().y; ++y) {
                Color colorPixel = image.getPixel(sf::Vector2u(x, y));
                if (colorPixel == Color::Magenta) {
                    // pushback only allows one bug to move
                    // chatgpt fix
                    bugs.emplace_back(Vector2f(x * tileSize, y * tileSize));
                }
            }
        }
    }

    void update(float deltaTime, const Platform& pl) {
        for (auto& bug : bugs)
            bug.update(deltaTime, pl);
    }

    void render(RenderWindow& window) {
        for (auto& bug : bugs)
            bug.render(window);
    }

    const vector<Bug>& getBugs() const { return bugs; }
private:
    vector<Bug> bugs;
};