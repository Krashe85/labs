#ifndef MYVECTOR_H
#define MYVECTOR_H


template<typename T>
class MyVector {
    int _size;
    int _capacity;
    T *_elements;
public:
    MyVector();

    explicit MyVector(int capacity);

    ~MyVector();

    int size() const;

    T front() const;

    T back() const;

    bool empty() const;

    void pushBack(T element);

    void popBack();

    T operator[](int index) const;

    bool operator==(const MyVector &vector) const;

    bool operator!=(const MyVector &vector) const;


};


#endif
