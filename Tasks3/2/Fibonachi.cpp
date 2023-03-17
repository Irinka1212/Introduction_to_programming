#include <iostream>
#include "Fibonachi.hpp"

int main()
{
	int arr[6] = { 3, 11, 5, 1, 7, 12 };
    int secondArr[6] = { 3, 0, 0, 1, 12, 8 };
	int thirdArr[12] = { 233, 6765, 4, 13, 8, 13, 9, 21, 21, -1, 10, 233 };

	F(arr, 6);
	std::cout << '\n';
	F(secondArr, 6);
	std::cout<< '\n';
	F(thirdArr, 12);
	std::cout << '\n';

	std::system("pause");

	return 0;
}