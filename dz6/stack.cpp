#include "stack.h"

bool Stack::empty() const
{
    return data.empty();
}

std::size_t Stack::size() const
{
    return data.size();
}

void Stack::push(double value)
{
    data.push_back(value);
}

void Stack::pop()
{
    data.pop_back();
}

double Stack::top() const
{
    return data.back();
}

double &Stack::top()
{
    return data.back();
}
