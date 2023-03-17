#include <iostream>
#include <cstring>
#include "Utils.h"

bool IsWhitespace(const char c)
{
	return (c == ' ');
}

bool IsFactorialSign(const char c)
{
	return (c == '!');
}

bool IsNumber(const char c)
{
	return (c >= '0' && c <= '9');
}

bool IsOperand(const char c)
{
	return (c == '+' || c == '-'|| c == '/' || c == '*');
}

bool IsValid(const char c)
{
	return (IsNumber(c) || IsOperand(c) || IsWhitespace(c) || IsFactorialSign(c));
}

void PrintInvalidMessage()
{
	std::cout << "The expression is invalid\n";
}

int Factorial(int num)
{
	int fact = 1;
	while (num > 0)
	{
		fact *= num;
		--num;
	}
	return fact;
}

int ExtractNumber(const char expression[], int begin, int end)
{
	int num = 0;
	int multiplier = 1;
	while (end >= begin)
	{
		num += (expression[end] - '0') * multiplier;
		--end;
		multiplier *= 10;
	}
	return num;
}

bool IsValidExpression(const char expression[])
{
	if (!IsNumber(expression[0]))
	{
		return false;
	}

	bool isLastOp = false;
	size_t size = std::strlen(expression);
	for (size_t i = 0; i < (size - 1); ++i)
	{
		char c = expression[i];
		char next = expression[i+1];
		if (!IsValid(c) || // ex: "e" ; "/t" ; "abc"
			IsNumber(c) && (IsOperand(next)) || // ex: "5+"
			IsFactorialSign(c) && !IsWhitespace(next) || // ex: "5!4" ; "5!+" ; "5!!"
			IsOperand(c) && !IsWhitespace(next) || // ex: "5 /3" ; "5 +!" ; "5 ++"
			IsWhitespace(c) && (IsWhitespace(next) || IsFactorialSign(next))) // ex: "5 !" ; "5  "
		{
			return false;
		}
		if (IsWhitespace(c) && IsOperand(next))
		{
			if (isLastOp) // ex: "+ +"
			{
				return false;
			}
			isLastOp = true;
		}
		else if (IsWhitespace(c) && IsNumber(next))
		{
			if (!isLastOp) // ex: "5 5"
			{
				return false;
			}
			isLastOp = false;
		}
	}
	return true;
}

int performOperation(const char operation, const int first, const int second)
{
	switch (operation)
	{
		case '+': return first + second;
		case '-': return first - second;
		case '*': return first * second;
		case '/': return first / second;
	}
	return 0;
}

void EvaluateExpression(const char expression[])
{
	if (!IsValidExpression(expression))
	{
		PrintInvalidMessage();
		return;
	}

	int result = 0;

	char operand = '#';
	int beginNumber = 0;
	int endNumber = 0;
	size_t size = std::strlen(expression);
	for (size_t i = 0; i < size; ++i)
	{
		char current = expression[i];
		bool isLast = (endNumber == (size - 1));
		if (IsWhitespace(current) || IsFactorialSign(current) || isLast)
		{
			if (isLast && !IsFactorialSign(current))
			{
				++endNumber;
			}
			if ((beginNumber == endNumber - 1) && (IsOperand(expression[beginNumber])))
			{
				operand = expression[beginNumber];
			}
			else
			{
				int num = ExtractNumber(expression, beginNumber, endNumber - 1);
				if (IsFactorialSign(current))
				{
					num = Factorial(num);
					if (!isLast)
					{
						++endNumber;
						++i;
					}
				}
				if (operand == '/' && (num == 0))
				{
					std::cout << "Division by ZERO\n";
					return;
				}
				result = (beginNumber == 0) ? num : performOperation(operand, result, num);
			}
			beginNumber = endNumber+1;
		}
		++endNumber;
	}

	std::cout << result << '\n';
}

void Calculator()
{
	std::cout << "Enter an expression to calculate or exit?\n";
	const int bufferSize = 100;
	char answer[bufferSize] = {};
	std::cin.getline(answer, bufferSize);

	if (std::strcmp(answer, "exit") == 0)
	{
		exit(0);
	}

	if (std::strcmp(answer, "enter") == 0)
	{
		char expression[bufferSize] = {};
		std::cin.getline(expression, bufferSize);

		EvaluateExpression(expression);
	}
	else
	{
		std::cout << "Invalid answer\n";
	}
}