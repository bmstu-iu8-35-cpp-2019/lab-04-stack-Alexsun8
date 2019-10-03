// Copyright 2019 alexsun.8 <alexsun24@yahoo.com>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <cstddef>
#include <iostream>
#include <type_traits>

template <typename T>
class stack
{
private:
    T* _data;
    size_t _size, _capacity;

    stack(const stack& st) = default;
    stack(stack& st) = default;
public:
    stack();
    stack(stack&& Stack) noexcept;
    ~stack();
    void push(T&& value);
    void push(const T& value);
    void pop();
    const T& head() const;
};

template <typename T>
class Stack
{
private:
    T* _data;
    size_t _size, _capacity;

    Stack(const Stack& st) = default;
    Stack(Stack& st) = default;
public:
    Stack();
    Stack(Stack&& Stack) noexcept;
    ~Stack();
    template <typename ... Args>
    void push_emplace(Args&&... value);
    void push(T&& value);
    const T& head() const;
    T pop();
};

#endif // INCLUDE_HEADER_HPP_
