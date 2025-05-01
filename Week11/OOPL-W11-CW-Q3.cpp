#include <iostream>
#include <stdexcept>
#include <string>

class ArrayIndexOutOfBounds : public std::out_of_range
{
public:
    explicit ArrayIndexOutOfBounds(const std::string &msg)
        : std::out_of_range(msg) {}
};

template <typename T>
class SafeArray
{
public:
    explicit SafeArray(size_t size)
        : size_(size), data_(new T[size]()) {}

    ~SafeArray()
    {
        delete[] data_;
    }

    T &operator[](size_t index)
    {
        checkBounds(index);
        return data_[index];
    }

    const T &operator[](size_t index) const
    {
        checkBounds(index);
        return data_[index];
    }

    size_t size() const noexcept
    {
        return size_;
    }

private:
    size_t size_;
    T *data_;

    void checkBounds(size_t index) const
    {
        if (index >= size_)
        {
            throw ArrayIndexOutOfBounds("Index " + std::to_string(index) +
                                        " out of bounds for array of size " + std::to_string(size_));
        }
    }
};

int main()
{
    SafeArray<int> arr(5);
    for (size_t i = 0; i < arr.size(); ++i)
        arr[i] = static_cast<int>(i * 10);

    std::cout << "Array contents:\n";
    for (size_t i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << "\n";

    try
    {
        std::cout << arr[10] << "\n";
    }
    catch (const ArrayIndexOutOfBounds &e)
    {
        std::cerr << e.what() << "\n";
    }

    return 0;
}
