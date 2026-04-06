#include "generator.hpp"
#include <include/utils/constants.hpp>

Generator::Generator(int _id)
  : Module(_id) {
  energy = 40;
}
void
Generator::upgrade() {
  level++;
  energy += 10;
  upgrade_cost *= UPGRADE_COST_FACTOR;
}
std::string
Generator::get_name() const {
  return "Generator";
}