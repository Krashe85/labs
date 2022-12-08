#include "MyVector.h"

template<typename T>
MyVector<T>::MyVector(): _size(0),
                         _capacity(10) {
    _elements = new T[_capacity];

}

template<typename T>
MyVector<T>::~MyVector() {
    delete _elements;

}

template<typename T>
MyVector<T>::MyVector(int capacity): _size(0),
                                     _capacity(capacity) {
    _elements = new T[_capacity];
}

template<typename T>
int MyVector<T>::size() const {
    return _size;
}

template<typename T>
T MyVector<T>::front() const {
    return _elements[0];

}

template<typename T>
T MyVector<T>::back() const {
    return _elements[_size - 1];
}

template<typename T>
bool MyVector<T>::operator==(const MyVector<T> &vector) const {
    if (this->size() == vector.size()) {
        return false;
    }

    bool flag = true;
    for (int currentElement = 0; currentElement < vector.size(); ++currentElement) {
        if (!flag) {
            break;
        }

        if (this->operator[](currentElement) != vector[currentElement]) {
            flag = false;
        }

    }
    return flag;
}

template<typename T>
T MyVector<T>::operator[](int index) const {
    return _elements[index];
}

template<typename T>
bool MyVector<T>::operator!=(const MyVector &vector) const {
    return !(this->operator==(vector));

}

template<typename T>
bool MyVector<T>::empty() const {
    if (_size == 0) {
        return true;
    }
    return false;
}

template<typename T>
void MyVector<T>::pushBack(T element) {
    if (_size < _capacity) {
        _elements[_size] = element;
        ++_size;
    } else {
        _capacity *= 2;
        int *newElements = new int[_capacity];
        for (int i = 0; i < _size; ++i) {
            newElements[i] = _elements[i];
        }
        newElements[_size] = element;
        ++_size;
        delete[] _elements;
        _elements = newElements;
    }

}

template<typename T>
void MyVector<T>::popBack() {
    if (_size < 0) {
        return;
    }
    --_size;
}
