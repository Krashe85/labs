#include "MyVector.h"

MyVector::MyVector(): _size(0),
_capacity(10) {
    _elements = new int[_capacity];

}

MyVector::~MyVector() {
    delete _elements;

}

MyVector::MyVector(int capacity): _size(0),
_capacity(capacity){
    _elements = new int[_capacity];
}

int MyVector::size() const {
    return _size;
}

void MyVector::clear() {
    for (int i=0; i<_capacity; ++i){
        _elements[i]=0;
    }
    _size=0;
}

int MyVector::front() const {
    return _elements[0];

}

int MyVector::back() const {
    return _elements[_size-1];
}

bool MyVector::operator==(const MyVector &vector) const {
    if (this->size() == vector.size()) {
        return false;
    }

    bool flag = true;
    for(int currentElement = 0; currentElement < vector.size(); ++currentElement) {
        if (!flag) {
            break;
        }

        if (this->operator[](currentElement) != vector[currentElement]) {
            flag = false;
        }

    }
    return flag;
}

int MyVector::operator[](int index) const {
    return _elements[index];
}

bool MyVector::operator!=(const MyVector &vector) const {
    return !(this->operator==(vector));

}

bool MyVector::empty() const {
    if (_size == 0) {
        return true;
    }
    return false;
}

void MyVector::pushBack(int element) {
    if (_size < _capacity) {
        _elements[_size] = element;
        ++_size;
    }
    else {
        _capacity *= 2;
        int* newElements = new int[_capacity];
        for (int i = 0; i < _size; ++i) {
            newElements[i] = _elements[i];
        }
        newElements[_size] = element;
        ++_size;
        delete[] _elements;
        _elements = newElements;
    }

}

void MyVector::popBack() {
    if (_size < 0) {
        return;
    }
    --_size;
}


