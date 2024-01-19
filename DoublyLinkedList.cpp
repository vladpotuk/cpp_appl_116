#include "DoublyLinkedList.h"


template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void DoublyLinkedList<T>::addToTail(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = newNode;
    }
    else {
        Node<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

template <typename T>
bool DoublyLinkedList<T>::search(const T& value) const {
    Node<T>* current = head;
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::cloneList() const {
    DoublyLinkedList<T> clonedList;

    Node<T>* current = head;
    while (current) {
        clonedList.addToTail(current->data);
        current = current->next;
    }

    return clonedList.getHead();
}

template <typename T>
DoublyLinkedList<T> DoublyLinkedList<T>::operator+(const DoublyLinkedList<T>& otherList) const {
    DoublyLinkedList<T> result = *this;  // Copy the current list

    Node<T>* currentOther = otherList.getHead();
    while (currentOther) {
        result.addToTail(currentOther->data);
        currentOther = currentOther->next;
    }

    return result;
}

template <typename T>
DoublyLinkedList<T> DoublyLinkedList<T>::operator*(const DoublyLinkedList<T>& otherList) const {
    DoublyLinkedList<T> commonElementsList;

    Node<T>* current = head;
    while (current) {
        if (otherList.search(current->data)) {
            commonElementsList.addToTail(current->data);
        }
        current = current->next;
    }

    return commonElementsList;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::getHead() const {
    return head;
}


template class DoublyLinkedList<int>;  
