#include "src/core/input.hpp"
#include "src/utils/utils.hpp"
#include <format>
#include <include/entities/factory.hpp>
#include <include/entities/station.hpp>
#include <include/entities/storm_errors.hpp>
#include <include/utils/constants.hpp>
#include <iostream>
#include <memory>

Station&
Station::get_instance() {
  static Station instance;
  return instance;
}

Station::Station()
  : name("")
  , day(1)
  , subject()
  , resources_manager(1000, 1000, MAX_ENERGY, MAX_BITS)
  , robot_manager(subject)
  , module_manager(subject)
  , events()
  , module_factory()
  , robot_factory()
  , storm_days(0) {
  name = get_station_name();

  for (int i = 0; i < 2; i++) {
    robot_manager.add_robot(robot_factory, "integrator");
    robot_manager.add_robot(robot_factory, "keeper");
  }

  module_manager.add_module(module_factory, "archive");
  module_manager.add_module(module_factory, "living_place");
  module_manager.add_module(module_factory, "command_center");
  module_manager.add_module(module_factory, "generator");

  events.add_events("Создана станция с именем " + name, day);
}

void
throw_storm_error() {
  if (static_cast<int>(random(0, 100)) > 50) {
    return;
  }
  int storm_error = static_cast<int>(random(0, 100));
  if (storm_error < 33) {
    throw Power_surge_exception();
  } else if (storm_error < 66) {
    throw Firmware_glitch_exception();
  } else {
    throw Meteor_strike_exception();
  }
}

void
Station::storm_errors() {
  if (day < DAY_BEFORE_STORM) {
    return;
  }
  if (storm_days > 0) {
    return;
  }
  int strom_chance = static_cast<int>(random(0, 100));
  if (strom_chance > STORM_CHANCE) {
    return;
  }
  storm_days = static_cast<int>(random(2, 5));
}
void
Station::error_handling() {
  bool event_hapenned = false;
  try {
    storm_errors();
    if (storm_days != 0) {
      events.add_events(
        std::format("Станция попала в шторм.. До конца шторма: {} дней", storm_days), day);
      storm_days--;
      throw_storm_error();
    }
  } catch (const Power_surge_exception& e) {
    events.add_events(e.what(), day);
    resources_manager.add_energy(-50);
    event_hapenned = true;
  } catch (const Firmware_glitch_exception& e) {
    events.add_events(e.what(), day);
    robot_manager.damage_firmware(10);
    event_hapenned = true;
  } catch (const Meteor_strike_exception& e) {
    events.add_events(e.what(), day);
    module_manager.module_toggle(
      static_cast<int>(random(0, static_cast<double>(module_manager.get_number_of_modules()))));
    event_hapenned = true;
  }
  if (event_hapenned) {
    subject.set_event("storm");
    subject.notify();
  }
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

  if (!storm_days) {
    int signal_chance = calculate_signal_chance();
    if (signal_chance > 50) {
      resources_manager.add_bits(500);
    }
  }
  error_handling();
  if (resources_manager.get_bits() <= 0 || resources_manager.get_energy() <= 0) {
    return 0;
  }
  return 1;
}
int
Station::calculate_signal_chance() {
  if (storm_days) {
    return 0;
  }
  int total_power = module_manager.calculate_energy() + robot_manager.calculate_energy();
  int interference = static_cast<int>(robot_manager.get_number_of_robots()) * INTERFERENCE_FACTOR;
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
Station::get_days() const {
  return day;
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
std::string
Station::get_end_game_stats() const {
  std::string msg;
  msg += "Дни: " + std::to_string(get_days()) + "\n";
  msg += "Количество роботов: " + std::to_string(robot_manager.get_number_of_robots()) + "\n";
  msg += "Количество модулей: " + std::to_string(module_manager.get_number_of_modules()) + "\n";
  int scores = robot_manager.calculate_bits() + module_manager.calculate_bits() +
               robot_manager.calculate_energy() + module_manager.calculate_energy() +
               10 * static_cast<int>(robot_manager.get_number_of_robots()) +
               20 * static_cast<int>(module_manager.get_number_of_modules());
  msg += "Заработанные очки: " + std::to_string(scores) + "\n";
  return msg;
}
bool
Station::end_game() const {
  if (resources_manager.get_bits() >= END_GAME_BITS_COST &&
      resources_manager.get_energy() >= END_GAME_ENEGY_COST) {
    return true;
  }
  return false;
}