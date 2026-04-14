#pragma once
#include <include/core/commands/command.hpp>

class Next_day_command : public Command {
public:
  void execute(Station& station, Iinterface& interface) override;
};