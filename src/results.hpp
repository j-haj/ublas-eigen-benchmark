/* vim: set ts=2 sts=2 et sw=2 tw=80: */
/**
 * results.hpp
 *
 * Author: Jeff Hajewski
 * Created: 7/28/2017
 *
 * Simple data structure to store the results from a benchmark.
 */

#ifndef __RESULTS_HPP
#define __RESULTS_HPP

#include <algorithm>
#include <numeric>
#include <vector>

/**
 * Benchmark types.
 *
 * There are two types of benchmark:
 *     * Eigen - based on the Eigen library
 *     * uBLAS - based on the Boost:uBLAS library
 */
enum class BenchmarkType { Eigen, uBLAS };

/**
 * Data structure that stores the results from benchmarks
 */
struct BenchmarkResults {
  BenchmarkResults(size_t N)
      : eigen_(std::vector<double>(N)), ublas_(std::vector<double>(N)) {}

  /// Results for Eigen benchmarks
  std::vector<double> eigen_;

  /// Results for Boost::uBLAS benchmarks
  std::vector<double> ublas_;

  /**
   * Add a result to results storage vector
   *
   * @param t `BenchmarkType` - must be either `Eigen` or `uBLAS`
   * @param result result to add to results collection
   */
  void push_back(BenchmarkType t, const double result) {
    switch (t) {
      case BenchmarkType::Eigen:
        eigen_.push_back(result);
        break;
      case BenchmarkType::uBLAS:
        ublas_.push_back(result);
        break;
    }
  }

  /**
   * Returns the results vector for the given benchmark type
   *
   * @param t benchmark type
   *
   * @return vector containing added results
   */
  std::vector<double> get_results(BenchmarkType t) {
    switch (t) {
      case BenchmarkType::Eigen:
        return eigen_;
      case BenchmarkType::uBLAS:
        return ublas_;
    }
  }

  /**
   * Returns the average of the given benchmark type.
   *
   * @param t benchmark type
   *
   * @return average of the given benchmark
   */
  double get_average(BenchmarkType t) {
    switch (t) {
      case BenchmarkType::Eigen:
        return std::accumulate(eigen_.begin(), eigen_.end(), 0.0) / eigen_.size();
      case BenchmarkType::uBLAS:
        return std::accumulate(ublas_.begin(), ublas_.end(), 0.0) / ublas_.size();
    }
  }
};  // struct BenchmarkResults

#endif  // __RESULTS_HPP
