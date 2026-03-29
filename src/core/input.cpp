#include "src/core/input.hpp"
#include <iostream>
#include <limits>

int
menu_request(const int min, const int max) {
  int data = 0;
  while (1) {
    std::cin >> data;
    if (std::cin.fail() || data > max || data < min) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    break;
  }
  return data;
}

std::string
get_station_name() {
  std::string name;
  std::cout << "Выберите имя для вашей станции: ";
  std::getline(std::cin, name);
  return name;
}