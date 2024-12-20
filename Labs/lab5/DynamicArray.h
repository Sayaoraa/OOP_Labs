#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <memory>
#include <memory_resource>
#include <vector>

template <typename T>
class DynamicArray {
public:
    using allocator_type = std::pmr::polymorphic_allocator<T>;
    using iterator = typename std::vector<T, allocator_type>::iterator;
    using const_iterator = typename std::vector<T, allocator_type>::const_iterator;

    DynamicArray(std::pmr::memory_resource* resource);

    void push_back(const T& value);

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

private:
    std::vector<T, allocator_type> data_;
};

template <typename T>
DynamicArray<T>::DynamicArray(std::pmr::memory_resource* resource)
    : data_(allocator_type(resource)) {}

template <typename T>
void DynamicArray<T>::push_back(const T& value) {
    data_.push_back(value);
}

template <typename T>
typename DynamicArray<T>::iterator DynamicArray<T>::begin() {
    return data_.begin();
}

template <typename T>
typename DynamicArray<T>::iterator DynamicArray<T>::end() {
    return data_.end();
}

template <typename T>
typename DynamicArray<T>::const_iterator DynamicArray<T>::begin() const {
    return data_.begin();
}

template <typename T>
typename DynamicArray<T>::const_iterator DynamicArray<T>::end() const {
    return data_.end();
}

#endif // DYNAMICARRAY_H
