/* vim: set ts=2 sts=2 et sw=2 tw=80: */
/**
 * matrix_matrix.cc
 *
 * Author: Jeff Hajewski
 * Created: 7/27/20127
 *
 * Matrix-matrix multiplication benchmarks
 */
#include <cmath>
#include <vector>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

#include <Eigen/Dense>

#include "matrix_matrix.hpp"
#include "results.hpp"
#include "timer.hpp"
#include "utility.hpp"

#define MAX_ROW_SIZE 10000
#define MAX_COL_SIZE 10000
#define N_MEAN 100
#define N_STD 23.5
#define TOL 0.000001

using ublas = boost::numeric::ublas;

ublas::matrix<double> create_ublas_matrix(size_t rows, size_t cols) {
  ublas::matrix<double> m(rows, cols);
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      m(i, j) = random_double(N_MEAN, N_STD);
    }
  }
  return m;
}

Eigen::MatrixXd create_eigen_matrix(size_t rows, size_t cols) {
  Eigen::MatrixXd m(rows, cols);
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      m(i, j) = random_double(N_MEAN, N_STD);
    }
  }
  return m;
}

BenchmarkResults run_matrix_matrix_benchmark(size_t N) {
  BenchmarkResults results = BenchmarkResults(N);
  auto timer = Timer();

  const size_t rows = 1000;
  const size_t cols = 1000;
  for (size_t i = 0; i < N; ++i) {
    
    // Create matrices
    auto A_eigen = create_eigen_matrix(rows, cols);
    auto B_eigen = create_eigen_matrix(rows, cols);
    auto A_ublas = create_eigen_matrix(rows, cols);
    auto B_ublas = create_ublas_matrix(rows, cols);

    // Benchmark
    timer.start();
    auto C_eigen = A_eigen * B_eigen;
    timer.stop();
    results.push_back(BenchmarkType::Eigen, timer.elapsed_time());

    timer.start();
    auto C_ublas = ublas::prod(A_ublas, B_ublas);
    timer.stop();
    results.push_back(BenchmarkType::uBLAS, timer.elapsed_time());

    // Check that the results are the same
    for (size_t row = 0; row < rows; ++row) {
      for (size_t col = 0; col < cols; ++col) {
        if (std::abs(C_eigen(row, col) - C_ublas(row, col)) > TOL) {
          std::cout << "WARNING: matrix products are not equivalent!\n";
          std::cout << "Exiting early as a result...\n";
          return results;
        }
      }
    }
  }
  return results;
}
