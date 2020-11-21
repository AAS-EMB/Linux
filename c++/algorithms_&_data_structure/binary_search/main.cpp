#include <iostream>
#include <algorithm>

void SortingChoice(int *pArray, unsigned int ArraySize);
int* BinarySearch_1(int *pArray, unsigned int ArraySize, int SearchValue);
int BinarySearch_2(int *pArray, unsigned int ArraySize, int SearchValue);

int main(int argc, char* argv[])
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
	int SearchValue;
	std::cout << "\r\nEnter the desired value: ";
	std::cin >> SearchValue;
	int *SearchMemoryAddress = BinarySearch_1(Array, ArraySize, SearchValue);
	if(SearchMemoryAddress != nullptr) {
		std::cout << "BinarySearch_1: for number " << SearchValue << " memory address " << SearchMemoryAddress << std::endl;
	} else {
		std::cout << "BinarySearch_1: " << SearchValue << " was not found in the list" << std::endl;
	}
	int SearchIndex = BinarySearch_2(Array, ArraySize, SearchValue);
	if(SearchIndex != -1) {
		std::cout << "BinarySearch_2: for number " << SearchValue << " index " << SearchIndex << std::endl;
	} else {
		std::cout << "BinarySearch_2: " << SearchValue << " was not found in the list" << std::endl;
	}
	delete [] Array;
	return 0;
}

/*!
 * @brief The sort method of the choice
 * 
 * @param pArray      Pointer to the object
 * @param ArraySize   Size object
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

/*!
 * @brief The binary search method 1
 * 
 * @param pArray      Pointer to the object
 * @param ArraySize   Size object
 * @param SearchValue Search value in massive
 * @return Pointer to the search object
 */
int* BinarySearch_1(int *pArray, unsigned int ArraySize, int SearchValue)
{
	auto FirstIndex = pArray, LastIndex = pArray + ArraySize - 1;
	while(FirstIndex <= LastIndex) {
		auto AverageIndex = FirstIndex + (LastIndex - FirstIndex) / 2;
		if(*AverageIndex == SearchValue) return AverageIndex;
		*AverageIndex > SearchValue ? LastIndex = AverageIndex - 1 : FirstIndex = AverageIndex + 1;
	}
	return nullptr;
}

/*!
 * @brief The binary search method 2
 * 
 * @param pArray      Pointer to the object
 * @param ArraySize   Size object
 * @param SearchValue Search value in massive
 * @return Index to the search object
 */
int BinarySearch_2(int *pArray, unsigned int ArraySize, int SearchValue)
{
	int FirstIndex = 0, LastIndex = ArraySize - 1;
	while(FirstIndex <= LastIndex) {
		auto AverageIndex = (FirstIndex + LastIndex) / 2;
		if(pArray[AverageIndex] == SearchValue) return AverageIndex;
		pArray[AverageIndex] > SearchValue ? LastIndex = AverageIndex - 1 : FirstIndex = AverageIndex + 1;
	}
	return -1;
}