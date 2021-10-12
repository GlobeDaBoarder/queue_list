#include <iostream>
#include "QueueList.h"

int main()
{
	QueueList q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);

	q.dequeue();
	q.enqueue(4);

	q.peek(1);
	q.peek(2);
	q.peek(3);
	q.peek(0);
	q.peek(4);

	q.front();

	q.size();

	q.display();

	q.reverse();

	q.display();

	q.clear();

	q.dequeue();

	std::cout << q.size() << std::endl;;

	std::cout << q.isEmty();

}