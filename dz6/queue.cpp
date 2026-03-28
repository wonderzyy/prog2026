#include "queue.h"

bool Queue::empty() const
{
    return data.empty();
}

std::size_t Queue::size() const
{
    return data.size();
}

void Queue::push(double value)
{
    data.push_back(value);
}

void Queue::pop()
{
    data.pop_front();
}

double Queue::front() const
{
    return data.front();
}

double &Queue::front()
{
    return data.front();
}

double Queue::back() const
{
    return data.back();
}

double &Queue::back()
{
    return data.back();
}
