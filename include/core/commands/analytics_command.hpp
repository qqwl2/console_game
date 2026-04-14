#pragma once
#include <include/core/commands/command.hpp>

class Analytics_command : public Command {
public:
  void execute(Station& station, Iinterface& interface) override;
};