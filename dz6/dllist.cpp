#include "dllist.h"
#include <utility>
#include <iostream>
using namespace std;

DLList::DLList(const DLList &other):DLList()
{
    *this = other;
}

DLList::DLList(DLList &&other) noexcept
{
    *this = std::move(other);
}

DLList &DLList::operator=(const DLList &other)
{
    if (this == &other)
        return *this;
    clear();
    copy(other);
    return *this;
}

void DLList::copy(const DLList &other)
{
    Node *cur = other.head.next;
    while (cur != &other.head)
    {
        push_back(cur->data);
        cur = cur->next;
    }
}

DLList &DLList::operator=(DLList &&other) noexcept
{
    if (this == &other)
        return *this;
    clear();
    head = other.head;
    size_ = other.size();
    head.next->prev = &head;
    head.prev->next = &head;
    other.head.next = &(other.head);
    other.head.prev = &(other.head);
    other.size_ = 0;
    return *this;
}

DLList::~DLList()
{
    clear();
}

void DLList::clear() noexcept
{
    while (!empty())
        erase_(head.next);
}

void DLList::erase_(Node *v) noexcept
{
    auto prev = v->prev;
    v->next->prev = prev;
    prev->next = v->next;
    delete v;
    --size_;
}

void DLList::pop_front()
{
    erase_(head.next);
}

void DLList::pop_back()
{
    erase_(head.prev);
}

void DLList::insert_after(Node *v, double elem)
{
    auto node = new Node{elem, v->next, v};
    v->next->prev = node;
    v->next = node;
    ++size_;
}

void DLList::push_front(double elem)
{
    insert_after(&head, elem);
}

void DLList::push_back(double elem)
{
    insert_after(head.prev, elem);
}

void DLList::debug() const
{
    Node *cur = head.next;
    while (cur != &head)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}
