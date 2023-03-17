#pragma once

int CalculateMoneyFromToys(int toyPrice, int birthdays)
{
	return toyPrice * birthdays;
}

int CalculateMoneyInCash(int birthdays)
{
	int money = 0;

	int givenCash = 30;

	for (int i = 1; i <= birthdays; ++i)
	{
		money += givenCash - 5;
		givenCash += 30;
	}

	return money;
}

int Abs(int num)
{
	return num * (num < 0 ? -1 : 1);
}
