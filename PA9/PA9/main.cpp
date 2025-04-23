#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.hpp"
#include "Platform.hpp"
#include "Bug.hpp"
#include "Map.hpp"
#include "ourLibrary.h"

int main() {
    Clock clock;
    RenderWindow window(VideoMode{ {800, 600} }, "Game Object Demo");
    //vector<Platform>& platformVector;
    Player player({ 100, 100 });
    Bug bug({ 150, 150 });
    sf::View camera;
    camera.setSize(Vector2f(800, 600));
    camera.setCenter(Vector2f(400, 300));
    Platform platforms;
    sf::Image image;
    image.loadFromFile("DemoMap2.png");
    platforms.LoadFromImage(image);
    //map.createTest(11, 11);
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        while (const optional event = window.pollEvent()) {
            if (event->is<Event::Closed>())
                window.close();
        }

        // Update logic
        player.update(deltaTime, platforms);
        bug.update(deltaTime, platforms);
        camera.setCenter(player.getPosition());
        window.setView(camera);
      
        // Render
        window.clear();
        platforms.render(window);
        player.render(window);
        bug.render(window);
        window.display();
    }

    return 0;
}
