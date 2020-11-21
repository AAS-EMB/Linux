#include <iostream>
#include <algorithm>

void SortingBubble(int *pArray, unsigned int ArraySize);

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
	SortingBubble(Array, ArraySize - 1);
	std::cout << "\r\nSorted array by bubble method" << std::endl;
	for(auto Iterator = &Array[0]; Iterator != (&Array[0] + ArraySize); Iterator++) {
		std::cout << "" << *Iterator << " ";
	}
	std::cout << std::endl;
	delete [] Array;
	return 0;
}

/*!
 * @brief The sort method of the bubble
 * 
 * @param pArray    Pointer to the object
 * @param ArraySize Size object
 */
void SortingBubble(int *pArray, unsigned int ArraySize)
{
	bool IsEndSorting = false;

	while(IsEndSorting == false) {
		IsEndSorting = true;
		for(auto Iterator = pArray; Iterator != (pArray + ArraySize); Iterator++) {
			if(*Iterator > *(Iterator + 1)) {
				std::swap(*Iterator, *(Iterator + 1));
				IsEndSorting = false;
			}
		}
	}
}
