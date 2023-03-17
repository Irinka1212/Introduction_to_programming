#pragma once
double MaxProfit(int n, const double* arr)
{
	int index = 0;
	double profit = 0;
	double maxProfit = 0;
	int res = arr[0];
	for (int i = 1; i < n; ++i)
	{
		if (res > arr[i])
		{
			res = arr[i];
			index = i;
		}

		if ((index == n - 1) && (maxProfit == 0))
			return 0;

		if ((arr[i] > arr[i + 1]))
		{
			profit = arr[i] - arr[index];
			index = i + 1;
			maxProfit += profit;
		}
	}
	return maxProfit;
}
