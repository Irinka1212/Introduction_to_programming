#pragma once
#include <iostream>

bool IsWhitespace(const char c);
bool IsFactorialSign(const char c);
bool IsNumber(const char c);
bool IsOperand(const char c);
bool IsValid(const char c);
void PrintInvalidMessage();
int Factorial(int num);
int ExtractNumber(const char expression[], int begin, int end);
bool IsValidExpression(const char expression[]);
int performOperation(const char operation, const int first, const int second);
void EvaluateExpression(const char expression[]);
void Calculator();