#include <include/core/commands/analytics_command.hpp>

void
Analytics_command::execute(Station& station, Iinterface& interface) {
  for (;;) {
    interface.clear();
    interface.analytics();
    int request = interface.request_value(0, 3);
    switch (request) {
      case 0:
        return;
      case 1:
        interface.clear();
        station.get_robot_manager().sort_robots();
        interface.roll_call(station);
        request = interface.request_value(0, 0);
        break;
      case 2:
        interface.clear();
        station.get_module_manager().sort_modules();
        interface.inventory(station);
        request = interface.request_value(0, 0);
        break;
      case 3:
        interface.loss_assessment(station);
        interface.delay(500);
        break;
    }
  }
}