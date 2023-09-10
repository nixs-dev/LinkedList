#include "list.hpp"


int main() {
    LinkedList list = LinkedList();

    list.push(0);
    list.push(1);
    list.push(2);
    list.push(3);

    list.all();

    return 0;
}