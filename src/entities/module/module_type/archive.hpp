#pragma once
#include <include/entities/module.hpp>

class Archive : public Module {
public:
  Archive(int _id);
  void        upgrade() override;
  std::string get_name() const override;
};