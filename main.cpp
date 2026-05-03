#include <iostream>
#include "algorithms.h"
#include "Employee.h"

template <typename TContainer>
void printContainer(const TContainer& container, const std::string& msg) {
    std::cout << msg << ": ";
    for (auto it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cout << "========== TESTING WITH INT TYPE ==========\n\n";

    std::array<int, 3> arr1 = {1, 3, 5};
    std::array<int, 4> arr2 = {2, 4, 6, 8};
    auto mergedArr = mergeArrays(arr1, arr2);
    std::cout << "--- Task 1: std::array ---\n";
    printContainer(mergedArr, "Merged array");

    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};
    auto partitions = partitionVector(vec);
    std::cout << "\n--- Task 2: std::vector ---\n";
    printContainer(partitions.first, "Even numbers");
    printContainer(partitions.second, "Odd numbers");

    std::deque<int> deq1 = {1, 2, 3, 2, 1};
    std::deque<int> deq2 = {1, 2, 3, 4, 5};
    std::cout << "\n--- Task 3: std::deque ---\n";
    std::cout << "Is Deque 1 {1, 2, 3, 2, 1} a palindrome? " << (isPalindrome(deq1) ? "Yes" : "No") << "\n";
    std::cout << "Is Deque 2 {1, 2, 3, 4, 5} a palindrome? " << (isPalindrome(deq2) ? "Yes" : "No") << "\n";

    std::cout << "\n\n========== TESTING WITH EMPLOYEE CLASS ==========\n\n";

    std::array<Employee, 2> empArr1 = {Employee(1, "Oleg"), Employee(4, "Maria")};
    std::array<Employee, 3> empArr2 = {Employee(2, "Ivan"), Employee(3, "Anna"), Employee(5, "Taras")};
    auto mergedEmpArr = mergeArrays(empArr1, empArr2);
    std::cout << "--- Task 1: std::array ---\n";
    printContainer(mergedEmpArr, "Merged employee array");

    std::vector<Employee> empVec = {
        Employee(10, "Dev1"), Employee(11, "Dev2"),
        Employee(12, "HR1"), Employee(13, "Manager1")
    };
    auto empPartitions = partitionVector(empVec);
    std::cout << "\n--- Task 2: std::vector ---\n";
    printContainer(empPartitions.first, "Employees with even IDs");
    printContainer(empPartitions.second, "Employees with odd IDs");

    std::deque<Employee> empDeq = {
        Employee(100, "X"), Employee(200, "Y"), Employee(100, "X")
    };
    std::cout << "\n--- Task 3: std::deque ---\n";
    std::cout << "Is Deque Employee {X, Y, X} a palindrome? " << (isPalindrome(empDeq) ? "Yes" : "No") << "\n";

    return 0;
}
