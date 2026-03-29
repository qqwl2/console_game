#pragma once
#include <iostream>

class Resources_manager {
  friend std::ostream& operator<<(std::ostream& os, const Resources_manager& resources_manager);

private:
  int energy;
  int bits;
  int energy_max;
  int bits_max;

public:
  Resources_manager(int _energy, int _bits, int _energy_max, int _bits_max);
  void add_energy(const int _energy);
  void add_bits(const int _bits);
  const int  get_energy() const;
  const int  get_bits() const;
};