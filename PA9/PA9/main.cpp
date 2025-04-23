#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.hpp"
#include "Platform.hpp"
#include "Enemy.hpp"


int main() {
    Clock clock;
    RenderWindow window(VideoMode{ {800, 600} }, "Game Object Demo");
    Player player({ 100.f, 100.f });
    Enemy e1({ 110.f, 115.f });
    Map map;
    vector<Platform> platforms;

    while (window.isOpen()) {

        float deltaTime = clock.restart().asSeconds();
        while (const optional event = window.pollEvent()) {
            if (event->is<Event::Closed>())
                window.close();
        }

        // Update logic
        player.update(deltaTime, map);

        

        // Render
        window.clear();
        player.render(window);
        window.display();
    }

    return 0;
}
