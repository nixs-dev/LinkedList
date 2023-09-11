#include "iostream"
#include "list.hpp"


int main() {
    LinkedList list = LinkedList();

    list.push(0);
    list.push(1);
    list.push(3);
    list.push(4);

    list.insert(4, 5);

    list.all();

    return 0;
}