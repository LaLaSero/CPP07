#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <typeinfo>

template< typename T>

class Array
{
private:
    T*  _array;
    unsigned int _size;
public:
// canonical form
    Array(): _size(0)
    {
        this->_array = new T[this->_size];
    }
    Array(unsigned int size): _size(size)
    {
           this->_array = new T[this->_size];
    }
    Array(const Array &src): _size(src.size())
    {
        this->_array = NULL;
        *this = src;
    }
    ~Array()
    {
        if (this->_array)
            delete [] this->_array;
    }
    Array &operator=(const Array &src)
    {
        if (this != &src)  
        {
            if (this->_array != NULL)
                delete[] this->_array;
            this->_size = src._size; 
            this->_array = new T[src._size]; 
            for (unsigned int i = 0; i < this->_size; i++) 
                this->_array[i] = src._array[i];
        }
        return *this;
    }
    T &operator[](unsigned int index)
    {
        if (index >= this->_size) {
            throw Array::OutOfIndexException();
        }
        return this->_array[index];
    }
    // constでもアクセスできるようにオーバーロード
    const T &operator[](unsigned int index) const
    {
        if (index >= this->_size) {
            throw Array::OutOfIndexException();
        }
        return this->_array[index];
    }

    unsigned int size() const
    {
        return this->_size;
    }
    
    class OutOfIndexException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

template< typename T >
const char *Array<T>::OutOfIndexException::what() const throw()
{
    return ("Error: Out of index");
}


#endif