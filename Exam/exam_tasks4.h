#pragma once
#include "cmath"

struct Point
{
	int x;
	int y;
};
int Abs(int num)
{
	if (num < 0)
		num *= -1;
	return num;
}
int Side(const Point& a, const Point& b)
{
	int x = Abs(a.x - b.x);
	int y = Abs(a.y - b.y);

	if (a.x == b.x)
		return y;
	if (a.y == b.y)
		return x;

	return sqrt(x * x + y * y);
}
bool CheckRectangular(const Point& a, const Point& b, const Point& c)
{
	int x = Side(a, b);
	int y = Side(b, c);
	int z = Side(a, c);

	return (x * x + y * y == z * z) || (z * z + y * y == x * x) || (x * x + z * z == y * y);
}

int D(int a, int b, int c)
{
	return (b * b) - (4 * a * c);
}

double Solve(const char* const str)// a*x^2+b*x+c=0
{
	int a = 0;
	int b = 0;
	int c = 0;

	if (str[0] == '-')
	{
		a = ((int)str[1] - '0') * (-1);

		if (str[6] == '-')
			b = ((int)str[7] - '0') * (-1);
		else
			b = (int)str[7] - '0';

		if (str[10] == '-')
			c = ((int)str[11] - '0') * (-1);
		else
			c = (int)str[10] - '0';
	}
	else
	{
		a = (int)str[0] - '0';

		if (str[5] == '-')
			b = ((int)str[6] - '0') * (-1);
		else
			b = (int)str[6] - '0';

		if (str[9] == '-')
			c = ((int)str[10] - '0') * (-1);
		else
			c = (int)str[10] - '0';
	}

	double x1 = 0;
	double x2 = 0;

	if (a > 0 && b > 0 && c > 0)
		return 0;//no solution

	int d = D(a, b, c);

	if (d > 0)
	{
		x1 = (-b + sqrt(d) / (2 * a));
		x2 = (-b - sqrt(d) / (2 * a));

		if (x1 > x2)
			return x1;
		else 
			return x2;
	}
	else if (d == 0)
	{
		return (-b) / (2 * a);
	}
	else
		return 0;//no solution
}

int* Extract(const int num)
{
	int number = num;
	if (number < 0)
		number *= -1;

	int digitCount[10] = { 0,0,0,0,0,0,0,0,0 };

	while (number != 0)
	{
		int digit = number % 10;
		digitCount[digit] = digitCount[digit] + 1;
		number /= 10;
	}

	int max = 0;
	int maxSize = 1;
	for (int i = 0; i < 10; ++i)
	{
		if (digitCount[i] > max)
		{
			max = digitCount[i];
			maxSize = 1;
		} 
		else if (digitCount[i] == max)
		{
			++maxSize;
		}
	}

	int index = 0;
	int* arr = new int[maxSize + 1];
	for (int i = 0; i < 10; ++i)
	{
		if (digitCount[i] == max)
		{
			arr[index] = i;
			++index;
		}
	}
	arr[index] = -1;

	return arr;
}