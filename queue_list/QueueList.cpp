#include "QueueList.h"
#include <iostream>

//private

void QueueList::OutOfBoundErr() const
{
	std::cout << "Index out of bounds of the queue" << std::endl;
}

void QueueList::emptyMessage() const
{
	std::cout << "Queue is empty" << std::endl;
}

//public

QueueList::QueueList()
	:m_front_ptr(nullptr), m_back_ptr(nullptr)
{
}

QueueList::~QueueList()
{
	QueueList::clear();
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
		emptyMessage();
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

	if (ind < 1 || this->isEmty())
	{
		OutOfBoundErr();
		return;
	}

	ListNode* it = m_front_ptr;
	for (int i = 0; i < ind -1 ; ++i)
	{
		it = it->link;
		if (it == nullptr)
		{
			OutOfBoundErr();
			return;
		}
	}

	std::cout << "element with index #" << ind << " is " << it->data << std::endl;
}


void QueueList::front() const
{
	if (this->isEmty())
	{
		emptyMessage();
		return;
	}

	std::cout << "First element of the queue is " << m_front_ptr->data << std::endl;
}


int QueueList::size() const
{
	ListNode* it = m_front_ptr;
	int size = 0;
	while (it != nullptr)
	{
		++size;
		it = it->link;
	}

	return size;
}



void QueueList::display()
{
	ListNode* it = m_front_ptr;
	while (it != nullptr)
	{
		std::cout << it->data << ' ';
		it = it->link;
	}

	std::cout << std::endl;
}

void QueueList::clear()
{
	ListNode* it = m_front_ptr;
	while (it != nullptr)
	{
		ListNode* del_it = it;
		it = it->link;
		delete del_it;
	}

	m_back_ptr = nullptr;
	m_front_ptr = nullptr;
}

void QueueList::reverse()
{
	int* copy = new int[this->size()];

	ListNode* it = m_front_ptr;
	for (int i = 0; i < this->size(); ++i)
	{
		copy[i] = it->data;
		it = it->link;
	}

	it = m_front_ptr;
	for (int i = this->size() - 1; i >= 0;  --i)
	{
		it->data = copy[i];
		it = it->link;
	}

	std::cout << "queue reversed" << std::endl;
}