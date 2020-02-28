#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <numeric>

namespace ds
{
template<class T>
class Vector
{
public:
    Vector(std::size_t count, T const& value)
        : size_(count)
        , capacity_(size_ * 4 / 3)
    {
        if (count == 0)
        {
            return;
        }

        ptr_ = new T[capacity_];
        for (std::size_t i = 0; i < size_; ++i)
        {
            ptr_[i] = value;
        }
    }

    ~Vector()
    {
        if (ptr_)
        {
            delete[] ptr_;
        }
    }

    std::size_t size() const
    {
        return size_;
    }

    std::size_t capacity() const
    {
        return capacity_;
    }

    T& operator[](std::size_t index)
    {
        return ptr_[index];
    }

    T const& operator[](std::size_t index) const
    {
        return ptr_[index];
    }

private:
    T* ptr_ = nullptr;
    std::size_t size_ = 0;
    std::size_t capacity_ = 0;

};
}

#endif
