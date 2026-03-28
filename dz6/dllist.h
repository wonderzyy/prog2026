#pragma once
#include <cstddef>

class DLList
{
    struct Node
    {
        double data = 0.0;
        Node *next = nullptr;
        Node *prev = nullptr;
    };

    Node head{0.0, &head, &head};

    std::size_t size_ = 0;

public:
    DLList() = default;
    DLList(const DLList &);
    DLList(DLList &&) noexcept;
    DLList &operator=(const DLList &);
    DLList &operator=(DLList &&) noexcept;
    ~DLList();

    std::size_t size() const noexcept { return size_; }
    bool empty() const noexcept { return size() == 0; }

    double front() const { return head.next->data; }
    double &front() { return head.next->data; }
    double back() const { return head.prev->data; }
    double &back() { return head.prev->data; }

    void clear() noexcept;

    void pop_front();
    void pop_back(); 
    void push_front(double elem);
    void push_back(double elem);

    void debug() const;

private:
    void erase_(Node *) noexcept;
    void insert_after(Node *, double);
    void copy(const DLList &);
};