#include <include/core/app.hpp>
#include <include/entities/factory.hpp>
#include <include/entities/station.hpp>
#include <include/graphics/Iinterface.hpp>
#include <include/graphics/console_interface.hpp>
#include <memory>

int
main() {
  std::ios_base::sync_with_stdio(false);

  Station& station = Station::get_instance();

  Console_interface interface;

  App app;
  app.run(station, interface);

  return 0;
}