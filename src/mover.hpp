#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <array>
#include <memory>
class mover{
public:
template <typename d>
  requires std::is_base_of_v<sf::Drawable, d>
static void generic_move(const sf::Vector2f v, std::shared_ptr<d> p, const std::array<sf::Keyboard::Key, 4> keys){
    sf::Vector2f v_;
    if(sf::Keyboard::isKeyPressed(keys[0])) v_.y -= v.y;
    if(sf::Keyboard::isKeyPressed(keys[1])) v_.y += v.y;
    if(sf::Keyboard::isKeyPressed(keys[2])) v_.x -= v.x;
    if(sf::Keyboard::isKeyPressed(keys[3])) v_.x += v.y;
    p->move(v_);

}
template <typename d>
  requires std::is_base_of_v<sf::Drawable, d>
static void wsad(const sf::Vector2f v, std::shared_ptr<d> p){
    using namespace sf::Keyboard;
    generic_move(v, p, {Key::W, Key::S, Key::A, Key::D});
}
template <typename d>
  requires std::is_base_of_v<sf::Drawable, d>
static constexpr std::array<void(*)(const sf::Vector2f v, std::shared_ptr<d> p),2> move {wsad};
};