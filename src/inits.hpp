#include "components.hpp"
#include "concepts.hpp"
#include <type_traits>
#pragma once
class initializer {
public:
  template <entity_ e, drawable_ d> static void init_shape_pointers(e *entity) {
   // make sure that entity has shape of type d
    if constexpr (std::is_convertible_v<decltype(entity), updateable<d> *>)
      static_cast<updateable<d> *>(entity)->init_pointer_to_shape(
          &(entity->shape));
    if constexpr (std::is_convertible_v<decltype(entity), drawable<d> *>)
      static_cast<drawable<d> *>(entity)->init_pointer_to_shape(&(entity->shape));
  }
};