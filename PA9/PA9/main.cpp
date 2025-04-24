#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.hpp"
#include "Platform.hpp"
#include "Map.hpp"
#include "BugManager.hpp"
#include "ourLibrary.h"

int main() {
    Clock clock;
    RenderWindow window(VideoMode::getDesktopMode(), "Game Object Demo");
    sf::Texture background;
    background.loadFromFile("BackgroundImage.png");
    sf::Sprite backgroundSprite(background);
    //vector<Platform>& platformVector;
    Vector2f spawnPos(100, 100);
    Player player(spawnPos);
    BugManager bugManager;
    sf::View camera;
    camera.setSize(Vector2f(800, 600));
    camera.setCenter(Vector2f(400, 300));
    Platform platforms;
    sf::Image image;
    image.loadFromFile("DemoLevel.png");
    bugManager.LoadFromImage(image);
    platforms.LoadFromImage(image);

    sf::Font font("OptimusPrinceps.ttf");
    sf::Text deathText(font);
    deathText.setString("You Died!");
    deathText.setCharacterSize(100);
    deathText.setFillColor(sf::Color::Red);
    deathText.setStyle(sf::Text::Bold);

    sf::Text restartText(font);
    restartText.setString("Press R to Restart");
    restartText.setCharacterSize(20);
    restartText.setFillColor(sf::Color::White);
    restartText.setStyle(sf::Text::Bold);

    sf::Text victoryText(font);
    victoryText.setString("Thanks for Playing Demo\n Byte Me!");
    victoryText.setCharacterSize(30);
    victoryText.setFillColor(sf::Color::Red);
    victoryText.setStyle(sf::Text::Bold);

    //map.createTest(11, 11);
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        while (const optional event = window.pollEvent()) {
            if (event->is<Event::Closed>())
                window.close();
        }

    

        window.clear();
        camera.setCenter(player.getPosition());
        window.setView(camera);
        sf::Vector2f viewSize = camera.getSize();
        sf::Vector2f viewCenter = camera.getCenter();

        sf::Vector2u textureSize = background.getSize();
        backgroundSprite.setScale(Vector2f(viewSize.x / textureSize.x, viewSize.y / textureSize.y));
        backgroundSprite.setPosition(Vector2f(viewCenter.x - viewSize.x / 2, viewCenter.y - viewSize.y / 2));
        
        window.draw(backgroundSprite);
        platforms.render(window);
        bugManager.render(window);
        
        if (!player.checkDead()) {
            player.render(window);
            player.update(deltaTime, platforms, bugManager.getBugs());
            bugManager.update(deltaTime, platforms);
        }
        if (player.checkDead()) {
            deathText.setPosition(window.getView().getCenter() - Vector2f({175, 100}));
            window.draw(deathText);
            restartText.setPosition(window.getView().getCenter() - Vector2f({ 175, 100 }));
            window.draw(restartText);
                if (isKeyPressed(Key::R)) {
                    player.resetState(spawnPos);
            }
        }
        else if (player.checkVictory()) {
            victoryText.setPosition(window.getView().getCenter() - Vector2f({ 175, 100 }));
            window.draw(victoryText);
            restartText.setPosition(window.getView().getCenter() - Vector2f({ 175, 100 }));
            window.draw(restartText);
            if (isKeyPressed(Key::R)) {
                player.resetState(spawnPos);
            }
        }
        window.display();
    }

    return 0;
}
