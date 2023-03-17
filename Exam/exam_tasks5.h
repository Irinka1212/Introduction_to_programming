#pragma once
bool isDigit(int num)
{
	return num >= 0 && num <= 9;
}
bool CheckDate(char date[])//dd.mm
{
	if (date[3] != '.')
		return false;
	int month = 0;
	int digit = (int)(date[4] - '0');
	if (!isDigit(digit))
		return false;
	month += digit;

	digit = (int)(date[3] - '0');
	if (!isDigit(digit))
		return false;
	month += 10 * digit;

	if (month < 1 || month >12)
		return false;

	int day = 0;
	digit = (int)(date[1] - '0');
	if (!isDigit(digit))
		return false;
	day += digit;

	digit = (int)(date[0] - '0');
	if (!isDigit(digit))
		return false;
	day += 10 * digit;

	if (day < 1 || day>31)
		return false;

	if (month == 2)
		return day >=1 && day <=28;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return day >= 1 && day <= 31;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return day >= 1 && day <= 30;

	return true;
}

int** transportMatrix(const int n, int** matrix)
{
	int size = n;
	int** newMatrix = new int*[size];
	for (int i = 0; i < size; ++i)
	{
		newMatrix[i] = new int[size];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			newMatrix[i][j] = matrix[j][i];
		}
	}

	return newMatrix;
}