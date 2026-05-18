#pragma once
#include <include/entities/robot.hpp>

class Keeper : public Robot {
public:
  Keeper(const int _id, const float _resources_efficiency);
  std::string get_type_str() const override;
  void        storm_reaction() override;
};