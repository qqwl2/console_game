#pragma once
#include <include/core/commands/command.hpp>

class Synthesis_robot_command : public Command {
public:
  void execute(Station& station, Iinterface& interface) override;
};