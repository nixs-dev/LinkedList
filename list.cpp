#include "iostream"
#include "node.hpp"
#include "list.hpp"


template <typename T>
void LinkedList<T>::all() {
    if(head == nullptr) {
        std::cout << "VAZIO";
    }
    else {
        Node<T> *item = head;

        while(true) {
            std::cout << "VALOR: " << item->value << std::endl;
            std::cout << "ENDERECO: " << &(*item) << std::endl;

            if(item->next == nullptr) {
                std::cout << "PONTEIRO: " << "NULLPOINTER" << std::endl;
            }
            else {
                std::cout << "PONTEIRO: " << item->next << std::endl;
            }

            if(item->next == nullptr) {
                break;
            }
            else {
                item = item->next;
            }

            std::cout << std::endl;
        }
    }
}

template <typename T>
T LinkedList<T>::get(int position) {
    Node<T> *item = head;
    int aux = 0;

    while(true) {
        if(aux == position) {
            return item->value;
        }

        if(item->next == nullptr) {
            throw std::runtime_error("OUT_OF_RANGE");
        }
        else {
            item = item->next;
            aux++;
        }
    }
}

template <typename T>
void LinkedList<T>::insert(int position, T value) {
    Node<T> *oldPointer = nullptr;
    Node<T> *newNode = new Node<T>;
    Node<T> *item = head;
    int aux = 0;

    (*newNode).value = value;

    while(true) {
        if(aux == position-1) {
            oldPointer = item->next;
            item->next = newNode;
        }
        else if(aux == position) {
            if(aux == 0) {
                if(head != nullptr) {
                    newNode->next = head;
                }
                else {
                    newNode->next = nullptr;
                }

                head = newNode;    
            }
            else {
                newNode->next = oldPointer;
            }
            
            break;
        }

        if(item->next != nullptr) {
            item = item->next;
            aux++;
        }
        else {
            break;
        }
    }
}

template <typename T>
void LinkedList<T>::push(T value) {
    Node<T> *node = new Node<T>;

    (*node).value = value;
    (*node).next = nullptr;

    if(head == nullptr) {
        head = node;
    }
    else {
        Node<T> *item = head;

        while(item->next != nullptr) {
            item = item->next;
        }

        item->next = node;
    }
}

template <typename T>
void LinkedList<T>::del(int position) {
    Node<T> *nodeBefore = nullptr;
    Node<T> *nodeAfter = nullptr;
    Node<T> *node = nullptr;
    Node<T> *item = head;
    int aux = 0;

    while(true) {
        if(aux == position-1) {
            nodeBefore = item;
        }
        else if(aux == position) {
            node = item;
        }
        else if(aux == position+1) {
            nodeAfter = item;

            break;
        }

        if(item->next != nullptr) {
            item = item->next;
            aux++;
        }
        else {
            break;
        }
    }

    if(nodeBefore == nullptr) {
        head = nodeAfter;
    }
    if(nodeAfter == nullptr) {
        if(nodeBefore != nullptr) {
            nodeBefore->next = nullptr;
        }
    }

    delete node;
}

template class LinkedList<int>;
template class LinkedList<char>;
template class LinkedList<bool>;
template class LinkedList<std::string>;