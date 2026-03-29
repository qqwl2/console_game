#include "src/utils/utils.hpp"
#include <include/entities/robot.hpp>
#include <include/utils/constants.hpp>
#include <memory>

Robot::Robot(const int id, const float resources_efficiency)
  : id(id)
  , name("")
  , chassis_integrity(INTEGRITY_MAX)
  , firmware_integrity(INTEGRITY_MAX)
  , is_homeless(false)
  , energy(0)
  , bits(0)
  , occupied_place(0)
  , resources_efficiency(resources_efficiency)
  , day(0) {}

const int
Robot::get_chassis_integrity() const {
  return chassis_integrity;
}
const int
Robot::get_firmware_integrity() const {
  return firmware_integrity;
}
const int
Robot::get_energy() const {
  return energy;
}
const int
Robot::get_bits() const {
  return bits;
}
const int
Robot::get_occupied_place() const {
  return occupied_place;
}
const int
Robot::get_id() const {
  return id;
}
const int
Robot::get_day() const {
  return day;
}
void
Robot::set_is_homeless(const bool data) {
  is_homeless = data;
}
void
Robot::new_day() {
  day++;
}

Robot&
Robot::operator--() {
  if (is_homeless) {
    firmware_integrity -= DAMAGE_HOMELESS;
    chassis_integrity -= DAMAGE_HOMELESS;
  } else {
    firmware_integrity -= DAMAGE_RICH;
    chassis_integrity -= DAMAGE_RICH;
  }
  if (firmware_integrity < INTEGRITY_MIN) {
    firmware_integrity = INTEGRITY_MIN;
  }
  if (chassis_integrity < INTEGRITY_MIN) {
    chassis_integrity = INTEGRITY_MIN;
  }
  return *this;
}
Robot&
Robot::operator++() {
  firmware_integrity = INTEGRITY_MAX;
  chassis_integrity = INTEGRITY_MAX;
  return *this;
}
int
Robot::operator+(Robot& robot) {
  int synthesis_energy = (this->energy + robot.energy) / 2.0 * random(0.8, 1.2);
  int synthesis_bits = (this->bits + robot.bits) / 2.0 * random(0.8, 1.2);
  if (this->bits + this->energy >= robot.bits + robot.energy) {
    this->bits = synthesis_bits;
    this->energy = synthesis_energy;
    return 1; // 1 - сохранили в первый объект и удаляем второй
  } else {
    robot.bits = synthesis_bits;
    robot.energy = synthesis_energy;
    return 2; // 2 - сохранили во второй объект и удаляем первый
  }
}