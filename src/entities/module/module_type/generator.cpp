#include "generator.hpp"
#include <include/utils/constants.hpp>

Generator::Generator(int id)
  : Module(id) {
  energy = 40;
}
void
Generator::upgrade() {
  level++;
  energy += 10;
  upgrade_cost *= UPGRADE_COST_FACTOR;
}
const std::string
Generator::get_name() const {
  return "Generator";
}