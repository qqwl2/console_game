#include "integrator.hpp"
#include "src/utils/utils.hpp"

std::string
generate_integrator_name() {
  std::string name;
  name = "Series_";
  for (int i = 0; i < 5; i++) {
    name += (char)(rand() % ('9' - '0') + '0');
  }
  return name;
}

Integrator::Integrator(const int _id, const float _resources_efficiency)
  : Robot(_id, _resources_efficiency) {
  name = generate_integrator_name();
  bits = static_cast<int>(5.0 * resources_efficiency);
  energy = static_cast<int>(10.0 * resources_efficiency);
  occupied_place = 1;
}
std::string
Integrator::get_type_str() const {
  return "INTEGR";
}
void
Integrator::storm_reaction() {
  if (random(-1, 1) > 0) {
    bits++;
  } else {
    bits--;
  };
};