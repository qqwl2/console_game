#include "living_place.hpp"
#include <include/utils/constants.hpp>

constexpr int ALIVE_PLACES = 8;

Living_place::Living_place(int id)
  : Module(id)
  , alive_places(ALIVE_PLACES) {}
void
Living_place::upgrade() {
  level++;
  alive_places += 2;
  upgrade_cost *= UPGRADE_COST_FACTOR;
}
const std::string
Living_place::get_name() const {
  return "Living place";
}
const int
Living_place::get_alive_places() const {
  if (is_active) {
    return alive_places;
  }
  return 0;
}