#include "entity.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <functional>
#include <type_traits>
#pragma once
template<typename E>
concept entity_ = std::is_base_of_v<entity_base, E>;
template <typename T>
concept multiplicable = requires() { std::is_same_v<std::multiplies<T>(), T>; };

template <typename D>
concept drawable_ =  std::is_base_of_v<sf::Drawable, D>;