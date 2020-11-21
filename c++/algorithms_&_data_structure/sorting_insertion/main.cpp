#include <iostream>

void SortingInsertion(int *pArray, unsigned int ArraySize);

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
	SortingInsertion(Array, ArraySize);
	std::cout << "\r\nSorted array by insertion method" << std::endl;
	for(auto Iterator = &Array[0]; Iterator != (&Array[0] + ArraySize); Iterator++) {
		std::cout << "" << *Iterator << " ";
	}
	std::cout << std::endl;
	delete [] Array;
	return 0;
}

/*!
 * @brief The sort method of the insertion
 * 
 * @param pArray    Pointer to the object
 * @param ArraySize Size object
 */
void SortingInsertion(int *pArray, unsigned int ArraySize)
{
	int TempValue, PrevIndex;

	for(unsigned int CurrentIndex = 1; CurrentIndex < ArraySize; CurrentIndex++) {
		TempValue = pArray[CurrentIndex];
		PrevIndex = CurrentIndex - 1;
		while(PrevIndex >= 0 && pArray[PrevIndex] > TempValue) {
			pArray[PrevIndex + 1] = pArray[PrevIndex];
			pArray[PrevIndex] = TempValue;
			PrevIndex--;
		}
	}
}