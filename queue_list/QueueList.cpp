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
