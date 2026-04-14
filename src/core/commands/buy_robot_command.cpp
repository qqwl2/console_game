#include <include/core/commands/buy_robot_command.hpp>
#include <include/utils/constants.hpp>

void
Buy_robot_command::execute(Station& station, Iinterface& interface) {
  int robot_purchase_menu = 0;
  for (;;) {
    interface.clear();
    interface.panel_robot_purchase(PURCHASE_COST, PURCHASE_COST);
    robot_purchase_menu = interface.request_value(0, 2);
    switch (robot_purchase_menu) {
      case 0:
        return;
      case 1:
        if (station.robot_purchase("keeper", PURCHASE_COST, PURCHASE_COST * 2)) {
          station.get_events().add_events("keeper был куплен", station.get_days());
          break;
        }
        interface.resources_deficit();
        break;
      case 2:
        if (station.robot_purchase("integrator", PURCHASE_COST * 2, PURCHASE_COST)) {
          station.get_events().add_events("integrator был куплен", station.get_days());
          break;
        }
        interface.resources_deficit();
        break;
    }
    interface.delay(300);
  }
}