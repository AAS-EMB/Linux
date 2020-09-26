#include <string>
#include <array>
#include "list.h"

/*!
 * @brief Constructor of the List class
 */
List::List(void)
{
	pListHead = new List_t;
	pListHead->CurrentList = 0;
	pListHead->pNextList = nullptr;
	std::cout << "The constructor of the List class was called. Memory is allocated dynamically!" << std::endl;
}

/*!
 * @brief Destructor of the List class
 */
List::~List(void)
{
	List_t *pTempList = nullptr;

	while(pListHead != nullptr) 
	{
		pTempList = pListHead;
		pListHead = pListHead->pNextList;
		delete pTempList; 
	}
	std::cout << "The destructor of the List class was called. Memory released!" << std::endl;
}

/*!
 * @brief Added new list 
 * @param NumberList Current number list
 */
void List::AddNewList(unsigned int NumberList)
{
	List_t *pTempList_1 = nullptr, *pTempList_2 = nullptr;

	pTempList_1 = pListHead;
	while(pTempList_1->pNextList != nullptr)
		pTempList_1 = pTempList_1->pNextList;
	pTempList_2 = new List_t;
	pTempList_2->CurrentList = NumberList;
	pTempList_2->pNextList = nullptr;
	pTempList_1->pNextList = pTempList_2;
}

/*!
 * @brief Remove single list 
 * @param NumberList Current number list
 */
void List::RemoveSingleList(unsigned int NumberList)
{
	unsigned int CurrentIndex = 0;
	List_t *pPrevList = nullptr, *pCurrList = nullptr;
		
	pCurrList = pListHead;
	while(CurrentIndex != NumberList)
	{
		pPrevList = pCurrList;
		pCurrList = pCurrList->pNextList;
		CurrentIndex++;
	}
	pPrevList->pNextList = pCurrList->pNextList;
	delete pCurrList;
}

/*!
 * @brief Print all list 
 */
void List::PrintAllList(void)
{
	List_t *pTempList = nullptr;

	pTempList = pListHead;
	while(pTempList != nullptr)
	{
		std::cout << "Current list: " << pTempList->CurrentList + 1 << "\t\tCurrent address list: " << pTempList << "\t\tNext address list: " << pTempList->pNextList << std::endl;
		pTempList = pTempList->pNextList;
	}
}

/*!
 * @brief Print single list 
 * @param NumberList Current number list
 */
void List::PrintSingleList(unsigned int NumberList)
{
	unsigned int CurrentIndex = 0;
	List_t *pTempList = nullptr;

	pTempList = pListHead;
	while(CurrentIndex != NumberList)
	{
		pTempList = pTempList->pNextList;
		CurrentIndex++;
	}
	std::cout << "Number list: " << pTempList->CurrentList + 1 << "\t\tCurrent address list: " << pTempList << "\t\tNext address list: " << pTempList->pNextList << std::endl;
}