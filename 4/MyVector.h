#pragma once
#include<iostream>

template <typename T>
class MyVector{
public:
    MyVector(size_t m = 1);
    MyVector(const MyVector& V);
    ~MyVector() = default;
    void pushf(const T& a);
    void pushe(const T& a);
    T popf();
    T pope();
    std::size_t size();
    T& operator[] (size_t n);
    class Iterator{
    public:
        Iterator(T* obj);
        Iterator(Iterator& obj);
        T* operator->();
        T& operator*();
        Iterator operator++();
        Iterator operator--();
        bool operator++(int n);
        bool operator--(int n);
        bool operator!=(Iterator obj);
        bool operator==(Iterator obj);
        Iterator& operator=(Iterator obj);
        T* __obj;
    };
    Iterator begin();
    Iterator end();
    void erase(Iterator front, Iterator end);
private:
    T* _memory;
    std::size_t _size_users;
    std::size_t _size_real;
};

template <typename T>
MyVector<T>::MyVector(size_t m){
    _size_users = m;
    _size_real = (size_t)(m*2);
    _memory = new T[_size_real];
}

template <typename T>
MyVector<T>::MyVector(const MyVector& V){
    _size_users = V._size_users;
    _size_real = V._size_real;
    _memory = new T[_size_real];
    for(size_t i = 0; i < _size_users; i++) _memory[i] = V._memory[i];
}

template <typename T>
void MyVector<T>::pushf(const T& a){
    _size_users++;
    if((size_t)(_size_users*1,5) < _size_real){
        for(size_t i =_size_users; i > 0; i--)    _memory[i] = _memory[i-1];
    }else{
        _size_real = (size_t)(_size_users*2);
        T* mam = new T[_size_real];
        for(size_t i =1; i <= _size_users; i++)    mam[i] = _memory[i-1];
        delete _memory;
        _memory = mam;
    }
    _memory[0] = a;
}

template <typename T>
T MyVector<T>::popf(){
    size_t a = _memory[0];
    _size_users--;
    if(_size_users>(size_t)(_size_real*0,25)){
        for(int i = 0; i < _size_users; i++) _memory[i] = _memory[i+1];
    }else{
        _size_real = (int)(_size_users*2);
        T* mam = new T[_size_real];
        for(int i = 0; i < _size_users; i++)    mam[i] = _memory[i+1];
        delete _memory;
        _memory = mam;
    }
    return a;
}

template <typename T>
T MyVector<T>::pope(){
    _size_users--;
    int a = _memory[_size_users];
    if(_size_users<=(int)(_size_real*0,25)){
        _size_real = (int)(_size_users*2);
        T* mam = new T[_size_real];
        for(int i = 0; i < _size_users; i++)    mam[i] = _memory[i];
        delete _memory;
        _memory = mam;
    }
    return a;
}

template <typename T>
void MyVector<T>::pushe(const T& a){
    _size_users++;
    if((int)(_size_users*1,5) < _size_real){
        _memory[_size_users-1] = a;
    }else{
        _size_real = (int)(_size_users*2);
        T* mam = new T[_size_real];
        mam[_size_users-1] = a;
        for(int i =0; i < _size_users-1; i++)    mam[i] = _memory[i];
        delete _memory;
        _memory = mam;
    }
}

template <typename T>
std::size_t MyVector<T>::size(){
    return _size_users;
}

template <typename T>
T& MyVector<T>::operator[](int n){
    return _memory[n];
}

template <typename T>
MyVector<T>::Iterator::Iterator(T* obj){
    __obj = obj;
}

template <typename T>
MyVector<T>::Iterator::Iterator(Iterator& obj){
    __obj = obj.__obj;
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::Iterator::operator++(){
    Iterator a(__obj++);
    return a;
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::Iterator::operator--(){
    Iterator a(__obj--);
    return a;
}

template <typename T>
bool MyVector<T>::Iterator::operator++(int n = 1){
    if(n)
        __obj+=n;
    else
        __obj++;
    //return a;
}

template <typename T>
bool MyVector<T>::Iterator::operator--(int n = 1){
    if(n)
        __obj-=n;
    else
        __obj--;
    //return a;
}

template <typename T>
T* MyVector<T>::Iterator::operator->(){
    return __obj;
}

template <typename T>
T& MyVector<T>::Iterator::operator*(){
    return *__obj;
}

template <typename T>
bool MyVector<T>::Iterator::operator!=(Iterator obj){
    return (bool)(__obj!=obj.__obj);
}

template <typename T>
bool MyVector<T>::Iterator::operator==(Iterator obj){
    return (bool)(__obj==obj.__obj);
}

template <typename T>
typename MyVector<T>::Iterator& MyVector<T>::Iterator::operator=(Iterator obj){
    __obj=obj.__obj;
    return *this;
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::begin(){
    MyVector<T>::Iterator a(_memory);
    return a;
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::end(){
    MyVector<T>::Iterator a(_memory + _size_users);
    return a;
}

template <typename T>
void MyVector<T>::erase(Iterator begin, Iterator end){
    T* obj= new T(2*(end.__obj - begin.__obj));
    _size_users = 0;
    for(auto i = begin; i!=end; i++){
        obj[_size_users] = *i;
        _size_users++;
    }
    _size_users+=2;
    _size_real = 2*_size_users;
    delete _memory;
    _memory = obj;
}