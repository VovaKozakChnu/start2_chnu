#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <array>
#include <vector>
#include <deque>
#include <utility>

template <typename T, std::size_t N, std::size_t M>
std::array<T, N + M> mergeArrays(const std::array<T, N>& arr1, const std::array<T, M>& arr2) {
    std::array<T, N + M> result;
    auto it1 = arr1.begin();
    auto it2 = arr2.begin();
    auto itRes = result.begin();

    while (it1 != arr1.end() && it2 != arr2.end()) {
        if (*it1 < *it2) {
            *itRes = *it1;
            ++it1;
        } else {
            *itRes = *it2;
            ++it2;
        }
        ++itRes;
    }

    while (it1 != arr1.end()) {
        *itRes = *it1;
        ++it1;
        ++itRes;
    }

    while (it2 != arr2.end()) {
        *itRes = *it2;
        ++it2;
        ++itRes;
    }

    return result;
}

template <typename T>
std::pair<std::vector<T>, std::vector<T>> partitionVector(const std::vector<T>& vec) {
    std::vector<T> evens;
    std::vector<T> odds;

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (*it % 2 == 0) {
            evens.push_back(*it);
        } else {
            odds.push_back(*it);
        }
    }
    return {evens, odds};
}

template <typename T>
bool isPalindrome(const std::deque<T>& dq) {
    if (dq.empty()) return true;

    auto left = dq.begin();
    auto right = dq.end();
    --right;

    while (left < right) {
        if (*left != *right) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

#endif
