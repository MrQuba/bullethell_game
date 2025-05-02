#pragma once
#include "mover.hpp"
#include "concepts.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>

template <multiplicable T>
sf::Vector2<T> operator*(const sf::Vector2<T> a,
                                const sf::Vector2<T> b) {
  return sf::Vector2<T>(a.x * b.x, a.y * b.y);
}

template <drawable_ d>
struct shape_pointer{
  void init_pointer_to_shape(d* shape) {
    shape_ = std::shared_ptr<d>(shape);
  }
  std::shared_ptr<d> shape_;
};

template <drawable_ d>
struct updateable : public shape_pointer<d> {
  constexpr updateable(const short movement_type, const sf::Vector2f velocity,
                       const bool collidable = true, const short ai_type = -1)
      : movement_(movement_type), ai_(ai_type), collidable_(collidable),
        velocity_(velocity) {}
  void update() {
    mover::move<d>[movement_](velocity_, this->shape_);
  }
private:
  const short movement_;
  const short ai_;
  const bool collidable_;
  const sf::Vector2f velocity_;
};
template <drawable_ d>
struct drawable : public shape_pointer<d>  {
  drawable() = default;
  void draw(sf::RenderWindow &w) { w.draw(*this->shape_); }
};
template <drawable_ d>
struct entity_shape {
  entity_shape() = default;
  entity_shape(sf::Vector2f s, sf::Vector2f pos, sf::Color c) {
    if constexpr (std::is_base_of_v<sf::RectangleShape, d>) {
      shape.setSize(s);
      shape.setFillColor(c);
      shape.setPosition(pos);
    }
  }
  d shape;
};