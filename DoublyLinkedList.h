#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "Node.h"
#include <iostream>
#include <stdexcept>

template <typename T>
class DoublyLinkedList {
private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
    size_t listSize;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

    void push_front(T val) {
        auto newNode = std::make_shared<Node<T>>(val);
        if (empty()) {
            head = tail = newNode;
        } else {
            newNode->nextShared = head;
            head->prev = newNode;
            head = newNode;
        }
        listSize++;
    }

    void push_back(T val) {
        auto newNode = std::make_shared<Node<T>>(val);
        if (empty()) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->nextShared = newNode;
            tail = newNode;
        }
        listSize++;
    }

    void pop_front() {
        if (empty()) throw std::underflow_error("List is empty");
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->nextShared;
            head->prev.reset();
        }
        listSize--;
    }

    void pop_back() {
        if (empty()) throw std::underflow_error("List is empty");
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev.lock();
            tail->nextShared.reset();
        }
        listSize--;
    }

    T& operator[](size_t index) {
        if (index >= listSize) throw std::out_of_range("Index out of range");
        auto temp = head;
        for (size_t i = 0; i < index; ++i) temp = temp->nextShared;
        return temp->data;
    }

    void insert(size_t index, T val) {
        if (index > listSize) throw std::out_of_range("Index out of range");
        if (index == 0) return push_front(val);
        if (index == listSize) return push_back(val);
        auto temp = head;
        for (size_t i = 0; i < index; ++i) temp = temp->nextShared;
        auto newNode = std::make_shared<Node<T>>(val);
        newNode->nextShared = temp;
        newNode->prev = temp->prev;
        temp->prev.lock()->nextShared = newNode;
        temp->prev = newNode;
        listSize++;
    }

    void remove(size_t index) {
        if (index >= listSize) throw std::out_of_range("Index out of range");
        if (index == 0) return pop_front();
        if (index == listSize - 1) return pop_back();
        auto temp = head;
        for (size_t i = 0; i < index; ++i) temp = temp->nextShared;
        temp->prev.lock()->nextShared = temp->nextShared;
        temp->nextShared->prev = temp->prev;
        listSize--;
    }

    size_t size() const { return listSize; }
    bool empty() const { return listSize == 0; }

    bool find(T val) const {
        auto temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->nextShared;
        }
        return false;
    }

    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<T>& list) {
        auto temp = list.head;
        while (temp) {
            os << temp->data << " <-> ";
            temp = temp->nextShared;
        }
        os << "null";
        return os;
    }
};

#endif
