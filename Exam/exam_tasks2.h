#pragma once
int GetSize(char str[])
{
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
long GetWord(char str[])
{
	if (!str)
		return -1;

	long count = 0;
	long word = 0;
	for (int i = 0; i < GetSize(str); ++i)
	{
		if (isDelimeter(str[i]) && word !=0)
		{
			++count;
			word = 0;
		}
		else if (str[i+1] == '\0' && word !=0)
		{
			++count;
		}
		++word;
	}
	return count;
}

long convertNumber(long num)
{
	if (num < 10)
		return num;

	long sum = 0;
	while (num > 0)
	{
		int digit = num % 10;
		sum += digit;
		num /= 10;
	}
	return sum;
}
void Revert(char str[])
{
	if (!str)
		return;

	for (int i = 0; i < GetSize(str); ++i)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}

	for (int i = 0; i < GetSize(str); ++i)
	{
		std::cout << str[i];
	}
}