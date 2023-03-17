#include <iostream>
#include "Sequence.h"

int main()
{
	int n = 0;
	std::cin >> n;

	if (n < 3 || n > 1000)
	{
		return -1;
	}

	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		std::cin >> arr[i];
	}

	int result = Sequence(arr, n);
	if (result == 0)
		return -1;
	std::cout << result << '\n';

	delete[] arr;

 	std::system("pause");

	return 0;
}