#ifndef ITER_HPP
# define ITER_HPP
#include <iostream> 
#include <stddef.h> 


template <typename T>
void iter(T* array, size_t len, void (*func)(T&)) {
    if (!array||!func)
        return;
    for (size_t i =0 ; i < len ; i++)
        func(array[i]);
    return;
}

template <typename T>
void iter(const T* array, size_t len, void (*func)(const T&)) {
    if (!array||!func)
        return;
    for (size_t i =0 ; i < len ; i++)
        func(array[i]);
}

#endif
