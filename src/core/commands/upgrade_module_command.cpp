#include <include/core/commands/upgrade_module_command.hpp>

void
Upgrade_module_command::execute(Station& station, Iinterface& interface) {
  int module_upgrade_menu = 0;
  for (;;) {
    interface.clear();
    interface.panel_module_toggle(station);
    module_upgrade_menu =
      interface.request_value(0, station.get_module_manager().get_number_of_modules());
    if (module_upgrade_menu == 0) {
      return;
    } else if (station.get_module_manager().module_upgrade(station.get_resources_manager(),
                                                           module_upgrade_menu - 1)) {
      station.get_events().add_events("Модуль был улучшен", station.get_days());
    } else {
      interface.resources_deficit();
    }
    interface.delay(300);
  }
}