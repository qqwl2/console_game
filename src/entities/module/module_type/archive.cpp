#include "archive.hpp"
#include <include/utils/constants.hpp>

Archive::Archive(int id)
  : Module(id) {
  energy = -5;
  bits = 5;
}
void
Archive::upgrade() {
  level++;
  energy -= 5;
  bits += 5;
  upgrade_cost *= UPGRADE_COST_FACTOR;
}
const std::string
Archive::get_name() const {
  return "Archive";
}