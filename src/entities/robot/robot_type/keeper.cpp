#include "keeper.hpp"
#include "src/utils/utils.hpp"

std::string
generate_keeper_name() {
  std::string name;
  name += (char)(rand() % ('Z' - 'A') + 'A');
  for (int i = 0; i < 11; i++) {
    name += (char)(rand() % ('z' - 'a') + 'a');
  }
  return name;
}

Keeper::Keeper(const int _id, const float _resources_efficiency)
  : Robot(_id, _resources_efficiency) {
  name = generate_keeper_name();
  bits = static_cast<int>(10.0 * resources_efficiency);
  energy = static_cast<int>(5.0 * resources_efficiency);
  occupied_place = 2;
}
std::string
Keeper::get_type_str() const {
  return "KEEPER";
}
void
Keeper::storm_reaction() {
  if (random(-1, 1) > 0) {
    energy++;
  } else {
    energy--;
  };
};