#pragma once
#include <include/core/commands/command.hpp>

class Buy_robot_command : public Command {
public:
  void execute(Station& station, Iinterface& interface) override;
};