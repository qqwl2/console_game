#include "src/utils/utils.hpp"
#include <include/entities/factory.hpp>
#include <iostream>
#include <stdexcept>

#include "src/entities/robot/robot_type/integrator.hpp"
#include "src/entities/robot/robot_type/keeper.hpp"

Robot_factory::Robot_factory() {
  creators["integrator"] = [](int id) {
    return std::make_unique<Integrator>(id, random(0.5, 1.5));
  };
  creators["keeper"] = [](int id) { return std::make_unique<Keeper>(id, random(0.5, 1.5)); };
}
std::unique_ptr<Robot>
Robot_factory::create(const std::string& type, int id) {
  auto iterator = creators.find(type);
  if (iterator != creators.end()) {
    return iterator->second(id);
  }
  throw std::invalid_argument("Неизвестный тип робота: " + type);
  return nullptr;
}

#include "src/entities/module/module_type/archive.hpp"
#include "src/entities/module/module_type/command_center.hpp"
#include "src/entities/module/module_type/generator.hpp"
#include "src/entities/module/module_type/living_place.hpp"

Module_factory::Module_factory() {
  creators["archive"] = [](int id) { return std::make_unique<Archive>(id); };
  creators["command_center"] = [](int id) { return std::make_unique<Command_center>(id); };
  creators["generator"] = [](int id) { return std::make_unique<Generator>(id); };
  creators["living_place"] = [](int id) { return std::make_unique<Living_place>(id); };
}
std::unique_ptr<Module>
Module_factory::create(const std::string& type, int id) {
  auto iterator = creators.find(type);
  if (iterator != creators.end()) {
    return iterator->second(id);
  }
  throw std::invalid_argument("Неизвестный тип модуля" + type);
  return nullptr;
}