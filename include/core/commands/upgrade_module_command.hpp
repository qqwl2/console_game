#pragma once
#include <include/core/commands/command.hpp>

class Upgrade_module_command : public Command {
public:
  void execute(Station& station, Iinterface& interface) override;
};