#include "integrator.hpp"

std::string
generate_integrator_name() {
  std::string name;
  name = "Series_";
  for (int i = 0; i < 5; i++) {
    name += (char)(rand() % ('9' - '0') + '0');
  }
  return name;
}

Integrator::Integrator(const int id, const float resources_efficiency)
  : Robot(id, resources_efficiency) {
  name = generate_integrator_name();
  bits = 5 * resources_efficiency;
  energy = 10 * resources_efficiency;
  occupied_place = 1;
}
std::string
Integrator::get_type_str() const {
  return "INTEGR";
}