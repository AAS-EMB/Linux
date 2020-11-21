#include <iostream>
#include <algorithm>

void SortingChoice(int *pArray, unsigned int ArraySize);

int main(int argc, char *argv[])
{
	unsigned int ArraySize;

	std::cout << "\r\nSet the size of the array: ";
	std::cin >> ArraySize;
	int *Array = new int[ArraySize];
	std::cout << "\r\nEnter the values of the array elements" << std::endl;
	for(auto Iterator = &Array[0]; Iterator != (&Array[0] + ArraySize); Iterator++) {
		std::cin >> *Iterator;
	}
	SortingChoice(Array, ArraySize);
	std::cout << "\r\nSorted array by choice method" << std::endl;
	for(auto Iterator = &Array[0]; Iterator != (&Array[0] + ArraySize); Iterator++) {
		std::cout << "" << *Iterator << " ";
	}
	std::cout << std::endl;
	delete [] Array;
	return 0;
}

/*!
 * @brief The sort method of the choice
 * 
 * @param pArray    Pointer to the object
 * @param ArraySize Size object
 */
void SortingChoice(int *pArray, unsigned int ArraySize)
{
	for(auto Iterator = pArray; Iterator != (pArray + ArraySize); Iterator++) {
		for(auto It = Iterator; It != (pArray + ArraySize); It++) {
			if(*Iterator > *It) {
				std::swap(*Iterator, *It);
			}
		}
	}
}