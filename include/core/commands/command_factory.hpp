#pragma once
#include <include/core/commands/command.hpp>
#include <memory>
#include <unordered_map>

class Command_factory {
private:
  std::unordered_map<int, std::unique_ptr<Command>> commands;

public:
  Command_factory();
  Command* get(int command_number);
  int      get_number_of_commands() const;
};