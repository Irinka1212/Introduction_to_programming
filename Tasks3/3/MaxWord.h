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

void MaxWord(char* str)
{
	size_t size = GetSize(str);
	int maxSum = 0;
	int maxWord = 0;
	int index = 0;
	int count = 0;
	for (size_t i = 0; i < size + 1; ++i)
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			if (maxSum > maxWord)
			{
				maxWord = maxSum;
				index = i - count;
			}
			maxSum = 0;
			count = 0;
		}
		else if (str[i] == '\0')
		{
			if (maxSum > maxWord)
			{
				maxWord = maxSum;
				index = i - count;
			}
		}
		else
		{
			maxSum += (int)str[i];
			++count;
		}
	}

	for (size_t j = index; j < size; ++j)
	{
		std::cout << str[j];
		if (str[j] == ' ' || str[j] == '\t')
			break;
	}
}
