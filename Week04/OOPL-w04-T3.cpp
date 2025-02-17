#include <iostream>
#include <stdexcept>
#include <algorithm>

class DynamicArray {
private:
    int size_;
    int* data;

public:
    DynamicArray() : size_(0), data(nullptr) {}

    DynamicArray(int n) : size_(n) {
        data = new int[size_]();
    }

    DynamicArray(const DynamicArray& other) : size_(other.size_) {
        data = new int[size_];
        std::copy(other.data, other.data + size_, data);
    }

    DynamicArray(DynamicArray&& other) noexcept : size_(other.size_), data(other.data) {
        other.size_ = 0;
        other.data = nullptr;
    }

    ~DynamicArray() {
        delete[] data;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            size_ = other.size_;
            data = new int[size_];
            std::copy(other.data, other.data + size_, data);
        }
        return *this;
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            delete[] data;
            size_ = other.size_;
            data = other.data;
            other.size_ = 0;
            other.data = nullptr;
        }
        return *this;
    }

    int size() const {
        return size_;
    }

    int& at(int index) {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const int& at(int index) const {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    void resize(int newSize) {
        if (newSize < 0) {
            throw std::invalid_argument("New size cannot be negative");
        }
        if (newSize == size_) {
            return;
        }
        int* newData = new int[newSize]();
        int elementsToCopy = std::min(size_, newSize);
        std::copy(data, data + elementsToCopy, newData);
        delete[] data;
        data = newData;
        size_ = newSize;
    }

    void print() const {
        for (int i = 0; i < size_; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};