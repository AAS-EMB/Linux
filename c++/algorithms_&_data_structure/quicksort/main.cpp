
#include <iostream>
#include <vector>

std::vector <int> QuickSort(std::vector <int> &Array);

int main(int argc, char *argv[])
{
	unsigned int ArraySize;

	std::cout << "\r\nSet the size of the array: ";
	std::cin >> ArraySize;
	std::vector <int> Array(ArraySize);
	std::cout << "\r\nEnter the values of the array elements" << std::endl;
	for(auto Iterator = &Array[0]; Iterator != (&Array[0] + ArraySize); Iterator++) {
		std::cin >> *Iterator;
	}
	std::vector <int> SortedArray = QuickSort(Array);
	std::cout << "\r\nSorted array by quick method" << std::endl;
	for(auto now : SortedArray) {
		std::cout << now << " ";
	}
	std::cout << std::endl;
	return 0;
}

/*!
 * @brief The method of quick sort
 * 
 * @param Array    Reference to the object
 */
std::vector <int> QuickSort(std::vector <int> &Array)
{
    if(Array.size() < 2) return Array;

    const auto Pivot = &Array.front() + Array.size() / 2 - 1;
    std::vector <int> Less;
    std::vector <int> More;
    for(auto It = &Array.front(); It <= &Array.back(); It++) {
        if(It == Pivot)   continue;
        if(*It <= *Pivot) Less.push_back(*It);
        else              More.push_back(*It);
    }
    std::vector <int> SortedLess = QuickSort(Less);
    std::vector <int> SortedMore = QuickSort(More);
    SortedLess.push_back(*Pivot);
    SortedLess.insert(SortedLess.end(), SortedMore.begin(), SortedMore.end());

    return SortedLess;
}
