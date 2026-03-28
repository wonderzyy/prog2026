#pragma once

#include "dllist.h"

class Stack
{
    DLList data;

public:
    bool empty() const;
    std::size_t size() const;

    void push(double value);
    void pop();

    double top() const;
    double &top();
};
