#include "command_center.hpp"
#include <include/utils/constants.hpp>

Command_center::Command_center(int id)
  : Module(id) {
  energy = -50;
}
void
Command_center::upgrade() {
  level++;
  energy += 5;
  bits += 5;
  upgrade_cost *= UPGRADE_COST_FACTOR;
}
const std::string
Command_center::get_name() const {
  return "Command center";
}
int Command_center::toggle_active(){
  return 0;
}