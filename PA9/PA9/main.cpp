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
    RenderWindow window(VideoMode::getDesktopMode(), "Game Object Demo");
    //vector<Platform>& platformVector;
    Vector2f spawnPos(100, 100);
    Player player(spawnPos);
    Bug bug({ 150, 150 });
    sf::View camera;
    camera.setSize(Vector2f(800, 600));
    camera.setCenter(Vector2f(400, 300));
    Platform platforms;
    sf::Image image;
    image.loadFromFile("DemoMap2.png");
    platforms.LoadFromImage(image);

    sf::Font font("OptimusPrinceps.ttf");
    sf::Text deathText(font);
    deathText.setString("You Died!");
    deathText.setCharacterSize(100);
    deathText.setFillColor(sf::Color::Red);
    deathText.setStyle(sf::Text::Bold);
    deathText.setPosition({ 100, 100 });  // Adjust to center

    sf::Text restartText(font);
    restartText.setString("Press R to Restart");
    restartText.setCharacterSize(20);
    restartText.setFillColor(sf::Color::White);
    restartText.setStyle(sf::Text::Bold);

    //map.createTest(11, 11);
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        while (const optional event = window.pollEvent()) {
            if (event->is<Event::Closed>())
                window.close();
        }

        // Update logic


        camera.setCenter(player.getPosition());
        window.setView(camera);
        // Render
        window.clear();
        platforms.render(window);
        bug.render(window);
        if (!player.checkDead()) {
            player.render(window);
            player.update(deltaTime, platforms, bug);
            bug.update(deltaTime, platforms);
        }
        if (player.checkDead()) {
            deathText.setPosition(window.getView().getCenter() - Vector2f({175, 100}));
            window.draw(deathText);
            restartText.setPosition(window.getView().getCenter() - Vector2f({ 175, 100 }));
            window.draw(restartText);\
                if (isKeyPressed(Key::R)) {
                    player.resetState(spawnPos);
            }
        }

        window.display();
    }

    return 0;
}
