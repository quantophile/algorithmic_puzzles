#include <iostream>
#include <memory>
#include <ostream>

using namespace std;

class LinkedList {
public:
	class Node {
	public:
		Node(int data, std::shared_ptr<Node> next) : m_data{ data }, m_next{ next } {}

		int m_data;
		std::shared_ptr<Node> m_next;

	};

	LinkedList() { m_head = nullptr; }

	LinkedList(std::initializer_list<int> l);

	std::shared_ptr<Node> m_head;
	void push_back(int element);
	void push_front(int element);
	void pop_back();
	void pop_front();

	/*
	* You are given two sorted linked lists list1 and list2.

	Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

	Return the merged linked list.
	*/
	friend LinkedList merge_two_lists(LinkedList& list1, LinkedList& list2)
	{
		std::shared_ptr<Node> l1 = list1.m_head;
		std::shared_ptr<Node> l2 = list2.m_head;
		LinkedList result{};

		while (l1 != nullptr && l2 != nullptr)
		{
			if (l1->m_data < l2->m_data)
			{
				result.push_back(l1->m_data);
				l1 = l1->m_next;
			}
			else
			{
				result.push_back(l2->m_data);
				l2 = l2->m_next;
			}
		}

		while (l1 != nullptr)
		{
			result.push_back(l1->m_data);
			l1 = l1->m_next;
		}

		while (l2 != nullptr)
		{
			result.push_back(l2->m_data);
			l2 = l2->m_next;
		}

		return result;
	}

	void insert_at_k(int k, int element);
	LinkedList operator+(const LinkedList& l);

	friend std::ostream& operator<<(std::ostream& out, LinkedList& l)
	{
		std::shared_ptr<Node> it = l.m_head;

		if (l.m_head == nullptr)
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