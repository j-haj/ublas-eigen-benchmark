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

#include "matrix_matrix.hpp"
#include "results.hpp"
#include "timer.hpp"

int main(int argc, char* argv[]) {
  std::cout << '\n'
            << "\t---------------------------------\n"
            << "\tBoost::ublas vs. Eigen Benchmarks\n"
            << "\t---------------------------------\n";

  std::cout << "Running matrix-matrix multiplication benchmark\n\n";
  auto results = run_matrix_matrix_benchmark(1);
  std::cout << "Results:\n"
            << "\tEigen: " << results.get_average(BenchmarkType::Eigen) << '\n'
            << "\tuBLAS: " << results.get_average(BenchmarkType::uBLAS) << '\n';
  return EXIT_SUCCESS;
}
