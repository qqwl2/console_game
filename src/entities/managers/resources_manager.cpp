#include <include/entities/managers/resources_manager.hpp>

Resources_manager::Resources_manager(int _energy, int _bits, int _energy_max, int _bits_max)
  : energy(_energy)
  , bits(_bits)
  , energy_max(_energy_max)
  , bits_max(_bits_max) {}
void
Resources_manager::add_energy(const int _energy) {
  energy += _energy;
  if (energy > energy_max) {
    energy = energy_max;
  } else if (energy < 0) {
    energy = 0;
  }
}
void
Resources_manager::add_bits(const int _bits) {
  bits += _bits;
  if (bits > bits_max) {
    bits = bits_max;
  } else if (bits < 0) {
    bits = 0;
  }
}
const int
Resources_manager::get_energy() const {
  return energy;
}
const int
Resources_manager::get_bits() const {
  return bits;
}