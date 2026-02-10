#include <cstddef>
#include <memory>
#include <stdexcept>
#include <utility>
#include <algorithm>

template <typename T>
class Vector {
public:
    using value_type = T;
    using size_type = std::size_t;
    using iterator = T*;
    using const_iterator = const T*;

private:
    T* data_;
    size_type size_;
    size_type capacity_;

    void destroy_elements() {
        for (size_type i = 0; i < size_; ++i)
            data_[i].~T();
        size_ = 0;
    }

    void reallocate(size_type new_cap) {
        T* new_data = static_cast<T*>(::operator new(sizeof(T) * new_cap));

        size_type i = 0;
        try {
            for (; i < size_; ++i)
                new (new_data + i) T(std::move_if_noexcept(data_[i]));
        } catch (...) {
            for (size_type j = 0; j < i; ++j)
                new_data[j].~T();
            ::operator delete(new_data);
            throw;
        }

        destroy_elements();
        ::operator delete(data_);

        data_ = new_data;
        capacity_ = new_cap;
        size_ = i;
    }

public:
    // Constructors
    Vector() : data_(nullptr), size_(0), capacity_(0) {}

    explicit Vector(size_type count, const T& value = T())
        : Vector() {
        reserve(count);
        for (size_type i = 0; i < count; ++i)
            push_back(value);
    }

    // Copy constructor
    Vector(const Vector& other) : Vector() {
        reserve(other.size_);
        for (const auto& x : other)
            push_back(x);
    }

    // Move constructor
    Vector(Vector&& other) noexcept
        : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
        other.data_ = nullptr;
        other.size_ = other.capacity_ = 0;
    }

    // Copy assignment
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            destroy_elements();
            reserve(other.size_);
            for (const auto& x : other)
                push_back(x);
        }
        return *this;
    }

    // Move assignment
    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            destroy_elements();
            ::operator delete(data_);
            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.data_ = nullptr;
            other.size_ = other.capacity_ = 0;
        }
        return *this;
    }

    // Destructor
    ~Vector() {
        destroy_elements();
        ::operator delete(data_);
    }

    // Element access
    T& operator[](size_type i) { return data_[i]; }
    const T& operator[](size_type i) const { return data_[i]; }

    T& at(size_type i) {
        if (i >= size_) throw std::out_of_range("Vector::at");
        return data_[i];
    }

    // Capacity
    size_type size() const { return size_; }
    size_type capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }

    void reserve(size_type new_cap) {
        if (new_cap > capacity_)
            reallocate(new_cap);
    }

    void resize(size_type count, T value = T()) {
        if (count < size_) {
            for (size_type i = count; i < size_; ++i)
                data_[i].~T();
        } else if (count > size_) {
            reserve(count);
            for (size_type i = size_; i < count; ++i)
                new (data_ + i) T(value);
        }
        size_ = count;
    }

    // Modifiers
    void push_back(const T& value) {
        if (size_ == capacity_)
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        new (data_ + size_) T(value);
        ++size_;
    }

    void push_back(T&& value) {
        if (size_ == capacity_)
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        new (data_ + size_) T(std::move(value));
        ++size_;
    }

    void pop_back() {
        if (size_ == 0) return;
        data_[--size_].~T();
    }

    void clear() {
        destroy_elements();
    }

    // Iterators
    iterator begin() { return data_; }
    iterator end() { return data_ + size_; }
    const_iterator begin() const { return data_; }
    const_iterator end() const { return data_ + size_; }
};