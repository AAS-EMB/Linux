#include <iostream>
#include "list.h"

int main(int argc, char *arg[])
{
	unsigned int NumberLists;
	unsigned int NumberListPrint;

	setlocale(0,"");
	std::cout << "\r\nPlease, enter quantity lists: ";
	std::cin >> NumberLists;

	List *pListClass = new List();

	for(unsigned int i = 1; i < NumberLists; i++)
		pListClass->AddNewList(i);
	std::cout << "\r\nPrint all lists" << std::endl;
	pListClass->PrintAllList();
	std::cout << "\r\nPlease, enter number of list for print and remove: ";
	std::cin >> NumberListPrint;
	if(NumberListPrint <= NumberLists && NumberListPrint != 1)
	{
		pListClass->PrintSingleList(NumberListPrint - 1);
		pListClass->RemoveSingleList(NumberListPrint - 1);
	}
	else
		std::cerr << "\r\nError print and remove!!!" << std::endl;

	std::cout << "\r\nPrint new all lists after remove single list" << std::endl;
	pListClass->PrintAllList();
	delete pListClass;
	return 0;
}