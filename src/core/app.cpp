#include "src/core/input.hpp"
#include <include/core/app.hpp>
#include <include/graphics/Iinterface.hpp>
#include <include/utils/constants.hpp>

int
App::run(Station& station, Iinterface& interface) {
  int menu = 0;
  for (;;) {
    interface.clear();
    interface.update_main(station);
    menu = interface.request_value(0, 7);
    switch (menu) {
      case 0:
        exit(EXIT_SUCCESS);
      case 1:
        if (station.new_day()) {
          station.get_events().remove_events();
        } else {
          interface.clear();
          interface.bad_end();
          exit(EXIT_SUCCESS);
        }
        break;
      case 2:
        robot_purchase(station, interface);
        break;
      case 3:
        module_purchase(station, interface);
        break;
      case 4:
        module_upgrade(station, interface);
        break;
      case 5:
        module_toggle(station, interface);
        break;
      case 6:
        module_synthesis(station, interface);
        break;
      case 7:
        robot_synthesis(station, interface);
        break;
    }
  }
  return 0;
}
int
App::module_toggle(Station& station, Iinterface& interface) {
  int module_toggle_menu = 0;
  for (;;) {
    interface.clear();
    interface.panel_module_toggle(station);
    module_toggle_menu =
      interface.request_value(0, station.get_module_manager().get_number_of_modules());
    if (module_toggle_menu == 0) {
      return 0;
    } else if (station.get_module_manager().module_toggle(module_toggle_menu - 1)) {
      station.get_events().add_events("Модуль был переключен");
    } else {
      interface.problem_output("Это нельзя отключать");
    }
    interface.delay(300);
  }
}
int
App::module_upgrade(Station& station, Iinterface& interface) {
  int module_upgrade_menu = 0;
  for (;;) {
    interface.clear();
    interface.panel_module_toggle(station);
    module_upgrade_menu =
      interface.request_value(0, station.get_module_manager().get_number_of_modules());
    if (module_upgrade_menu == 0) {
      return 0;
    } else if (station.get_module_manager().module_upgrade(station.get_resources_manager(),
                                                           module_upgrade_menu - 1)) {
      station.get_events().add_events("Модуль был улучшен");
    } else {
      interface.resources_deficit();
    }
    interface.delay(300);
  }
}
int
App::module_purchase(Station& station, Iinterface& interface) {
  int module_purchase_menu = 0;
  for (;;) {
    interface.clear();
    interface.panel_module_purchase(station, PURCHASE_COST, PURCHASE_COST);
    module_purchase_menu = interface.request_value(0, 4);
    switch (module_purchase_menu) {
      case 0:
        return 0;
      case 1:
        if (station.module_purchase("archive", PURCHASE_COST, PURCHASE_COST)) {
          station.get_events().add_events("Архив был куплен");
          break;
        }
        interface.resources_deficit();
        break;
      case 2:
        if (station.module_purchase("command_center", PURCHASE_COST, PURCHASE_COST)) {
          station.get_events().add_events("Командный центр был куплен");
          break;
        }
        interface.resources_deficit();
        break;
      case 3:
        if (station.module_purchase("living_place", PURCHASE_COST, PURCHASE_COST)) {
          station.get_events().add_events("Жилой отсек был куплен");
          break;
        }
        interface.resources_deficit();
        break;
      case 4:
        if (station.module_purchase("generator", PURCHASE_COST, PURCHASE_COST)) {
          station.get_events().add_events("Генератор был куплен");
          break;
        }
        interface.resources_deficit();
        break;
    }
    interface.delay(300);
  }
}
int
App::robot_purchase(Station& station, Iinterface& interface) {
  int robot_purchase_menu = 0;
  for (;;) {
    interface.clear();
    interface.panel_robot_purchase(station, PURCHASE_COST, PURCHASE_COST);
    robot_purchase_menu = interface.request_value(0, 2);
    switch (robot_purchase_menu) {
      case 0:
        return 0;
      case 1:
        if (station.robot_purchase("keeper", PURCHASE_COST, PURCHASE_COST * 2)) {
          station.get_events().add_events("keeper был куплен");
          break;
        }
        interface.resources_deficit();
        break;
      case 2:
        if (station.robot_purchase("integrator", PURCHASE_COST * 2, PURCHASE_COST)) {
          station.get_events().add_events("integrator был куплен");
          break;
        }
        interface.resources_deficit();
        break;
    }
    interface.delay(300);
  }
}
int
App::module_synthesis(Station& station, Iinterface& interface) {
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
      return 0;
    } else if (first_module_menu == second_module_menu) {
      interface.problem_output("Модули не могут быть одинаковые");
    } else if (station.get_module_manager().synthesis(first_module_menu - 1,
                                                      second_module_menu - 1)) {
      station.get_events().add_events("Модуль был синтезирован");
    }
  }
  interface.delay(300);
}
int
App::robot_synthesis(Station& station, Iinterface& interface) {
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
      return 0;
    } else if (first_robot_menu == second_robot_menu) {
      interface.problem_output("Роботы не могут быть одинаковые");
    } else if (station.get_robot_manager().synthesis(first_robot_menu - 1, second_robot_menu - 1)) {
      station.get_events().add_events("Робот был синтезирован");
    }
  }
  interface.delay(300);
}