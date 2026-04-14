#include <include/core/commands/buy_module_command.hpp>
#include <include/utils/constants.hpp>

void
Buy_module_command::execute(Station& station, Iinterface& interface) {
  int module_purchase_menu = 0;
  for (;;) {
    interface.clear();
    interface.panel_module_purchase(PURCHASE_COST, PURCHASE_COST);
    module_purchase_menu = interface.request_value(0, 4);
    switch (module_purchase_menu) {
      case 0:
        return;
      case 1:
        if (station.module_purchase("archive", PURCHASE_COST, PURCHASE_COST)) {
          station.get_events().add_events("Архив был куплен", station.get_days());
          break;
        }
        interface.resources_deficit();
        break;
      case 2:
        if (station.module_purchase("command_center", PURCHASE_COST, PURCHASE_COST)) {
          station.get_events().add_events("Командный центр был куплен", station.get_days());
          break;
        }
        interface.resources_deficit();
        break;
      case 3:
        if (station.module_purchase("living_place", PURCHASE_COST, PURCHASE_COST)) {
          station.get_events().add_events("Жилой отсек был куплен", station.get_days());
          break;
        }
        interface.resources_deficit();
        break;
      case 4:
        if (station.module_purchase("generator", PURCHASE_COST, PURCHASE_COST)) {
          station.get_events().add_events("Генератор был куплен", station.get_days());
          break;
        }
        interface.resources_deficit();
        break;
    }
    interface.delay(300);
  }
}