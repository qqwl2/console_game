#include <algorithm>
#include <include/entities/managers/module_manager.hpp>

void
Module_manager::add_module(Module_factory& module_factory, const std::string type) {
  modules.push_back(module_factory.create(type, module_id++));
}

const int
Module_manager::calculate_energy() {
  int total = 0;
  for (auto& module : modules) {
    total += module->get_energy();
  }
  return total;
}
const int
Module_manager::calculate_bits() {
  int total = 0;
  for (auto& module : modules) {
    total += module->get_bits();
  }
  return total;
}
const int
Module_manager::calculate_alive_places() {
  int total = 0;
  for (auto& module : modules) {
    total += module->get_alive_places();
  }
  return total;
}
const int
Module_manager::get_number_of_modules() const {
  return modules.size();
}
int
Module_manager::module_upgrade(Resources_manager& resources_manager, const int _index) {
  int     upgrade_cost = 0;
  Module* module = modules[_index].get();
  upgrade_cost = module->get_upgrade_cost();
  if (resources_manager.get_bits() >= upgrade_cost &&
      resources_manager.get_energy() >= upgrade_cost) {
    resources_manager.add_bits(-1 * upgrade_cost);
    resources_manager.add_energy(-1 * upgrade_cost);
    module->upgrade();
    return 1;
  } else {
    return 0;
  }
  return 0;
}
int
Module_manager::module_toggle(const int _index) {
  return modules[_index]->toggle_active();
  return 0;
}
int
Module_manager::synthesis(const int _first_index, const int _second_index) {
  Module* first_module = modules[_first_index].get();
  Module* second_module = modules[_second_index].get();
  if (first_module && second_module) {
    if (*first_module + *second_module) {
      remove_module(modules[_second_index]->get_id());
      return 1;
    }
  }
  return 0;
}
void
Module_manager::remove_module(const int _id) {
  auto iterator = std::remove_if(modules.begin(), modules.end(), [_id](const auto& module) {
    return module->get_id() == _id;
  });
  modules.erase(iterator, modules.end());
}
