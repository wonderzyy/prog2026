#pragma once

#include "dllist.h"

class Queue
{
    DLList data;

public:
    bool empty() const;
    std::size_t size() const;

    void push(double value);
    void pop();

    double front() const;
    double &front();
    double back() const;
    double &back();
};
