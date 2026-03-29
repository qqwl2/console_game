#pragma once
#include <include/entities/module.hpp>

class Archive : public Module {
public:
  Archive(int id);
  void        upgrade() override;
  const std::string get_name() const override;
};