#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.hpp"
#include "Platform.hpp"
#include "ourLibrary.h"

int main() {
    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode{ {800, 600} }, "Game Object Demo");
    Player player({ 100.f, 100.f });

    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Update logic
        player.update(deltaTime);

        

        // Render
        window.clear();
        player.render(window);
        window.display();
    }

    return 0;
}
