#include <include/entities/managers/module_manager.hpp>
#include <include/entities/managers/resources_manager.hpp>
#include <include/entities/managers/robot_manager.hpp>
#include <include/entities/module.hpp>
#include <include/entities/robot.hpp>
#include <include/entities/station.hpp>
#include <include/utils/ostream_operators.hpp>
#include <iomanip>
#include <iostream>

std::ostream&
operator<<(std::ostream& os, Station& station) {
  os << "                " << "----------------------" << std::endl;
  os << "                | " << std::setw(12) << station.name << " | " << std::setw(3)
     << station.day << " |" << std::endl;
  os << "                " << "----------------------" << std::endl;
  os << "Шанс сигнала: " << station.calculate_signal_chance() << "%" << std::endl;
  return os;
}
std::ostream&
operator<<(std::ostream& os, const Robot& robot) {
  os << "| " << std::setw(6) << robot.get_type_str() << " | " << std::setw(12) << robot.name
     << " | " << std::setw(3) << robot.energy << " энергии " << std::setw(3) << robot.bits
     << " битов"
     << " | " << std::setw(3) << robot.chassis_integrity << "% и " << std::setw(3)
     << robot.firmware_integrity << "% |  " << std::setw(2) << robot.day << " |" << std::endl;
  return os;
}
std::ostream&
operator<<(std::ostream& os, const Module& module) {
  os << std::left << std::setw(16) << module.get_name() << std::right << std::setw(6)
     << " (Lvl " + std::to_string(module.level) + ")" << " : " << std::setw(8)
     << module.get_is_active_str() << " (Энергия: " << std::setw(4) << module.energy
     << ", Биты: " << std::setw(4) << module.bits << ")" << std::endl;
  return os;
}
std::ostream&
operator<<(std::ostream& os, const Resources_manager& resources_manager) {
  os << "                [РЕСУРСЫ]" << std::endl;
  os << std::setw(20)
     << "Энергия: " + std::to_string(resources_manager.energy) + " / " +
          std::to_string(resources_manager.energy_max)
     << std::endl;
  os << std::setw(20)
     << "Биты: " + std::to_string(resources_manager.bits) + " / " +
          std::to_string(resources_manager.bits_max)
     << std::endl;
  return os;
}
std::ostream&
operator<<(std::ostream& os, const Robot_manager& robot_manager) {
  int i = 1;
  os << "               [НАСЕЛЕНИЕ]" << std::endl;
  os << "     | Тип    | Имя          |    Энергия и Биты     | Шасси и ПО  | Дни |" << std::endl;
  for (auto& robot : robot_manager.robots) {
    os << "[" << std::setw(2) << i << "] " << *robot;
    i++;
  }
  return os;
}
std::ostream&
operator<<(std::ostream& os, const Module_manager& module_manager) {
  int i = 1;
  os << "                [МОДУЛИ]" << std::endl;
  for (auto& module : module_manager.modules) {
    os << "[" << std::setw(2) << i << "] " << *module;
    i++;
  }
  return os;
}
std::ostream&
operator<<(std::ostream& os, const Event& event) {
  os << "                [СОБЫТИЯ]" << std::endl;
  for (auto& event : event.events) {
    os << event << std::endl;
  }
  return os;
}