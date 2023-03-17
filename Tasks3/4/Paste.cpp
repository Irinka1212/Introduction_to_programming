#include <iostream>
#include "Paste.h"

int main()
{
	char first[1000] = {};
	std::cin.getline(first, 1000);

	char second[1000] = {};
	std::cin.getline(second, 1000);

	int n = 0;
	std::cin >> n;

	if (n < 0)
		std::cout << "invalid n\n";

	char * str = F(first, second, n);
	for (size_t i = 0; i < GetSize(str)+1; ++i)
	{
		std::cout << str[i];
	}
	std::cout << '\n';

	std::system("pause");

	return 0;
}