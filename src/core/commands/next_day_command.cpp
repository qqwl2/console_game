#include <include/core/commands/next_day_command.hpp>

void
Next_day_command::execute(Station& station, Iinterface& interface) {
  if (station.new_day()) {
    station.get_events().remove_events();
  } else {
    interface.clear();
    interface.bad_end();
    exit(EXIT_SUCCESS);
  }
}