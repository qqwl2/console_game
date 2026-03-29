#pragma once
#include <include/entities/module.hpp>

class Living_place : public Module {
private:
  int alive_places;

public:
  Living_place(int id);
  void              upgrade() override;
  const std::string get_name() const override;
  const int         get_alive_places() const override;
};