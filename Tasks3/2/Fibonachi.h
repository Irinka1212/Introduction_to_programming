#pragma once
#include <iostream>
#include <math.h>

bool isPerfectSquare(long long num)
{
	int s = sqrt(num);
	return (s * s == num);
}

bool isFibonacci(long long n)
{
	if (n < 0)
	{
		return false;
	}
	else
	{
		return isPerfectSquare(5 * n * n + 4) ||
			isPerfectSquare(5 * n * n - 4);
	}
}

void SortArray(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size + 1; ++j)
		{
			if (arr[i] > arr[j])
			{
				int swap = arr[i];
				arr[i] = arr[j];
				arr[j] = swap;
			}
		}
	}

	for (int k = 0; k < size; ++k)
	{
		for (int i = 0; i < size; ++i)
		{
			if (arr[i] == arr[i + 1])
			{
				for (int j = i; j < size; ++j)
					arr[j] = arr[j + 1];
				--size;
			}
		}
	}

	for (int i = 0; i < size + 1; ++i)
	{
		std::cout << arr[i] << " ";
	}

}

void F(int arr[], int size)
{
	if (!arr)
		return;

	int newSize = size + 1;
	int* newArr = new int[newSize];
	for (int i = 0; i < size; ++i)
	{
		for (int j = i; j < newSize; ++j)
		{
			int num = arr[i];
			if (isFibonacci(num))
			{
				newArr[j] = num;
			}
			else
			{
				--j;
				--newSize;
				break;
			}
		}
	}

	SortArray(newArr, newSize);
}