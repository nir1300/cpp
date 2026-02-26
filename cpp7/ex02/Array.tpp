#include "Array.hpp"

template <class T>
Array<T>::Array(){
    _size = 0;
    array = new T [0];
}

template <class T>
Array<T>::Array(unsigned int n): _size(n) {
    array = new T [n](); // empty parenthesis trigger default initialisation
}

template <class T>
Array<T>::Array(const Array &other) {
    array = new T [other.size()];
    for (unsigned int i = 0; i < other.size(); i++)
        array[i] = other.array[i];
    _size = other.size();
}

template <class T>
Array<T>::~Array(){
    delete[] array;
}

template <class T>
Array<T> &Array<T>::operator=(const Array &other){
    if (this == &other)
        return *this;
    delete[] array;
    array = new T [other.size()];
    for (unsigned int i = 0; i < other.size(); i++)
        array[i] = other.array[i];
    _size = other.size();
    return *this;
}

template <class T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
    return ("Cannot access element (out of bounds)");
}

template <class T>
T &Array<T>::operator[](unsigned int i){
    if (i >= _size)
        throw OutOfBoundsException();
    return array[i];
}

template <class T>
unsigned int Array<T>::size() const {
    return _size;
}