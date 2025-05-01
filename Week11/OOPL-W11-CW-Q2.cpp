#pragma once
#include <vector>
#include <stdexcept>
#include <sstream>

class DimensionMismatchException : public std::logic_error
{
public:
    explicit DimensionMismatchException(const std::string &message)
        : std::logic_error(message) {}
};

template <typename T>
class Matrix
{
public:
    Matrix() : rows_(0), cols_(0) {}
    Matrix(size_t rows, size_t cols, const T &initial = T())
        : rows_(rows), cols_(cols), data_(rows * cols, initial) {}

    Matrix(const Matrix &) = default;
    Matrix(Matrix &&) noexcept = default;
    Matrix &operator=(const Matrix &) = default;
    Matrix &operator=(Matrix &&) noexcept = default;

    size_t rows() const noexcept { return rows_; }
    size_t cols() const noexcept { return cols_; }

    T &operator()(size_t i, size_t j)
    {
        checkBounds(i, j);
        return data_[i * cols_ + j];
    }

    const T &operator()(size_t i, size_t j) const
    {
        checkBounds(i, j);
        return data_[i * cols_ + j];
    }

    Matrix operator+(const Matrix &other) const
    {
        if (rows_ != other.rows_ || cols_ != other.cols_)
        {
            throw DimensionMismatchException(
                "Cannot add matrices: dimensions do not match (" +
                dimString() + " vs " + other.dimString() + ")");
        }
        Matrix result(rows_, cols_);
        for (size_t i = 0; i < data_.size(); ++i)
            result.data_[i] = data_[i] + other.data_[i];
        return result;
    }

    Matrix operator*(const Matrix &other) const
    {
        if (cols_ != other.rows_)
        {
            throw DimensionMismatchException(
                "Cannot multiply matrices: inner dimensions do not match (" +
                std::to_string(cols_) + " vs " + std::to_string(other.rows_) + ")");
        }
        Matrix result(rows_, other.cols_);
        for (size_t i = 0; i < rows_; ++i)
            for (size_t j = 0; j < other.cols_; ++j)
            {
                T sum = T();
                for (size_t k = 0; k < cols_; ++k)
                    sum += (*this)(i, k) * other(k, j);
                result(i, j) = sum;
            }
        return result;
    }

private:
    size_t rows_, cols_;
    std::vector<T> data_;

    void checkBounds(size_t i, size_t j) const
    {
        if (i >= rows_ || j >= cols_)
        {
            std::ostringstream oss;
            oss << "Index out of bounds: (" << i << "," << j << ") for matrix of size " << dimString();
            throw std::out_of_range(oss.str());
        }
    }

    std::string dimString() const
    {
        return std::to_string(rows_) + "x" + std::to_string(cols_);
    }
};
