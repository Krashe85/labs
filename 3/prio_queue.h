#ifndef PriorQueue_H
#define PriorQueue_H

#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

typedef unsigned int uint;

template<typename T>
class PriorQueue {
public:
    PriorQueue() = default;

    ~PriorQueue() = default;

    void operator=(const PriorQueue<T> &queue2);

    T top();

    bool empty();

    size_t size();

    void pop();

    void push(T item);

private:
    std::vector<T> cont;
    std::less<T> less;

    int Parent(int index) { return (index - 1) / 2; }

    int Left(int index) { return (index * 2 + 1); }

    int Right(int index) { return (index * 2 + 2); }

    void heapDown(int index);

    void heapUp(int index);
};

template<typename T>
void PriorQueue<T>::operator=(const PriorQueue<T> &queue2) {
    for (int i = 0; i < this.size; i++) {
        this.pop();
    }
    for (int i = 0; i < queue2.size(); i++) {
        this.push(queue2.cont[i]);
    }
}

template<typename T>
T PriorQueue<T>::top() {
    return cont.front();
}

template<typename T>
bool PriorQueue<T>::empty() {
    return cont.empty();
}

template<typename T>
size_t PriorQueue<T>::size() {
    return cont.size();
}

template<typename T>
void PriorQueue<T>::pop() {
    cont.front() = cont.back();
    cont.pop_back();
    heapDown(0);
}

template<typename T>
void PriorQueue<T>::push(T item) {
    cont.push_back(item);
    int index = size() - 1;
    this->heapUp(index);
}


template<typename T>
void PriorQueue<T>::heapDown(int index) {
    int left = Left(index);
    int right = Right(index);

    int greatest = index;

    if (left < size() && cont[left] > cont[index]) {
        greatest = left;
    }
    if (right < size() && cont[right] > cont[greatest]) {
        greatest = right;
    }
    if (greatest != index) {
        std::swap(cont[index], cont[greatest]);
        heapDown(greatest);
    }
}

template<typename T>
void PriorQueue<T>::heapUp(int index) {
    if (index && (cont[Parent(index)] < cont[index])) {
        std::swap(cont[index], cont[Parent(index)]);
        this->heapUp(Parent(index));
    }
}

#endif