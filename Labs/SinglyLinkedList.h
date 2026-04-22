#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include "Node.h"
#include <iostream>
#include <stdexcept>

template <typename T>
class SinglyLinkedList {
private:
    std::unique_ptr<Node<T>> head;
    size_t listSize;

public:
    SinglyLinkedList() : head(nullptr), listSize(0) {}

    void push_front(T val) {
        auto newNode = std::make_unique<Node<T>>(val);
        newNode->next = std::move(head);
        head = std::move(newNode);
        listSize++;
    }

    void push_back(T val) {
        auto newNode = std::make_unique<Node<T>>(val);
        if (!head) {
            head = std::move(newNode);
        } else {
            Node<T>* temp = head.get();
            while (temp->next) temp = temp->next.get();
            temp->next = std::move(newNode);
        }
        listSize++;
    }

    void pop_front() {
        if (!head) throw std::underflow_error("List is empty");
        head = std::move(head->next);
        listSize--;
    }

    void pop_back() {
        if (!head) throw std::underflow_error("List is empty");
        if (!head->next) {
            head.reset();
        } else {
            Node<T>* temp = head.get();
            while (temp->next->next) temp = temp->next.get();
            temp->next.reset();
        }
        listSize--;
    }

    T& operator[](size_t index) {
        if (index >= listSize) throw std::out_of_range("Index out of range");
        Node<T>* temp = head.get();
        for (size_t i = 0; i < index; ++i) temp = temp->next.get();
        return temp->data;
    }

    void insert(size_t index, T val) {
        if (index > listSize) throw std::out_of_range("Index out of range");
        if (index == 0) return push_front(val);
        Node<T>* temp = head.get();
        for (size_t i = 0; i < index - 1; ++i) temp = temp->next.get();
        auto newNode = std::make_unique<Node<T>>(val);
        newNode->next = std::move(temp->next);
        temp->next = std::move(newNode);
        listSize++;
    }

    void remove(size_t index) {
        if (index >= listSize) throw std::out_of_range("Index out of range");
        if (index == 0) return pop_front();
        Node<T>* temp = head.get();
        for (size_t i = 0; i < index - 1; ++i) temp = temp->next.get();
        temp->next = std::move(temp->next->next);
        listSize--;
    }

    size_t size() const { return listSize; }
    bool empty() const { return listSize == 0; }

    bool find(T val) const {
        Node<T>* temp = head.get();
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next.get();
        }
        return false;
    }

    friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList<T>& list) {
        Node<T>* temp = list.head.get();
        while (temp) {
            os << temp->data << " -> ";
            temp = temp->next.get();
        }
        os << "null";
        return os;
    }
};

#endif
