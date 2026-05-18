#include "archive.hpp"
#include <include/utils/constants.hpp>

Archive::Archive(int _id)
  : Module(_id) {
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
std::string
Archive::get_name() const {
  return "Archive";
}
void
Archive::storm_reaction() {
  upgrade();
  energy += 5;
};