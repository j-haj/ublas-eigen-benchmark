/* vim: set ts=2 sts=2 et sw=2 tw=80: */
/**
 * Boost::ublas vs Eigen
 *
 * Author: Jeff Hajewski
 * Created: 7/25/2017
 *
 * These benchmarks compare two popular linear algebra libraries. The benchmarks
 * are not comprehensive and should increase in coverage over time.
 */

#include <iostream>

#include "timer.hpp"

int main(int argc, char* argv[]) {
  auto stopwatch = Timer();
  stopwatch.start();
  auto sum(0);
  for (int i = 0; i < 100000; ++i) {
    sum += i;
  }
  stopwatch.stop();
  std::cout << '\n'
            << "\t---------------------------------\n"
            << "\tBoost::ublas vs. Eigen Benchmarks\n"
            << "\t---------------------------------\n";

  std::cout << "Elapsed time (s): " << stopwatch.elapsed_time() << '\n';
  return EXIT_SUCCESS;
}
