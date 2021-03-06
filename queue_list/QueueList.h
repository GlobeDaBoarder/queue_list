
#pragma once
#include "ListNode.h"

class QueueList
{
private:
	ListNode* m_front_ptr;
	ListNode* m_back_ptr;

private:
	void OutOfBoundErr() const;
	void EmptyErr() const;

public:
	QueueList();
	~QueueList();
	const bool isEmty() const;
	void enqueue(int);
	void dequeue();
	void peek(int) const;
	void front() const;
	void size() const;
	void display()const;
	void clear();
	void reverse();
};

void PrintInstructions();

