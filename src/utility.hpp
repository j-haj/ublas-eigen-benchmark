/* vim: set ts=2 sts=2 et sw=2 tw=80: */
/**
 * utility.hpp
 *
 * Author: Jeff Hajewski
 * Created: 7/27/2017
 *
 * Contains a number of utility functions to simplify some of the benchmark
 * tests such as random number geration.
 */

#include <random>

/**
 * Returns a random value sample from a normal distribution with mean `mean` and
 * standard deviation `std`.
 *
 * @param mean mean of the normal distribution
 * @param std standard deviation of the normal distribution
 *
 * @return random sample from N(mean, std)
 */
double random_double(const double mean, const double std) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::normal_distribution<double> d(mean, std);
  return d(gen);
}
