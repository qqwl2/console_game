#pragma once
#include <include/entities/robot.hpp>

class Integrator : public Robot {
public:
  Integrator(const int _id, const float _resources_efficiency);
  std::string get_type_str() const override;
};