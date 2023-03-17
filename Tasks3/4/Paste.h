#pragma once
#include <iostream>

size_t GetSize(char* str)
{
	if (!str)
		return NULL;

	size_t i = 0;
	while (str[i] != '\0')
	{
		++i;
	}

	return i;
}

char* F(char* first, char* second, int n)
{
	size_t size = GetSize(first) + GetSize(second);
	char* newStr = new char[size + 1];
	for (size_t i = 0; i < GetSize(first); ++i)
	{
		if (i == n)
		{
			for (size_t j = 0; j < GetSize(second); ++j)
			{
				newStr[n] = second[j];
				++n;
			}
			for (size_t k = i; k < GetSize(first); ++k)
			{
				newStr[n] = first[k];
				++n;
			}
			break;
		}
		else
			newStr[i] = first[i];
	}
	newStr[size] = '\0';

	return newStr;
}