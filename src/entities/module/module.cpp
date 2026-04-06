#include <include/entities/module.hpp>

Module::Module(int _id)
  : id(_id)
  , level(1)
  , is_active(true)
  , energy(0)
  , bits(0)
  , upgrade_cost(250) {}

int
Module::get_energy() const {
  if (is_active) {
    return energy;
  }
  return 0;
}
int
Module::get_bits() const {
  if (is_active) {
    return bits;
  }
  return 0;
}
std::string
Module::get_is_active_str() const {
  if (is_active) {
    return "АКТИВЕН";
  }
  return "ВЫКЛЮЧЕН";
}
int
Module::toggle_active() {
  is_active = !is_active;
  return 1;
}
int
Module::get_alive_places() const {
  return 0;
}
int
Module::get_upgrade_cost() const {
  return upgrade_cost;
}
int
Module::get_id() const {
  return id;
}
Module*
Module::operator+(const Module& _module) {
  if (this->get_name() == _module.get_name() && this->level == _module.level) {
    this->upgrade();
    return this;
  }
  return nullptr;
}