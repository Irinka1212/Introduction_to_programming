#include <iostream>
#include "MaxWord.h"

int main()
{
	//char str[] = "This is a string.";
	//char str[] = "zzzzZzz AAAAAAAAAAAA";

	char str[1000] = {};
	std::cin.getline(str, 1000);

	MaxWord(str);

	std::cout << '\n';

	std::system("pause");

	return 0;
}