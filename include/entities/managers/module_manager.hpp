#pragma once
#include <include/entities/factory.hpp>
#include <include/entities/managers/resources_manager.hpp>
#include <include/entities/module.hpp>
#include <iostream>
#include <vector>

class Module_manager {
  friend std::ostream& operator<<(std::ostream& os, const Module_manager& module_manager);

private:
  std::vector<std::unique_ptr<Module>> modules;

  int module_id;

public:
  void add_module(Module_factory& module_factory, std::string type);

  const int calculate_energy();
  const int calculate_bits();
  const int calculate_alive_places();
  const int get_number_of_modules() const;
  int       module_upgrade(Resources_manager& resources_manager, const int _index);
  int       module_toggle(const int _index);
  int       synthesis(const int _first_index, const int _second_index);
  void      remove_module(const int _id);
};