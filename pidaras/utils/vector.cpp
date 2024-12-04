#ifndef UTILS_VECTOR_CPP
#define UTILS_VECTOR_CPP
#include "vector.h"
#include "vector_error.h"
template<typename T>
Vector<T>::Vector()
{
    arr = new T[1];
    capacity = 1;
    current = 0;
}

template<typename T>
Vector<T>::~Vector() { delete[] arr; }


template<typename T>
void Vector<T>::push(T data)
{

    if (current == capacity) {
        T* temp = new T[2 * capacity];

        for (int i = 0; i < capacity; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;
        capacity *= 2;
        arr = temp;
    }

    arr[current] = data;
    current++;
}

template<typename T>
void Vector<T>::push(T data, int index)
{
    if (index == capacity)
        push(data);
    else
        arr[index] = data;
}

template<typename T>
T* Vector<T>::get(int index)
{
    if (index < current)
        return &arr[index];
    throw new VectorError("Выход за границы");
}

template<typename T>
void Vector<T>::pop() { current--; }

template<typename T>
int Vector<T>::size() { return current; }

template<typename T>
int Vector<T>::getcapacity() { return capacity; }

template<typename T>
void Vector<T>::print()
{
    for (int i = 0; i < current; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


template<typename T>
void Vector<T>::clear() {
    arr = new T[1];
    capacity = 1;
    current = 0;
}

#endif