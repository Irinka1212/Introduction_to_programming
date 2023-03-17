#pragma once
#include <iostream>

bool isLeapYear(int year)
{
	if (year % 100 == 0)
	{
		return (year % 400 == 0);
	}
	else
		return (year % 4 == 0);
}
void LeapYear(int y, int m)
{
	if ((y < 0) || (y > 2100) || (m < 0) || (m > 1000))
		std::cout << "invalid input\n";

	int count = 0;
	for (int i = y + 1; count < m; ++i)
	{
		if (isLeapYear(i))
		{
			std::cout << i << '\n';
			++count;
		}
	}
}
