#pragma once
#include <include/entities/robot.hpp>

class Keeper : public Robot {
public:
  Keeper(const int id, const float resources_efficiency);
  std::string get_type_str() const override;
};