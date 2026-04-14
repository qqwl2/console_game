#include <include/core/commands/synthesis_robot_command.hpp>

void
Synthesis_robot_command::execute(Station& station, Iinterface& interface) {
  int first_robot_menu = 0;
  int second_robot_menu = 0;
  for (;;) {
    interface.clear();
    interface.robot_synthesis(station);
    first_robot_menu =
      interface.request_value(0, station.get_robot_manager().get_number_of_robots());
    second_robot_menu =
      interface.request_value(0, station.get_robot_manager().get_number_of_robots());
    if (first_robot_menu == 0 || second_robot_menu == 0) {
      return;
    } else if (first_robot_menu == second_robot_menu) {
      interface.problem_output("Роботы не могут быть одинаковые");
    } else if (station.get_robot_manager().synthesis(first_robot_menu - 1, second_robot_menu - 1)) {
      station.get_events().add_events("Робот был синтезирован", station.get_days());
    }
    interface.delay(300);
  }
}