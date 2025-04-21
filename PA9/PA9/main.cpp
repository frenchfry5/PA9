#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.hpp"
#include "Platform.hpp"
#include "Map.hpp"
#include "ourLibrary.h"

int main() {
    Clock clock;
    RenderWindow window(VideoMode{ {800, 600} }, "Game Object Demo");
    //vector<Platform>& platformVector;
    Player player({ 100, 100 });
    Map map;
    sf::Image image;
    image.loadFromFile("DemoMap.png");
    map.LoadFromImage(image);
    //map.createTest(11, 11);
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        while (const optional event = window.pollEvent()) {
            if (event->is<Event::Closed>())
                window.close();
        }

        // Update logic
        player.update(deltaTime);
      
        // Render
        window.clear();
        map.Draw(window);
        player.render(window);
        window.display();
    }

    return 0;
}
