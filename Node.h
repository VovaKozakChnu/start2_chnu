#ifndef NODE_H
#define NODE_H

#include <memory>

template <typename T>
struct Node {
    T data;
    std::unique_ptr<Node<T>> next;
    std::shared_ptr<Node<T>> nextShared;
    std::weak_ptr<Node<T>> prev;

    Node(T val) : data(val), next(nullptr), nextShared(nullptr) {}
};

#endif
