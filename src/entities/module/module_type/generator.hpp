#pragma once
#include <include/entities/module.hpp>

class Generator : public Module {
public:
  Generator(int id);
  void        upgrade() override;
  const std::string get_name() const override;
};