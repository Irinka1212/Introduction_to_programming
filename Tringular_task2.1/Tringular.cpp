#include <iostream>
#include "Tringular.h"

int main()
{
	//int n = 8;
	//int arr[8] = { 9, 8, 3, 4, 2, 1, 6, 5 };
	//int n = 5;
	//int arr[5] = { 5, 5, 3, 5, 5 };
	//int n = 6;
	//int arr[6] = { 1,2,3,6,8,7 };

	int n = 0;
	std::cin >> n;
	if (n < 3 || n > 100)
	{
		std::cout << "invalid input\n";
	}
	else
	{
		int* arr = new int[n];
		for (int i = 0; i < n; ++i)
		{
			std::cin >> arr[i];
		}

		std::cout << isTringular(n, arr);
		delete[] arr;
	}
	return 0;
}