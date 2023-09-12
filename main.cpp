#include "iostream"
#include "list.hpp"


int main() {
    LinkedList<std::string> list = LinkedList<std::string>();

    list.push("assa");
    list.push("ka");
    list.push("dd");

    list.all();

    return 0;
}