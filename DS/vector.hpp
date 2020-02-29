#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <numeric>
#include <cassert>

namespace ds
{
template<class T>
class Vector_Iterator
{
public:
    Vector_Iterator(T* ptr)
        : ptr_(ptr)
    {
    }

    T& operator*()
    {
        return *ptr_;
    }

    T* operator->()
    {
        return ptr_;
    }

    Vector_Iterator operator-(std::size_t diff)
    {
        return Vector_Iterator(ptr_ - diff);
    }

    Vector_Iterator operator+(std::size_t diff)
    {
        return Vector_Iterator(ptr_ + diff);
    }

    Vector_Iterator& operator++()
    {
        ++ptr_;
        return *this;
    }

    Vector_Iterator& operator--()
    {
        --ptr_;
        return *this;
    }

    Vector_Iterator operator++(int)
    {
        Vector_Iterator tmp = *this;
        ++ptr_;
        return tmp;
    }

    Vector_Iterator operator--(int)
    {
        Vector_Iterator tmp = *this;
        --ptr_;
        return tmp;
    }

    bool operator==(Vector_Iterator const& other)
    {
        return ptr_ == other.ptr_;
    }

    bool operator!=(Vector_Iterator const& other)
    {
        return ptr_ != other.ptr_;
    }

private:
    T* ptr_;

};

template<class T>
class Vector
{
public:
    using iterator = Vector_Iterator<T>;

    Vector()
        : size_(0)
        , capacity_(0)
    {
    }

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

    void push_back(T const& value)
    {
        if (capacity_ == size_)
        {
            Reallocate(capacity_ > 0 ? capacity_ * 4 / 3 : 4);
        }

        ptr_[size_++] = value;
    }

    void pop_back()
    {
        --size_;
    }

    T& front()
    {
        assert(size_ > 0);
        return ptr_[0];
    }

    T& back()
    {
        assert(size_ > 0);
        return ptr_[size_ - 1];
    }

    iterator begin()
    {
        return iterator(ptr_);
    }

    iterator end()
    {
        return iterator(ptr_ + size_);
    }

    std::size_t size() const
    {
        return size_;
    }

    std::size_t capacity() const
    {
        return capacity_;
    }

    T* data()
    {
        return ptr_;
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
    void Reallocate(std::size_t new_capacity)
    {
        assert(new_capacity > capacity_);
        capacity_ = new_capacity;

        T* old = ptr_;
        // Allocate new memory
        ptr_ = new T[capacity_];
        // Copy from the old memory to the new allocated memory
        memcpy(ptr_, old, sizeof(T) * size_);
        // Delete old memory
        delete[] old;

    }

    T* ptr_ = nullptr;
    std::size_t size_ = 0;
    std::size_t capacity_ = 0;

};

}

#endif
