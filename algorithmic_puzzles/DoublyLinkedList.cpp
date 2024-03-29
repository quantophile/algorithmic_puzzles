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
    ++length;
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
    ++length;
}

void DoublyLinkedList::insert_at_k(int k, int element)
{
    if (k > length)
    {
        return;
    }

    if (k == 1)
    {
        push_front(element);
        return;
    }
    
    std::shared_ptr<Node> it = nullptr;

    for (int i{ 1 }; i < k; ++i)
    {
        if (i == 1)
            it = m_head;
        else
            it = it-> m_next;
    }

    std::shared_ptr<Node> myNode = std::make_shared<Node>(element, it->m_next, it);
    it->m_next->m_prev = myNode;
    it->m_next = myNode;
    ++length;
}

void DoublyLinkedList::delete_at_k(int k)
{
    if (k<=0 || k > length)
        return;

    if (k == 1)
    {
        m_head->m_next->m_prev = nullptr;
        m_head = m_head->m_next;
        --length;
        return;
    }

    if (k == length)
    {
        m_tail = m_tail->m_prev;
        m_tail->m_next = nullptr;
        --length;
        return;
    }

    std::shared_ptr<Node> it = nullptr;
    for (int i{ 1 }; i <= k; ++i)
    {
        if (i == 1)
            it = m_head;
        else
            it = it->m_next;
    }
    it->m_prev->m_next = it->m_next;
    it->m_next->m_prev = it->m_prev;
    --length;
}

void DoublyLinkedList::pop_back()
{
    if (length == 0)
        return;

    if (length == 1)
    {
        m_head = m_tail = nullptr;
        --length;
        return;
    }
        
    m_tail->m_prev->m_next = nullptr;
    --length;
}

void DoublyLinkedList::pop_front()
{
    if (length == 0)
        return;

    if (length == 1)
    {
        m_head = m_tail = nullptr;
        --length;
        return;
    }

    m_head = m_head->m_next;
    m_head->m_prev = nullptr;
    --length;
}
