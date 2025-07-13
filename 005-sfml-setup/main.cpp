#include <SFML/Graphics.hpp>

// the following are included transitively in <SFML/Graphics.hpp>
// #include <SFML/System.hpp>
// #include <SFML/Window.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML with Homebrew Setup Guide");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Red);

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent())
      if (event->is<sf::Event::Closed>())
        window.close();

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}
