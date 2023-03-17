#pragma once

bool isPolindrom(int num)
{
	int originalNum = num;
	int reverseNum = 0;
	int digit = 0;
	while (num > 0)
	{
		digit = num % 10;
		reverseNum *= 10;
		reverseNum += digit;
		num /= 10;
	}

	return (originalNum == reverseNum);
}

bool isPolindrom(const int* arr, int begin, int end)
{
	while (begin < end)
	{
		if (arr[begin] != arr[end])
			return false;
		++begin;
		--end;
	}

	return true;
}
int Sequence(const int* arr, int n)
{
	int counter = 0;
	int begin = 0;
	int end = 2;
	while (begin + 2 < n)
	{
		if (isPolindrom(arr, begin, end))
			++counter;
		++end;

		if (end == n)
		{
			++begin;
			end = begin + 2;
		}
	}
	return counter;
}