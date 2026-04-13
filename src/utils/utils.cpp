#include "src/utils/utils.hpp"
#include <include/utils/constants.hpp>
#include <random>

static std::mt19937 rng(std::random_device{}());

double
random(double min, double max) {
  std::uniform_real_distribution<double> dist(min, max);
  return dist(rng);
}