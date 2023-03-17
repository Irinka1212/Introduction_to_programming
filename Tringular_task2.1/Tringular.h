#pragma once

int Abs(int num)
{
	if (num < 0)
		num *= -1;
	return num;
}

bool isTringular(int n, const int* arr)
{
	for (int i = 1; i < n; ++i)
	{
		if (Abs(arr[i - 1] - arr[i]) != Abs(arr[n - i] - arr[n - i - 1]))
			return false;
	}
	return true;
}
