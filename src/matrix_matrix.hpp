
#ifndef __MATRIX_MATRIX_HPP
#define __MATRIX_MATRIX_HPP

#include "results.hpp"

/**
 * Perform the matrix-matrix multiplication benchmarks
 *
 * @param N the number of times to perform the benchmark
 *
 * @return a vector containg the benchmark results
 */
BenchmarkResults run_matrix_matrix_benchmark(size_t N);

#endif // __MATRIX_MATRIX_HPP
