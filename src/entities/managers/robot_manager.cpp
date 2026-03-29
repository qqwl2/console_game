#include <algorithm>
#include <include/entities/managers/robot_manager.hpp>
#include <include/utils/constants.hpp>

void
Robot_manager::add_robot(Robot_factory& robot_factory, const std::string type) {
  robots.push_back(robot_factory.create(type, robot_id++));
}

void
Robot_manager::damage_robots() {
  for (auto& robot : robots) {
    --*robot;
  }
}
void
Robot_manager::delete_corpse() {
  auto iterator = std::remove_if(robots.begin(), robots.end(), [](const auto& robot) {
    return robot->get_chassis_integrity() <= INTEGRITY_MIN ||
           robot->get_firmware_integrity() <= INTEGRITY_MIN;
  });
  robots.erase(iterator, robots.end());
}
void
Robot_manager::repair_robots(Resources_manager& resources_manager) {
  int cost = 0;
  for (auto& robot : robots) {
    if (robot->get_chassis_integrity() < INTEGRITY_MAX / 2 ||
        robot->get_firmware_integrity() < INTEGRITY_MAX / 2) {
      if (resources_manager.get_energy() >= REPAIR_ROBOT_COST &&
          resources_manager.get_bits() >= REPAIR_ROBOT_COST) {
        ++*robot;
        resources_manager.add_bits(-1 * REPAIR_ROBOT_COST);
        resources_manager.add_energy(-1 * REPAIR_ROBOT_COST);
      }
    }
  }
}
void
Robot_manager::robot_new_day() {
  for (auto& robot : robots) {
    robot->new_day();
  }
}
void
Robot_manager::robot_placement(const int living_places) {
  int places = living_places;
  for (auto& robot : robots) {
    if (places >= robot->get_occupied_place()) {
      places -= robot->get_occupied_place();
      robot->set_is_homeless(false);
    } else {
      robot->set_is_homeless(true);
    }
  }
}
const int
Robot_manager::calculate_energy() {
  int total = 0;
  for (auto& robot : robots) {
    total += robot->get_energy();
  }
  return total;
}
const int
Robot_manager::calculate_bits() {
  int total = 0;
  for (auto& robot : robots) {
    total += robot->get_bits();
  }
  return total;
}
const int
Robot_manager::get_number_of_robots() const {
  return robots.size();
}
int
Robot_manager::synthesis(const int _first_index, const int _second_index) {
  Robot* first_robot = robots[_first_index].get();
  Robot* second_robot = robots[_second_index].get();
  if (first_robot->get_day() >= 5 && second_robot->get_day() >= 5) {
    if (*first_robot + *second_robot == 1) {
      remove_robot(robots[_second_index]->get_id());
      return 1;
    } else {
      remove_robot(robots[_first_index]->get_id());
      return 1;
    }
  }
  return 0;
}
void
Robot_manager::remove_robot(const int _id) {
  auto iterator = std::remove_if(
    robots.begin(), robots.end(), [_id](const auto& robot) { return robot->get_id() == _id; });
  robots.erase(iterator, robots.end());
}