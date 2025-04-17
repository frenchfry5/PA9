#include <SFML/Graphics.hpp>
#include "Player.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Platformer Test");
    window.setFramerateLimit(60);

    Player player({ 100.f, 100.f });

    sf::RectangleShape ground;
    ground.setSize({ 800.f, 100.f });
    ground.setFillColor(sf::Color(100, 100, 100));
    ground.setPosition(0.f, 500.f);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        player.update(deltaTime);

        window.clear(sf::Color::Black);
        player.render(window);
        window.draw(ground);
        window.display();
    }

    return 0;
}
