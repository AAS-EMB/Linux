#pragma once
#include <string>
#include <iostream>

/* Structure single list */
typedef struct List_s 
{
	unsigned int CurrentList;
	struct List_s *pNextList;
}List_t;

/* Class List */
class List 
{
	public:
		List(void);
		~List(void);
		void AddNewList(unsigned int NumberList);
		void RemoveSingleList(unsigned int NumberList);
		void PrintAllList(void);
		void PrintSingleList(unsigned int NumberList);
	private:
		List_t *pListHead = NULL;
};