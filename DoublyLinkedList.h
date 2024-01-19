#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void addToTail(const T& value);
    bool search(const T& value) const;

    Node<T>* cloneList() const;
    DoublyLinkedList<T> operator+(const DoublyLinkedList<T>& otherList) const;
    DoublyLinkedList<T> operator*(const DoublyLinkedList<T>& otherList) const;

    Node<T>* getHead() const;
};

#include "DoublyLinkedList.cpp" 

#endif 
