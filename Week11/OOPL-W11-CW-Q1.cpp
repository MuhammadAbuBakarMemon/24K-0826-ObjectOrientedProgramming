#pragma once
#include <any>
#include <unordered_map>
#include <typeindex>
#include <stdexcept>
#include <string>

class BadTypeException : public std::logic_error
{
public:
    explicit BadTypeException(const std::string &message)
        : std::logic_error(message) {}
};

class TypeSafeContainer
{
public:
    template <typename T>
    void store(const T &value)
    {
        data_[std::type_index(typeid(T))] = value;
    }

    template <typename T>
    T &get()
    {
        auto key = std::type_index(typeid(T));
        auto it = data_.find(key);
        if (it == data_.end())
        {
            throw BadTypeException(std::string("No object stored for type: ") + key.name());
        }
        try
        {
            return std::any_cast<T &>(it->second);
        }
        catch (const std::bad_any_cast &)
        {
            throw BadTypeException(std::string("Type mismatch retrieving object for type: ") + key.name());
        }
    }

    template <typename T>
    bool contains() const noexcept
    {
        return data_.count(std::type_index(typeid(T))) > 0;
    }

private:
    std::unordered_map<std::type_index, std::any> data_;
};