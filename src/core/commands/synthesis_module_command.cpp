#include <include/core/commands/synthesis_module_command.hpp>

void
Synthesis_module_command::execute(Station& station, Iinterface& interface) {
  int first_module_menu = 0;
  int second_module_menu = 0;
  for (;;) {
    interface.clear();
    interface.module_synthesis(station);
    first_module_menu =
      interface.request_value(0, station.get_module_manager().get_number_of_modules());
    second_module_menu =
      interface.request_value(0, station.get_module_manager().get_number_of_modules());
    if (first_module_menu == 0 || second_module_menu == 0) {
      return;
    } else if (first_module_menu == second_module_menu) {
      interface.problem_output("Модули не могут быть одинаковые");
    } else if (station.get_module_manager().synthesis(first_module_menu - 1,
                                                      second_module_menu - 1)) {
      station.get_events().add_events("Модуль был синтезирован", station.get_days());
    }
    interface.delay(300);
  }
}