#pragma once
#include <include/entities/robot.hpp>

class Integrator : public Robot {
public:
  Integrator(const int id, const float resources_efficiency);
  std::string get_type_str() const override;
};