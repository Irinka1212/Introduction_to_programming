#pragma once

void Revert(long& num)
{
	bool isNegative = num < 0;
	if (isNegative)
		num *= -1;
	int copyNum = num;
	num = 0;
	while (copyNum > 0)
	{
		int digit = copyNum % 10;
		num *= 10;
		num += digit;
		copyNum /= 10;
	}
	if (isNegative)
		num *= -1;
}
long ReverseNum(long num)
{
	long reverseNum = 0;
	while (num > 0)
	{
		int digit = num % 10;
		reverseNum *= 10;
		reverseNum += digit;
		num /= 10;
	}
	return reverseNum;
}
int Find(long N, int n)
{
	if (n >8 || N < 0)
		return 0;

	long num = 0;
	long biggestNum = 0;
	int count = n;
	N = ReverseNum(N);
	while (N > 0)
	{
		long newNum = N;
		if (num > biggestNum)
		{
			biggestNum = num;
			num = 0;
		}

		while (n > 0 && newNum>  0)
		{
			int digit = newNum % 10;
			num *= 10;
			num += digit;
			--n;
			newNum /= 10;
		}
		n = count;
		N /= 10;
	}

	return biggestNum;
}
int GetSize(char str[])
{
	if (!str)
		return 0;

	int i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return i;
}

bool isDelimeter(char c)
{
	return c == ' ' || c == '\t';
}

int GetWord(char str[])
{
	int index = 0;
	int word = 0;
	int count = 0;
	for (int i = 0; i < GetSize(str); ++i)
	{
		if (isDelimeter(str[i]))
		{
			if (count > word)
			{
				word = count;
				index = i - count;
			}
			count = 0;
		}
		else if (isDelimeter(str[i]) && str[i + 1] == '\0')
		{
			if (count > word)
			{
				word = count;
				index = i - count;
			}
		}
		else
			++count;
			
	}
	return index;
}