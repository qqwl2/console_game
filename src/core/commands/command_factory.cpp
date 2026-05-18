#include <include/core/commands/analytics_command.hpp>
#include <include/core/commands/buy_module_command.hpp>
#include <include/core/commands/buy_robot_command.hpp>
#include <include/core/commands/command.hpp>
#include <include/core/commands/command_factory.hpp>
#include <include/core/commands/control_module_command.hpp>
#include <include/core/commands/end_game.hpp>
#include <include/core/commands/next_day_command.hpp>
#include <include/core/commands/synthesis_module_command.hpp>
#include <include/core/commands/synthesis_robot_command.hpp>
#include <include/core/commands/upgrade_module_command.hpp>

Command_factory::Command_factory() {
  commands[1] = std::make_unique<Next_day_command>();
  commands[2] = std::make_unique<Buy_robot_command>();
  commands[3] = std::make_unique<Buy_module_command>();
  commands[4] = std::make_unique<Upgrade_module_command>();
  commands[5] = std::make_unique<Control_module_command>();
  commands[6] = std::make_unique<Synthesis_module_command>();
  commands[7] = std::make_unique<Synthesis_robot_command>();
  commands[8] = std::make_unique<Analytics_command>();
  commands[9] = std::make_unique<End_game>();
}
Command*
Command_factory::get(int command_number) {
  return commands[command_number].get();
}
int
Command_factory::get_number_of_commands() const {
  return static_cast<int>(commands.size());
}