#pragma once
#include <include/entities/factory.hpp>
#include <include/entities/managers/resources_manager.hpp>
#include <include/entities/robot.hpp>
#include <iostream>
#include <vector>

class Robot_manager {
  friend std::ostream& operator<<(std::ostream& os, const Robot_manager& robot_manager);

private:
  std::vector<std::unique_ptr<Robot>> robots;

  int robot_id;

public:
  void      add_robot(Robot_factory& robot_factory, const std::string type);
  void      damage_robots();
  void      delete_corpse();
  void      repair_robots(Resources_manager& resources_manager);
  void      robot_new_day();
  void      robot_placement(const int living_places);
  const int calculate_energy();
  const int calculate_bits();
  const int get_number_of_robots() const;
  int       synthesis(const int _first_index, const int _second_index);
  void      remove_robot(const int _id);
};