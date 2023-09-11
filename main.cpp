#include "iostream"
#include "list.hpp"


int main() {
    LinkedList list = LinkedList();

    list.insert(0, 5);

    list.all();

    return 0;
}