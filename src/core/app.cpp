#include <include/core/app.hpp>
#include <include/core/commands/command_factory.hpp>

int
App::run(Station& station, Iinterface& interface) {
  Command_factory command_factory;
  for (;;) {
    interface.clear();
    interface.update_main(station);
    int menu = interface.request_value(0, command_factory.get_number_of_commands());
    if (!menu)
      exit(EXIT_SUCCESS);
    Command* command = command_factory.get(menu);
    if (command)
      command->execute(station, interface);
  }
  return 0;
}
