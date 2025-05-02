#include "src/components.hpp"
#include "src/entity.hpp"
#include "src/inits.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
using Player =
    entity<updateable<sf::RectangleShape>, entity_shape<sf::RectangleShape>,
           drawable<sf::RectangleShape>>;
int main() {
  auto window =
      sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Bullet Hell Game");
  window.setFramerateLimit(60);
  Player player(updateable<sf::RectangleShape>(0, sf::Vector2f(2.5f, 3.f)),
                entity_shape<sf::RectangleShape>(
                    sf::Vector2f(32.f, 32.f), sf::Vector2f(), sf::Color::Red),
                drawable<sf::RectangleShape>());
  initializer::init_shape_pointers<Player, sf::RectangleShape>(&player);
  while (window.isOpen()) {
    /* add delta time
    time = clock.restart();
    float dt = time.asSeconds();
    */
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }
    player.update(); // make loops for update and draw

    window.clear();
    player.draw(window);
    window.display();
  }
}