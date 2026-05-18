#pragma once
#include <include/core/commands/command.hpp>

class End_game : public Command {
public:
  void execute(Station& station, Iinterface& interface) override;
};