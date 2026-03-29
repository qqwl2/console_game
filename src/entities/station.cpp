#include "src/core/input.hpp"
#include <include/entities/station.hpp>
#include <include/utils/constants.hpp>
#include <iostream>

Station::Station(Module_factory& _module_factory, Robot_factory& _robot_factory)
  : name("")
  , day(1)
  , resources_manager(1000, 1000, 10000, 10000)
  , robot_manager()
  , module_manager()
  , events()
  , module_factory(_module_factory)
  , robot_factory(_robot_factory) {
  name = get_station_name();

  for (int i = 0; i < 2; i++) {
    robot_manager.add_robot(robot_factory, "integrator");
    robot_manager.add_robot(robot_factory, "keeper");
  }

  module_manager.add_module(module_factory, "archive");
  module_manager.add_module(module_factory, "living_place");
  module_manager.add_module(module_factory, "command_center");
  module_manager.add_module(module_factory, "generator");

  events.add_events("Создана станция с именем " + name);
}
int
Station::new_day() {
  // 0 - станция разрушается
  // 1 - станция в порядке
  day++;

  int total_bits = robot_manager.calculate_bits() + module_manager.calculate_bits();
  resources_manager.add_bits(total_bits);
  int total_energy = robot_manager.calculate_energy() + module_manager.calculate_energy();
  resources_manager.add_energy(total_energy);

  robot_manager.robot_placement(module_manager.calculate_alive_places());
  robot_manager.damage_robots();
  robot_manager.repair_robots(resources_manager);
  robot_manager.delete_corpse();
  robot_manager.robot_new_day();

  int signal_chance = calculate_signal_chance();
  if (signal_chance > 50) {
    resources_manager.add_bits(500);
  }

  if (resources_manager.get_bits() <= 0 || resources_manager.get_energy() <= 0) {
    return 0;
  }
  return 1;
}
int
Station::calculate_signal_chance() {
  int total_power = module_manager.calculate_energy() + robot_manager.calculate_energy();
  int interference = robot_manager.get_number_of_robots() * INTERFERENCE_FACTOR;
  int probability = (100 * total_power) / (total_power + interference + 1);
  if (probability < 0) {
    probability = 0;
  }
  return probability;
}
Resources_manager&
Station::get_resources_manager() {
  return resources_manager;
}
Robot_manager&
Station::get_robot_manager() {
  return robot_manager;
}
Module_manager&
Station::get_module_manager() {
  return module_manager;
}
Event&
Station::get_events() {
  return events;
}
int
Station::robot_purchase(const std::string type, const int _energy, const int _bits) {
  if (resources_manager.get_bits() >= _bits && resources_manager.get_energy() >= _energy) {
    resources_manager.add_energy(-1 * _energy);
    resources_manager.add_bits(-1 * _bits);
    robot_manager.add_robot(robot_factory, type);
    return 1;
  }
  return 0;
}
int
Station::module_purchase(const std::string type, const int _energy, const int _bits) {
  if (resources_manager.get_bits() >= _bits && resources_manager.get_energy() >= _energy) {
    resources_manager.add_energy(-1 * _energy);
    resources_manager.add_bits(-1 * _bits);
    module_manager.add_module(module_factory, type);
    return 1;
  }
  return 0;
}