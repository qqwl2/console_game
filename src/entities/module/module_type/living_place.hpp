#pragma once
#include <include/entities/module.hpp>

class Living_place : public Module {
private:
  int alive_places;

public:
  Living_place(int _id);
  void        upgrade() override;
  std::string get_name() const override;
  int         get_alive_places() const override;
  void        storm_reaction() override;
};