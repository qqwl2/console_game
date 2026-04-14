#pragma once
#include <include/core/commands/command.hpp>

class Control_module_command : public Command {
public:
  void execute(Station& station, Iinterface& interface) override;
};