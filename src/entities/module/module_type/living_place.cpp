#include "living_place.hpp"
#include <include/utils/constants.hpp>

constexpr int ALIVE_PLACES = 8;

Living_place::Living_place(int _id)
  : Module(_id)
  , alive_places(ALIVE_PLACES) {}
void
Living_place::upgrade() {
  level++;
  alive_places += 2;
  upgrade_cost *= UPGRADE_COST_FACTOR;
}
std::string
Living_place::get_name() const {
  return "Living place";
}
int
Living_place::get_alive_places() const {
  if (is_active) {
    return alive_places;
  }
  return 0;
}
void
Living_place::storm_reaction() {
  upgrade_cost += 20;
};