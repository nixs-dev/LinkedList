#include "node.hpp"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H 

class LinkedList {
    Node *head = nullptr;

    public:
        void all();
        int get(int position);
        void insert(int position, int value);
        void push(int value);
        void del(int position);
};

#endif