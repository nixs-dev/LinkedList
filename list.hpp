#include "node.hpp"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H 

template <typename T>

class LinkedList {
    Node<T> *head = nullptr;

    public:
        void all();
        T get(int position);
        void insert(int position, T value);
        void push(T value);
        void del(int position);
};

#endif