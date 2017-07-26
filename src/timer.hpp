/* vim: set ts=2 sts=2 et sw=2 tw=80: */
/**
 * Timing tools for getting benchmark results
 *
 * Author: Jeff Hajewski
 * Created: 7/26/2017
 *
 * Mostly just a wrapper on parts of <chrono> to simplify timing code execution.
 */

#include <chrono>

struct Timer {

  using system_clock = std::chrono::system_clock;
  /**
   * Start the timer
   */
  void start() {
    start_ = system_clock::now();
  }

  /**
   * Stop the timer
   */
  void stop() {
    elapsed_ = system_clock::now() - start_;
  }

  /**
   * Returns the elapsed time between calls of `start` and `stop`
   *
   * @return elapsed time in seconds
   */
  double elapsed_time() {
    return elapsed_.count();
  }

  /// Tracks the start time of the timer
  std::chrono::time_point<system_clock> start_;

  /// Stores the elapsed time. This is computed in the `stop()` method.
  std::chrono::duration<double> elapsed_;

}; // struct Timer
