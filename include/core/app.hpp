#pragma once
#include <include/entities/station.hpp>
#include <include/graphics/Iinterface.hpp>

class App {
public:
  int run(Station& station, Iinterface& interface);
  int module_toggle(Station& station, Iinterface& interface);
  int module_upgrade(Station& station, Iinterface& interface);
  int module_purchase(Station& station, Iinterface& interface);
  int robot_purchase(Station& station, Iinterface& interface);
  int module_synthesis(Station& station, Iinterface& interface);
  int robot_synthesis(Station& station, Iinterface& interface);
};