#include "QueueList.h"
#include <iostream>

QueueList::QueueList()
	:m_front_ptr(nullptr), m_back_ptr(nullptr)
{
}

QueueList::~QueueList()
{
}

const bool QueueList::isEmty() const { return m_front_ptr == nullptr; }

void QueueList::enqueue(int el_data)
{
	ListNode* el_ptr = new ListNode;
	el_ptr->data = el_data;

	if (m_front_ptr == nullptr)
	{
		m_front_ptr = el_ptr;
		m_back_ptr = el_ptr;
		return;
	}

	m_back_ptr->link = el_ptr;
	m_back_ptr = el_ptr;
}


void QueueList::dequeue()
{
	if (this->isEmty())
	{
		std::cout << "The queue is empty. Nothing to delete" << std::endl;
		return;
	}
	if (m_front_ptr == m_back_ptr)
	{
		delete m_front_ptr;
		return;
	}
	ListNode* del_node = m_front_ptr;
	m_front_ptr = m_front_ptr->link;
	delete del_node;
}



void QueueList::peek(int ind)
{

	if (ind < 1)
	{
		std::cout << "index is out of queue bounds" << std::endl;
		return;
	}

	ListNode* it = m_front_ptr;
	for (int i = 0; i < ind -1 ; ++i)
	{
		it = it->link;
		if (it == nullptr)
		{
			std::cout << "index is out of queue bounds" << std::endl;
			return;
		}
	}

	std::cout << "element with index #" << ind << " is " << it->data << std::endl;
}