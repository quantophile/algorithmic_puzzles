// DoubleLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <memory>

class DoubleLinkedList {
public:
    class Node {
    public:
        int m_data;
        std::shared_ptr<Node> m_next;
        std::shared_ptr<Node> m_prev;

        Node(int data, std::shared_ptr<Node> next, std::shared_ptr<Node> prev) : m_data(data), m_next(next), m_prev(prev) {}
    };

    std::shared_ptr<Node> m_head;
    std::shared_ptr<Node> m_tail;

    DoubleLinkedList() { m_head = nullptr; m_tail = nullptr; }
    DoubleLinkedList(std::initializer_list<int> l);

    void push_back(int element);
    void push_front(int element);
    void pop_back();
    void pop_front();
    void insert_at_k(int element);
    void delete_at_k(int element);
    void reverse();

    friend std::ostream& operator<<(std::ostream& out, DoubleLinkedList& l)
    {
        auto it = l.m_head;

        if (it == nullptr)
            return out;

        while (it->m_next != nullptr)
        {
            out << it->m_data << "->";
            it = it->m_next;
        }

        out << it->m_data << "\n";
        return out;
    }
};
