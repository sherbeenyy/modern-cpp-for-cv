#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <array>
#include <iostream>

template <typename T>
void printVector(const std::vector<T> &vec)
{
    std::cout << "================================" << std::endl;
    std::cout << "Vector (size: " << vec.size() << "): ";
    for (const auto &item : vec)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    std::cout << "================================" << std::endl;
}

template <typename T, size_t N>
void printArray(const std::array<T, N> &arr)
{
    std::cout << "================================" << std::endl;
    std::cout << "Array (size: " << N << "): ";
    for (const auto &item : arr)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    std::cout << "================================" << std::endl;
}

template <typename T, size_t N>
void printCArray(const T (&arr)[N])
{
    std::cout << "================================" << std::endl;
    std::cout << "C-Array (size: " << N << "): ";
    for (size_t i = 0; i < N; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "================================" << std::endl;
}

#endif // UTILS_H
