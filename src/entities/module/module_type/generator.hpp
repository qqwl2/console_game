#pragma once
#include <include/entities/module.hpp>

class Generator : public Module {
public:
  Generator(int _id);
  void        upgrade() override;
  std::string get_name() const override;
};