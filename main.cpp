#include "List.h"
#include <fstream>
int main()
{
	std::ifstream ifs;
	std::string input = "input.txt";
	ifs.open(input);
	char command;
	int pos, val;
	List<int>* list = nullptr;
	try
	{
		while (ifs >> command)
		{
			switch (command) {
			case 'u':
				list = new List<int>();
				break;
			case'a':
				ifs >> val;
				list->add(val);
				printf("Add: %d\n", val);
				break;
			case 'c':
				list->clear();
				printf("Clear list\n");
				break;
			case 'g':
				ifs >> pos;
				printf("Element at %d: %d\n", pos, list->get(pos));
				break;
			case'i':
				ifs >> pos >> val;
				list->insert(pos, val);
				printf("Insert at %d: %d\n", pos, val);
				break;
			case'd':
				ifs >> val;
				list->remove(val);
				printf("Delete: %d\n", val);
				break;
			case 's':
				ifs >> val;
				printf("Search %d: %d\n", val, list->search(val));
				break;
			case 'r':
				ifs >> pos;
				list->removeAt(pos);
				printf("Remove position: %d\n", pos);
				break;
			case'p':
				
				list->printList();
				printf("\n");
				break;
			case'x':
				list->printDetail();
				printf("\n");
				break;
			default:
				throw "Wrong input format!";
			}
		}
	}
	catch (const char * error)
	{
		printf("Error: %s", error);
	}
	return 0;
}