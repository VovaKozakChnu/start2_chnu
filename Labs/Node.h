#ifndef NODE_H
#define NODE_H

#include <memory>

template <typename T>
struct Node {
    T data;
    std::unique_ptr<Node<T>> next; // Для однозв'язного
    std::shared_ptr<Node<T>> nextShared; // Для двозв'язного
    std::weak_ptr<Node<T>> prev; // Для двозв'язного

    Node(T val) : data(val), next(nullptr), nextShared(nullptr) {}
};

#endif
