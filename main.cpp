#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include <string>

int main() {
    try {
        SinglyLinkedList<int> sList;
        sList.push_back(10);
        sList.push_front(5);
        sList.insert(1, 7);
        std::cout << "Singly: " << sList << " Size: " << sList.size() << std::endl;

        DoublyLinkedList<std::string> dList;
        dList.push_back("World");
        dList.push_front("Hello");
        std::cout << "Doubly: " << dList << " Found 'Hello': " << dList.find("Hello") << std::endl;

        dList.pop_back();
        std::cout << "After pop: " << dList << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
