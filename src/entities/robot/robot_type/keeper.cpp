#include "keeper.hpp"

std::string
generate_keeper_name() {
  std::string name;
  name += (char)(rand() % ('Z' - 'A') + 'A');
  for (int i = 0; i < 11; i++) {
    name += (char)(rand() % ('z' - 'a') + 'a');
  }
  return name;
}

Keeper::Keeper(const int id, const float resources_efficiency)
  : Robot(id, resources_efficiency) {
  name = generate_keeper_name();
  bits = 10 * resources_efficiency;
  energy = 5 * resources_efficiency;
  occupied_place = 2;
}
std::string
Keeper::get_type_str() const {
  return "KEEPER";
}