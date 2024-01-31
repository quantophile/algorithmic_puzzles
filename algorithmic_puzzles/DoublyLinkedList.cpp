#include "DoublyLinkedList.h"

void DoublyLinkedList::push_back(int element)
{
    if (m_head == nullptr)
    {
        m_head = std::make_shared<Node>(element, nullptr, nullptr);
        m_tail = m_head;
    }
    else
    {
        std::shared_ptr<Node> myNode = std::make_shared<Node>(element, nullptr, nullptr);
        m_tail->m_next = myNode;
        myNode->m_prev = m_tail;
        m_tail = myNode;
    }
}

DoublyLinkedList::DoublyLinkedList(std::initializer_list<int> l)
{
    for (int e : l)
    {
        push_back(e);
    }
}

void DoublyLinkedList::push_front(int element)
{
    if (m_head == nullptr)
    {
        m_head = std::make_shared<Node>(element, nullptr, nullptr);
        m_tail = m_head;
    }
    else {
        std::shared_ptr<Node> myNode = std::make_shared<Node>(element, m_head, nullptr);
        m_head->m_prev = myNode;
        m_head = myNode;
    }
}
