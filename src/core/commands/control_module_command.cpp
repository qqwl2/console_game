#include <include/core/commands/control_module_command.hpp>

void
Control_module_command::execute(Station& station, Iinterface& interface) {
  int module_toggle_menu = 0;
  for (;;) {
    interface.clear();
    interface.panel_module_toggle(station);
    module_toggle_menu =
      interface.request_value(0, station.get_module_manager().get_number_of_modules());
    if (module_toggle_menu == 0) {
      return;
    } else if (station.get_module_manager().module_toggle(module_toggle_menu - 1)) {
      station.get_events().add_events("Модуль был переключен", station.get_days());
    } else {
      interface.problem_output("Это нельзя отключать");
    }
    interface.delay(300);
  }
}