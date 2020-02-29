#ifndef LIST_HPP
#define LIST_HPP

namespace ds
{
template<class T>
struct List_Node
{
    T value_;
    List_Node* next_;
};

template<class T>
class List_Iterator
{
public:
    List_Iterator(List_Node<T> * node)
        : node_(node)
    {}

    T* operator->()
    {
        return node_->value_;
    }

    T& operator*()
    {
        return node_->value_;
    }

    List_Iterator& operator++()
    {
        node_ = node_->next_;
        return *this;
    }

    List_Iterator operator++(int)
    {
        List_Iterator tmp = *this;
        node_ = node_->next_;
        return tmp;
    }

    List_Iterator operator+(std::size_t diff)
    {
        List_Iterator tmp = *this;
        for (std::size_t i = 0; i < diff; ++i)
        {
            tmp.node_ = tmp.node_->next_;
        }

        return tmp;
    }

    bool operator==(List_Iterator const& other)
    {
        return node_ == other.node_;
    }

    bool operator!=(List_Iterator const& other)
    {
        return node_ != other.node_;
    }

private:
    List_Node<T>* node_;

};

template<class T>
class List
{
public:
    using iterator = List_Iterator<T>;

    List()
        : first_(nullptr)
        , size_(0)
    {}

    ~List()
    {
        while (first_)
        {
            List_Node<T>* curr = first_->next_;
            delete first_;
            first_ = curr;
        }
    }

    void push_back(T const& value)
    {
        if (size_ == 0)
        {
            first_ = new List_Node<T>;
            first_->value_ = value;
            first_->next_ = nullptr;
        }
        else
        {
            List_Node<T>* current = first_;

            for (std::size_t i = 0; i < size_ - 1; ++i)
            {
                current = current->next_;
            }

            current->next_ = new List_Node<T>;
            current = current->next_;
            current->value_ = value;
            current->next_ = nullptr;
        }

        ++size_;
    }

    iterator begin()
    {
        return iterator(first_);
    }

    iterator end()
    {
        return iterator(nullptr);
    }

    std::size_t size() const
    {
        return size_;
    }

    bool empty() const
    {
        return size_ == 0;
    }

private:
    List_Node<T>* first_ = nullptr;
    std::size_t size_ = 0;
};

}

#endif // LIST_HPP
