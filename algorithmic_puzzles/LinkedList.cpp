#include "LinkedList.h"

LinkedList::LinkedList(std::initializer_list<int> l)
{
	for (int e : l)
	{
		push_back(e);
	}
}

void LinkedList::push_back(int element)
{
	if (m_head == nullptr)
	{
		m_head = std::make_shared<Node>(element, nullptr);
	}
	else {
		std::shared_ptr<Node> it = m_head;

		while (it->m_next != nullptr)
			it = it->m_next;

		it->m_next = std::make_shared<Node>(element, nullptr);
	}
}

void LinkedList::push_front(int element)
{
	std::shared_ptr<Node> myNode = std::make_shared<Node>(element, m_head);
	m_head = myNode;
}

void LinkedList::insert_at_k(int k, int element)
{
	std::shared_ptr<Node> pred = nullptr;
	std::shared_ptr<Node> it = m_head;
	for (int i{ 1 }; i < k; ++i)
	{
		if (it == nullptr)
			return;

		pred = it;
		it = it->m_next;
	}

	if (pred == nullptr)
	{
		m_head = std::make_shared<Node>(element, m_head);
	}
	else
	{
		std::shared_ptr<Node> myNode = std::make_shared<Node>(element, nullptr);
		myNode->m_next = pred->m_next;
		pred->m_next = myNode;
	}
}

void LinkedList::pop_back()
{
	std::shared_ptr<Node> pred = nullptr;
	std::shared_ptr<Node> it = m_head;

	if (m_head == nullptr)
		return;

	if (m_head->m_next == nullptr)
	{
		m_head = nullptr;
		return;
	}

	while (it->m_next != nullptr)
	{
		pred = it;
		it = it->m_next;
	}

	pred->m_next = nullptr;
	it = nullptr;
}

void LinkedList::pop_front()
{
	m_head = m_head->m_next;
}