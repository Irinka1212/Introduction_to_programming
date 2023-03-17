#pragma once
#include <iostream>

using namespace std;

void Swap(int& a, int& b)//1.1
{
	int swapper = a;
	a = b;
	b = swapper;
}
int* SortNewArray(int* first, int* second, int size1, int size2) 
{
	int size = size1 + size2;
	int* newArr = new int[size + 1];
	for (int i = 0; i < size; ++i)
	{
		if (i < size1)
		{
			newArr[i] = first[i];
		}
		else
		{
			newArr[i] = second[i - size1];
		}
	}
	for (int j = 0; j < size - 1; ++j)
	{
		for (int l = 0; l < size - 1 - j; ++l)
		{
			if (newArr[l] > newArr[l + 1]) Swap(newArr[l], newArr[l + 1]);
		}
	}
	return newArr;
}

struct dot//1.2
{
	double x, y;
};

struct line { dot A; dot B; };

double Distance(line One, line Two)
{
	if (One.A.x != One.B.x && One.A.y != One.B.y) return -1;
	if (Two.A.x != Two.B.x && Two.A.y != Two.B.y) return -1;

	double distance = 0;

	if (One.A.x == One.B.x)
	{
		if (One.A.y > Two.A.y)
		{
			distance = Two.A.y - One.A.y;
		}
		else if (One.A.y < Two.A.y)
		{
			distance = One.A.y - Two.A.y;
		}
	}

	if (One.A.y == One.B.y)
	{
		if (One.A.x > Two.A.x)
		{
			distance = Two.A.x - One.A.x;
		}
		else if (One.A.x < Two.A.x)
		{
			distance = One.A.x - Two.A.x;
		}
	}

	if (distance <= 0) return -1;
	else return distance;
}


void FullRectangle(int N, int M, char symbol)//1.3 
{
	if (N < 0 || N>25 || M < 0 || M>80) 
	{
		cout << "Invalid input.";
		return;
	}
	int spaceM = (80 - M) / 2;
	int spaceN = (25 - N) / 2;
	char** rectangle = new char*[N];
	for (int i = 0; i < N; ++i)
	{
		rectangle[i] = new char[M];
	}
	//cout << spaceN <<endl;
	for (int i = 0; i < spaceN; ++i) cout << '\n';
	for (int row = 0; row < N; ++row)
	{
		//cout << spaceM;
		for (int i = 0; i < spaceM; ++i) cout << ' ';
		for (int col = 0; col < M; ++col)
		{
			rectangle[row][col] = symbol;
			cout << rectangle[row][col];
		}
		//cout<<spaceM;
		for (int i = 0; i < spaceM; ++i) cout << ' ';
		cout << endl;
	}
	//cout << spaceN <<endl;
	for (int i = 0; i < spaceN; ++i) cout << '\n';
}

int Sum(double** matrix, int N)//1.4
{
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (j > i) sum += matrix[i][j];
		}
	}
	return sum;
}

void Swap2(double& a, double& b)//1.5
{
	double swapper = a;
	a = b;
	b = swapper;
}
double** TransMatrix(double** matrix, int N)
{
	for (int i = 0; i < N; ++i)
	{

		for (int j = 0; j < N; ++j)
		{
			if (j > i) Swap2(matrix[i][j], matrix[j][i]);
		}
	}
	return matrix;
}

double Abs(const double a)//2.1
{
	return a >= 0 ? a : -a;
}

double Formula(const double a, const double xOld)
{
	return 0.5*(xOld + a / xOld);
}

double Sqrt_a(const double a, const double eps)
{
	if (a <= 0)
	{
		return 0;
	}

	double xOld = a;
	double xNew = Formula(a, xOld);
	while (Abs(xOld - xNew) >= eps)
	{
		xOld = xNew;
		xNew = Formula(a, xOld);
	}
	return xNew;
}

void Revert(char a[])//2.2
{
	int arrSize = 0;
	for (int i = 0; a[i] != '\0'; ++i)
	{
		++arrSize;
	}
	for (int i = 0; i < arrSize; ++i)
	{
		if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A';
		else if (a[i] >= 'A' && a[i] <= 'Z')
		{
			a[i] += 'a' - 'A';
		}

		cout << a[i];
	}
}

bool CheckDate(char date[])//2.3 
{
	if (date == nullptr) 
	{
		cout << "invalid" << endl;
		return 0;
	}
	int counter = 0;
	while (date[counter] != '\0') 
	{
		counter++;
	}
	int month = (date[3] - '0') * 10 + (date[4] - '0');
	int day = (date[0] - '0') * 10 + (date[1] - '0');
	
	if (counter != 5 || date[2] != '.' || month < 1 || month>12 || day < 1 || day>31) return false;
	if ((month == 2 && day > 29) || ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))) return false;

	return true;
}

int LenNumber(int a)//task2.4
{ 
	int br = 0;
	while (a) 
	{ 
		a /= 10;
		++br;
	} 
	return br;
} 
int DigitPos(long num, int k) 
{ 
	int len = LenNumber(num); 	
	if (k > len) return -1; 	
	long* arr = new long[len];
	for (int i = len; i >= 0; --i) 
	{ 
		arr[i] = num % 10;
		num /= 10;
	} 	
	if (len >= k) 
	{ 
		int result = arr[k];
		return result;
	} 
} 
int StrLen(char arr[])//2.5
{
	int i = 0;
	while (arr[i] != '\0') ++i;
	return i;
}
bool DoExist(char* symbols, char* word)
{
	int len = StrLen(symbols);
	int lenWord = StrLen(word);
	if (len < lenWord) return 0;
	for (int i = 0; i < len; ++i)
	{
		if (symbols[i] == word[0])
		{
			if (lenWord == 1) return 1;
			for (int j = 1; (word[j] == symbols[j + i]); ++j)
			{
				if (j == lenWord - 1) return 1;
			}
		}
	}
	return 0;
}
int GetSize(char* arr)//3.1
{
	int index = 0;
	while (arr[index] != '\0')
	{
		++index;
	}
	return index;
}
int GetNumLength(int number) 
{
	int size = 0;
	do
	{
		number /= 10;
		++size;
	} 
	while (number != 0);

	return size;
}
void SwapByIndex(int* arr, int size, int leftIndex, int rightIndex) 
{
	if (arr != nullptr && leftIndex < rightIndex)
	{
		if (leftIndex >= 0 && leftIndex < size && rightIndex >= 0 && rightIndex < size) 
			Swap(arr[rightIndex], arr[leftIndex]);
	}
}

long GetWords(char str[])//3.2
{
	int size = StrLen(str);
	int words = 1;
	for (int i = 0; i < size; ++i)
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			++words;
		}
	}

	return words;
}

int SumDigits(int arr[],int len)//3.3
{
	int sum = 0;
	for (int i = 0; i < len; ++i)
	{
		sum += arr[i];
	}
	return sum;
}

/*int** matrixMulti(int** matrix1, int m1, int n1, int** matrix2, int m2, int n2)
{
	int row = 0;
	int** result;
	if (n1!= m2) 
		return 0;  
	else
	{
		for (int i = 0; i = n2; ++i)
		{
			for (int j,s = 0; j = m2, s = m2; ++j, ++s)
			{
				result += matrix1[j][i] * matrix2[i][s];
			}
		}
	}
	return result; 
}*/

