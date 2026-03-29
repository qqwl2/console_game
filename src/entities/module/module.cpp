#include <include/entities/module.hpp>

Module::Module(int id)
  : id(id)
  , level(1)
  , is_active(true)
  , energy(0)
  , bits(0)
  , upgrade_cost(250) {}

const int
Module::get_energy() const {
  if (is_active) {
    return energy;
  }
  return 0;
}
const int
Module::get_bits() const {
  if (is_active) {
    return bits;
  }
  return 0;
}
const std::string
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
const int
Module::get_alive_places() const {
  return 0;
}
const int
Module::get_upgrade_cost() const {
  return upgrade_cost;
}
const int
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