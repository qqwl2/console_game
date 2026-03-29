#include <include/core/app.hpp>
#include <include/entities/factory.hpp>
#include <include/entities/station.hpp>
#include <include/graphics/Iinterface.hpp>
#include <include/graphics/console_interface.hpp>
#include <memory>

int
main() {
  srand(time(NULL));
  std::ios_base::sync_with_stdio(false);

  Robot_factory  robot_factory;
  Module_factory module_factory;

  Station station(module_factory, robot_factory);

  Console_interface interface;

  App app;
  app.run(station, interface);

  return 0;
}