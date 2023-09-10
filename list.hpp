#include "node.hpp"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H 

class LinkedList {
    Node *head;

    public:
        void all();
        void push(int value);
};

#endif