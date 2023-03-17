#include <iostream>
#include "MaxProfit.h"

int main()
{
	//int days = 8;
	//double prices[8] = { 1, 2, 3, 4, 3, 2, 1, 5 };
	//int days = 5;
	//double prices[5] = { 15, 14.5, 10, 7.45, 5 };

	int n = 0;
	std::cin >> n;
	if (n < 3 || n > 365)
		std::cout << "invalid n\n";
	else
	{
		double* prices = new double[n];
		for (int i = 0; i < n; ++i)
		{
			std::cin >> prices[i];
			if (prices[i] < 0.1 || prices[i] >  100)
			{
				std::cout << "invalid prices\n";
				break;
			}
		}
		std::cout << MaxProfit(n, prices);

		delete[] prices;
	}
	return 0;
}