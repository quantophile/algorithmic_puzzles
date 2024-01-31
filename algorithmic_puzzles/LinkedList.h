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
	void insert_at_k(int k, int element);

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