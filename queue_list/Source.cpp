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
}