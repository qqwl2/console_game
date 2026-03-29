#pragma once
#include <include/graphics/Iinterface.hpp>

class Console_interface : public Iinterface {
  void delay(unsigned long milliseconds) override;
  void clear() override;
  void update_main(Station& station) override;
  void panel_module_toggle(Station& station) override;
  void panel_module_upgrade(Station& station) override;
  void panel_module_purchase(Station& station, int energy_cost, int bits_cost) override;
  void panel_robot_purchase(Station& station, int energy_cost, int bits_cost) override;
  void resources_deficit() override;
  void bad_end() override;
  void module_synthesis(Station& station) override;
  void robot_synthesis(Station& station) override;
  void problem_output(std::string problem) override;

  int request_value(int min, int max) override;
};