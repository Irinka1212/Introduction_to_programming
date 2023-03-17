#pragma once

int* CheckNums(long num1, long num2)
{
	bool numCheck[10] = { 0,0,0,0,0,0,0,0,0};
	long originalNum1 = num1;

	while (num2 > 0)
	{
		int digit1 = num2 % 10;
		while (num1 > 0)
		{
			int digit2 = num1 % 10;
			if (digit1 == digit2)
				numCheck[digit1] = 1;
			num1 /= 10;
		}
		num1 = originalNum1;
		num2 /= 10;
	}

	int count = 0;
	int* result = new int[10];
	for (int i = 0; i < 10; ++i)
	{
		if (numCheck[i])
		{
			result[count] = i;
			++count;
		}
	}
	
	return result;
}

int GetSize(char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return i;
}

bool doExist(char* symbols, char* word)
{
	if (symbols && word)
	{
		for (int i = GetSize(symbols)-1; i >= GetSize(word)-1; --i)
		{
			int begin = i;
			bool result = true;
			for (int j = 0; j < GetSize(word); ++j)
			{
				if (word[j] != symbols[begin-j])
					result = false;
			}
			if (result)
				return true;
		}
	}
	return false;
}
int reverseNum(int num)
{
	if (num < 10)
		return num;

	int newNum = 0;
	while (num > 0)
	{
		int digit = num % 10;
		newNum *= 10;
		newNum += digit;
		num /= 10;
	}
	return newNum;
}
char* Encode(char str[])
{
	char* newStr = new char[1000];
	int j = 0;
	for (int i = 0; i < GetSize(str); ++i)
	{
		int ascii = ((int)str[i];
		ascii = reverseNum(ascii);

		while (ascii > 0)
		{
			int digit = ascii % 10;
			newStr[j] = (char)(digit + (int)'0');
			ascii /= 10;
			++j;
		}
		if (i + 1 == GetSize(str))
			newStr[j] = '\0';
		else
		{
			newStr[j] = ' ';
			++j;
		}
	}
	return newStr;
}