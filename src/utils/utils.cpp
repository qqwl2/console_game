#include "src/utils/utils.hpp"
#include <include/utils/constants.hpp>
#include <random>

double
random(double min, double max) {
  return ((double)rand() / RAND_MAX) * (max - min) + min;
}