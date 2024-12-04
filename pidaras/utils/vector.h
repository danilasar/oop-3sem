#ifndef UTILS_VECTOR_H
#define UTILS_VECTOR_H

#include <bits/stdc++.h>
template <typename T> class Vector {
 
    T* arr;
 
    int capacity;
 
    int current;
 
public:
    Vector();
    ~Vector();
 
    void push(T data);
 
    void push(T data, int index);
 
    T* get(int index);
 
    void pop();
 
    int size();

    void clear();
 
    int getcapacity();
    void print();
};


#include "vector.cpp"

#endif