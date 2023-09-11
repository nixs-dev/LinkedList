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

int LinkedList::get(int position) {
    Node *item = head;
    int aux = 0;

    while(true) {
        if(aux == position) {
            return item->value;
        }

        if(item->next == nullptr) {
            return -1;
        }
        else {
            item = item->next;
        }
    }
}

void LinkedList::insert(int position, int value) {
    Node *oldPointer = nullptr;
    Node *newNode = new Node;
    Node *item = head;
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

void LinkedList::push(int value) {
    Node *node = new Node();

    (*node).value = value;
    (*node).next = nullptr;

    if(head == nullptr) {
        head = node;
    }
    else {
        Node *item = head;

        while(item->next != nullptr) {
            item = item->next;
        }

        item->next = node;
    }
}

void LinkedList::del(int position) {
    Node *nodeBefore = nullptr;
    Node *nodeAfter = nullptr;
    Node *node = nullptr;
    Node *item = head;
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