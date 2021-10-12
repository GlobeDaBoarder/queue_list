#include "QueueList.h"

QueueList::QueueList()
	:m_front_ptr(nullptr), m_back_ptr(nullptr)
{
}

QueueList::~QueueList()
{
}



void QueueList::enqueue(int el_data)
{
	ListNode* el_ptr = new ListNode;
	el_ptr->data = el_data;

	if (m_front_ptr == 0)
	{
		m_front_ptr = el_ptr;
		m_back_ptr = el_ptr;
		return;
	}

	m_back_ptr->link = el_ptr;
	m_back_ptr = el_ptr;
}