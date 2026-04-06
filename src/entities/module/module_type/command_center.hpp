#pragma once
#include <include/entities/module.hpp>

class Command_center : public Module {
public:
  Command_center(int _id);
  void        upgrade() override;
  std::string get_name() const override;
  int         toggle_active() override;
};