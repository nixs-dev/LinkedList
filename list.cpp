#include "iostream"
#include "node.hpp"
#include "list.hpp"


void LinkedList::all() {
    if(head == nullptr) {
        std::cout << "VAZIO";
    }
    else {
        Node *item = head;

        while(true) {
            std::cout << "VALOR: " << (*item).value << std::endl;
            std::cout << "ENDERECO: " << &(*item) << std::endl;

            if((*item).next == nullptr) {
                std::cout << "PONTEIRO: " << "NULLPOINTER" << std::endl;
            }
            else {
                std::cout << "PONTEIRO: " << (*item).next << std::endl;
            }

            if((*item).next == nullptr) {
                break;
            }
            else {
                item = (*item).next;
            }

            std::cout << std::endl;
        }
    }
}

void LinkedList::push(int value) {
    Node *node = new Node();

    (*node).value = value;
    (*node).next = nullptr;

    if(head == nullptr) {
        head = node;
    }
    else {
        Node *item = head;

        while((*item).next != nullptr) {
            item = (*item).next;
        }

        (*item).next = node;
    }
}