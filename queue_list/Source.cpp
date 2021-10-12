#include <iostream>
#include "QueueList.h"

int main()
{
	QueueList q;
	std::string input;
	int el = 0;

	PrintInstructions();

	while (true)
	{
		std::cin >> input;
		if (input == "add")
		{
			std::cin >> el;
			q.enqueue(el);
		}
		else if (input == "peek")
		{
			std::cout << "enter index of element you want to show (numeration begins from 1):" << std::endl;
			std::cin >> el;
			q.peek(el);
		}
		else if (input == "rem") q.dequeue();
		else if (input == "display") q.display();
		else if (input == "front") q.front();
		else if (input == "isEmpty") std::cout << std::boolalpha << q.isEmty() << std::endl;
		else if (input == "clear") q.clear();
		else if (input == "size") q.size();
		else if (input == "reverse") q.reverse();
		else if (input == "q") return 0;
		else std::cout << "WRONG INPUT" << std::endl;
	}

}