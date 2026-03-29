#pragma once
#include <include/entities/station.hpp>

class Iinterface {
public:
  virtual void delay(unsigned long milliseconds) = 0;
  virtual void clear() = 0;
  virtual void update_main(Station& station) = 0;
  virtual void panel_module_toggle(Station& station) = 0;
  virtual void panel_module_upgrade(Station& station) = 0;
  virtual void panel_module_purchase(Station&  station,
                                     const int energy_cost,
                                     const int bits_cost) = 0;
  virtual void panel_robot_purchase(Station&  station,
                                    const int energy_cost,
                                    const int bits_cost) = 0;
  virtual void resources_deficit() = 0;
  virtual void bad_end() = 0;
  virtual void module_synthesis(Station& station) = 0;
  virtual void robot_synthesis(Station& station) = 0;
  virtual void problem_output(std::string problem) = 0;

  virtual int request_value(const int min, const int max) = 0;
};