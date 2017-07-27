/* vim: set ts=2 sts=2 et sw=2 tw=80: */
/**
 * matrix_matrix.cc
 *
 * Author: Jeff Hajewski
 * Created: 7/27/20127
 *
 * Matrix-matrix multiplication benchmarks
 */

#include <vector>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

#include <Eigen/Dense>

#include "utility.hpp"

#define MAX_ROW_SIZE 10000
#define MAX_COL_SIZE 10000
#define N_MEAN 100
#define N_STD 23.5

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

/**
 * Performs the matrix-matrix multiplication benchmarks
 */
std::vector<double> run_matrix_matrix_test() {

}
