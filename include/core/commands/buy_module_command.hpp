#pragma once
#include <include/core/commands/command.hpp>

class Buy_module_command : public Command {
public:
  void execute(Station& station, Iinterface& interface) override;
};