#ifndef SASHAVECTOR_MYVECTOR_H
#define SASHAVECTOR_MYVECTOR_H


class MyVector {
    int _size;
    int _capacity;
    int* _elements;
public:
    MyVector();
    explicit MyVector(int capacity);
    ~MyVector();

    int size() const;
    void clear();
    int front() const;
    int back() const;
    bool empty() const;
    void pushBack(int element);
    void popBack();

    int operator[](int index) const;
    bool operator==(const MyVector& vector) const;
    bool operator!=(const MyVector& vector) const;


};


#endif //SASHAVECTOR_MYVECTOR_H
