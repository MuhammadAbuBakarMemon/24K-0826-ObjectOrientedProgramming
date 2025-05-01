#include <iostream>
#include <vector>
#include <stdexcept>

class StackUnderflowException : public std::underflow_error
{
public:
    explicit StackUnderflowException(const std::string &msg)
        : std::underflow_error(msg) {}
};

template <typename T>
class Stack
{
public:
    void push(const T &value) { data_.push_back(value); }
    void pop()
    {
        if (data_.empty())
            throw StackUnderflowException("pop() on empty stack");
        data_.pop_back();
    }
    T &top()
    {
        if (data_.empty())
            throw StackUnderflowException("top() on empty stack");
        return data_.back();
    }
    const T &top() const
    {
        if (data_.empty())
            throw StackUnderflowException("top() on empty stack");
        return data_.back();
    }
    bool empty() const noexcept { return data_.empty(); }

private:
    std::vector<T> data_;
};

int main()
{
    Stack<int> s;
    try
    {
        s.pop();
    }
    catch (const StackUnderflowException &e)
    {
        std::cout << e.what() << "\n";
    }

    s.push(10);
    s.push(20);
    std::cout << s.top() << "\n";
    s.pop();
    std::cout << s.top() << "\n";

    return 0;
}
