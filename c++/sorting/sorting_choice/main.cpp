#include <iostream>

void SortingChoice(int *pArray, unsigned int ArraySize);

int main(int argc, char *argv[])
{
	unsigned int ArraySize;

	std::cout << "\r\nSet the size of the array: ";
	std::cin >> ArraySize;
	int *Array = new int[ArraySize];
	std::cout << "\r\nEnter the values of the array elements" << std::endl;
	for(unsigned int CurrentIndex = 0; CurrentIndex < ArraySize; CurrentIndex++)
	{
		std::cout << "\r\nElement number " << CurrentIndex << ": ";
		std::cin >> Array[CurrentIndex];
	}
	SortingChoice(Array, ArraySize);
	std::cout << "\r\nSorted array by choice method" << std::endl;
	for(unsigned int CurrentIndex = 0; CurrentIndex < ArraySize; CurrentIndex++)
	{
		std::cout << "" << Array[CurrentIndex] << " ";
	}
	std::cout << std::endl;
	delete [] Array;
	return 0;
}

/*!
 * @brief The sort method of the choice
 * @param pArray Pointer to the object
 * @param ArraySize Size object
 */
void SortingChoice(int *pArray, unsigned int ArraySize)
{
	int TempValue;

	for(unsigned int CurrentSortIndex = 0; CurrentSortIndex < ArraySize; CurrentSortIndex++)
	{
		for(unsigned int CurrentIndex = CurrentSortIndex + 1; CurrentIndex < ArraySize; CurrentIndex++)
		{
			if(pArray[CurrentSortIndex] > pArray[CurrentIndex])
			{
				TempValue = pArray[CurrentSortIndex];
				pArray[CurrentSortIndex] = pArray[CurrentIndex];
				pArray[CurrentIndex] = TempValue;
			}
		}
	}
}