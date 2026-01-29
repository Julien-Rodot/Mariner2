#pragma once

/**
 * @param name m_Matrix.cpp
 * @author jj
 * @brief matrix class, learnt from specialist math in grade 10. god kill me.
 */

#include <vector>
#include <stdexcept>
#include <iostream>

namespace Mariner {

    namespace Libraries {

        template<typename T>
        class m_Matrix {

            public:

                m_Matrix() = default;
                m_Matrix(size_t rows, size_t cols, const T& value = T()) : Rows(rows), Cols(cols), Data(rows * cols, value) {}
                m_Matrix(const std::initializer_list<std::initializer_list<T>>& init) {
                   
                    // so you can do m_Matrix<int> MyMatrix = { {x,y,z} }
                    
                    Rows = init.size();
                    Cols = init.begin()->size();
                    Data.reserve(Rows * Cols);

                    for (auto& row : init) {

                        if (row.size() != Cols) {

                            throw std::runtime_error("All rows must have the same number of columns");
                        }

                        Data.insert(Data.end(), row.begin(), row.end());
                    }
                }

                T& operator()(size_t row, size_t col) {

                    if (row >= Rows || col >= Cols) {

                        throw std::out_of_range("Matrix index out of range");

                    }

                    return Data[row * Cols + col];

                }

                const T& operator()(size_t row, size_t col) const {

                    if (row >= Rows || col >= Cols) {

                        throw std::out_of_range("Matrix index out of range");

                    }

                    return Data[row * Cols + col];
                }

                m_Matrix operator+(const m_Matrix& other) const {

                    check_same_size(other);
                    m_Matrix result(Rows, Cols);

                    for (size_t i = 0; i < Data.size(); ++i) {

                        result.Data[i] = Data[i] + other.Data[i];

                    }

                    return result;
                }

                m_Matrix operator-(const m_Matrix& other) const {
                    
                    check_same_size(other);
                    m_Matrix result(Rows, Cols);

                    for (size_t i = 0; i < Data.size(); ++i) {

                        result.Data[i] = Data[i] - other.Data[i];

                    }

                    return result;
                }

                m_Matrix operator*(const m_Matrix& other) const {

                    // oh god i want to kill myself.
                    if (Cols != other.Rows) {

                        throw std::runtime_error("Matrix dimensions do not match for multiplication");

                    } 

                    m_Matrix result(Rows, other.Cols, T());

                    for (size_t i = 0; i < Rows; ++i) {

                        for (size_t j = 0; j < other.Cols; ++j) {

                            for (size_t k = 0; k < Cols; ++k) {

                                result(i, j) += (*this)(i, k) * other(k, j);

                            }

                        }

                    }

                    return result;

                }

                void Print() const {

                    for (size_t i = 0; i < Rows; ++i) {

                        for (size_t j = 0; j < Cols; ++j) {

                            std::cout << (*this)(i, j) << " ";

                        }

                        std::cout << "\n";
                    }

                }

                // TOO MUCH MATH!!!!
                m_Matrix<double> Inverse() const {

                    if (Rows != Cols) {

                        throw std::runtime_error("Inverse only defined for square matrices");
                        
                    }

                    size_t n = Rows;
                    m_Matrix<double> A(n, n);
                    m_Matrix<double> I(n, n, 0.0);

                    for (size_t i = 0; i < n; ++i) {

                        for (size_t j = 0; j < n; ++j) {

                            A(i, j) = static_cast<double>((*this)(i, j));
                            I(i, j) = (i == j) ? 1.0 : 0.0;

                        }

                    }

                    for (size_t i = 0; i < n; ++i) {

                        double pivot = A(i, i);
                        if (pivot == 0.0) {

                            bool swapped = false;

                            for (size_t k = i + 1; k < n; ++k) {

                                if (A(k, i) != 0.0) {

                                    for (size_t j = 0; j < n; ++j) {

                                        std::swap(A(i, j), A(k, j));
                                        std::swap(I(i, j), I(k, j));

                                    }

                                    pivot = A(i, i);
                                    swapped = true;
                                    
                                    break;
                                }
                            }

                            if (!swapped) {

                                throw std::runtime_error("Matrix is singular, cannot invert");

                            } 

                        }

                        for (size_t j = 0; j < n; ++j) {

                            A(i, j) /= pivot;
                            I(i, j) /= pivot;

                        }

                        for (size_t k = 0; k < n; ++k) {

                            if (k == i) continue;

                            double factor = A(k, i);
                            for (size_t j = 0; j < n; ++j) {

                                A(k, j) -= factor * A(i, j);
                                I(k, j) -= factor * I(i, j);

                            }

                        }

                    }
    
                    return I;

                }

                void Resize(size_t rows, size_t cols, const T& value = T()) {

                    Rows = rows;
                    Cols = cols;
                    Data.assign(rows * cols, value);

                }

                size_t RowCount() const { return Rows; }
                size_t ColCount() const { return Cols; }

                bool IsEmpty() const { return Data.empty(); }
                void Clear() { Data.clear(); Rows = Cols = 0; }

            private:

                size_t Rows = 0;
                size_t Cols = 0;
                std::vector<T> Data;

                void check_same_size(const m_Matrix& other) const {

                    if (Rows != other.Rows || Cols != other.Cols) {

                        throw std::runtime_error("Matrix dimensions do not match");

                    }
                }
        };

    } // namespace Libraries

} // namespace Mariner
