#include <iostream>
#include "DoublyLinkedList.h"

int main() {
    DoublyLinkedList<int> list1;
    list1.addToTail(1);
    list1.addToTail(2);
    list1.addToTail(3);

    DoublyLinkedList<int> list2;
    list2.addToTail(2);
    list2.addToTail(3);
    list2.addToTail(4);

    
    Node<int>* clonedListHead = list1.cloneList();

   
    DoublyLinkedList<int> concatenatedList = list1 + list2;

    
    DoublyLinkedList<int> commonElementsList = list1 * list2;

    
    std::cout << "Cloned List: ";
    Node<int>* current = clonedListHead;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    
    std::cout << "Concatenated List: ";
    current = concatenatedList.getHead();
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    
    std::cout << "Common Elements List: ";
    current = commonElementsList.getHead();
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}
