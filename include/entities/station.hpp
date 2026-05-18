#pragma once
#include <include/entities/event.hpp>
#include <include/entities/factory.hpp>
#include <include/entities/managers/module_manager.hpp>
#include <include/entities/managers/resources_manager.hpp>
#include <include/entities/managers/robot_manager.hpp>
#include <include/entities/observer.hpp>

class Station {
  friend std::ostream& operator<<(std::ostream& os, Station& station);

private:
  std::string name;
  int         day;

  Subject           subject;
  Resources_manager resources_manager;
  Robot_manager     robot_manager;
  Module_manager    module_manager;
  Event             events;

  Module_factory module_factory;
  Robot_factory  robot_factory;

  int storm_days;

  void storm_errors();
  void error_handling();

  ~Station() = default;
  Station();

protected:
public:
  Station(Station& other) = delete;
  void operator=(const Station&) = delete;

  static Station& get_instance();

  int                new_day();
  int                calculate_signal_chance();
  Resources_manager& get_resources_manager();
  Robot_manager&     get_robot_manager();
  Module_manager&    get_module_manager();
  Event&             get_events();
  int                get_days() const;
  std::string        get_end_game_stats() const;
  bool               end_game() const;
  int                robot_purchase(const std::string type, int _energy, int _bits);
  int                module_purchase(const std::string type, int _energy, int _bits);
};