#include <iostream>

void SortingBubble(int *pArray, unsigned int ArraySize);

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

	SortingBubble(Array, ArraySize - 1);
	std::cout << "\r\nSorted array by bubble method" << std::endl;
	for(unsigned int CurrentIndex = 0; CurrentIndex < ArraySize; CurrentIndex++)
	{
		std::cout << "" << Array[CurrentIndex] << " ";
	}
	std::cout << std::endl;
	delete [] Array;
	return 0;
}

/*!
 * @brief The sort method of the bubble
 * @param pArray Pointer to the object
 * @param ArraySize Size object
 */
void SortingBubble(int *pArray, unsigned int ArraySize)
{
	int TempValue;
	bool IsEndSorting = false;

	while(IsEndSorting == false)
	{
		IsEndSorting = true;
		for(unsigned int CurrentIndex = 0; CurrentIndex < ArraySize; CurrentIndex++)
		{
			if(pArray[CurrentIndex] > pArray[CurrentIndex + 1])
			{
				TempValue = pArray[CurrentIndex];
				pArray[CurrentIndex] = pArray[CurrentIndex + 1];
				pArray[CurrentIndex + 1] = TempValue;
				IsEndSorting = false;
			}
		}
	}
}