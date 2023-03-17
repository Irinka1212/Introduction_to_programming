#include <iostream>
#include "Birthday.h"

int main()
{
	unsigned int birthdays;
	unsigned int laptopPrice;
	unsigned int toyPrice;
	std::cin >> birthdays >> laptopPrice >> toyPrice;

	unsigned int money;
	unsigned int half = (birthdays / 2);
	int bonusOddBirthday = birthdays % 2;
	money = CalculateMoneyFromToys(toyPrice, (half+bonusOddBirthday)) + CalculateMoneyInCash(half);

	std::cout << (money >= laptopPrice ? "yes" : "no") << '\n' << Abs(money - laptopPrice) << '\n';

	system("pause");

	return 0;
}