#include "QueueList.h"
#include <iostream>

//private

void QueueList::OutOfBoundErr() const
{
	std::cout << "Index out of bounds of the queue" << std::endl;
}

void QueueList::EmptyErr() const
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
		EmptyErr();
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

void QueueList::peek(int ind) const
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
		EmptyErr();
		return;
	}

	std::cout << "First element of the queue is " << m_front_ptr->data << std::endl;
}


void QueueList::size() const
{
	ListNode* it = m_front_ptr;
	int size = 0;
	while (it != nullptr)
	{
		++size;
		it = it->link;
	}

	std::cout << "sie of the queue is " << size << std::endl;
}

void QueueList::display() const
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
	if (this->isEmty())
	{
		EmptyErr();
		return;
	}

	ListNode* next = nullptr;
	ListNode* previous = nullptr;
	while (m_front_ptr != nullptr)
	{
		next = m_front_ptr->link;
		m_front_ptr->link = previous;
		previous = m_front_ptr;
		m_front_ptr = next;
	}
	m_front_ptr = previous;

	std::cout << "The queue has been reversed" << std::endl;
}

void PrintInstructions()
{
	std::cout << "Create a queue (maximim length is 10) using these commands:" << std::endl
		<< "\tadd -- adds inputed element to the queue" << std::endl
		<< "\trem -- removes first element in the queue" << std::endl
		<< "\tpeek -- reval element with inputed index of the queue" << std::endl
		<< "\tfront -- prints first element of the queue" << std::endl
		<< "\tisEmpty -- prints whether queue is empty or not (TRUE/FALSE)" << std::endl
		<< "\tdisplay -- prints all elements of th queue" << std::endl
		<< "\tclear -- clears all elements of the queue" << std::endl
		<< "\treverse -- reverts elements' order in the queue" << std::endl
		<< "\tsize -- prints size of the queue" << std::endl
		<< "\tq -- exit application" << std::endl
		<< std::endl;
}