#include "DoublyLinkedList.h"

void DoubleLinkedList::push_back(int element)
{
    if (m_head == nullptr)
    {
        m_head = std::make_shared<Node>(element, nullptr, nullptr);
    }
    else
    {
        std::shared_ptr<Node> myNode = std::make_shared<Node>(element, nullptr, nullptr);
        m_tail->m_next = myNode;
        myNode->m_prev = m_tail;
        m_tail = myNode;
    }
}

DoubleLinkedList::DoubleLinkedList(std::initializer_list<int> l)
{
    for (int e : l)
    {
        push_back(e);
    }
}

void DoubleLinkedList::push_front(int element)
{
    
}
