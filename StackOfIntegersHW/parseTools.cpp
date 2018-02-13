#include <iostream>
#include <cstring>
#include <string>
#include "parseTools.h"
#include "StackOfIntegers.h"

parseTools::parseTools()
{	
}

parseTools::~parseTools()
{
}

StackOfIntegers stack;

int parseTools::getSize() {
	return stack.getSize();
}

void parseTools::cleanStack()
{
	stack.clnStk();
}

void parseTools::parseString(std::string str)
{
	const char symbolTable[6] = { '(', ')', '{', '}', '[', ']' };
	int strLen = str.length();
	for (int i = 0; i < strLen; i++)
	{
		if (str.at(i) == symbolTable[0])	  //0 = '('
		{
			stack.push(1);
		}
		else if (str.at(i) == symbolTable[1]) //1 = ')'
		{	
			stack.pop();
		}
		else if (str.at(i) == symbolTable[2]) //2 = '{'
		{
			stack.push(1);
		}
		else if (str.at(i) == symbolTable[3]) //3 = '}'
		{
			stack.pop();
		}
		else if (str.at(i) == symbolTable[4]) //4 = '['
		{
			stack.push(1);
		}
		else if (str.at(i) == symbolTable[5]) //5 = ']'
		{
			stack.pop();
		}
		else
			continue;
	}
}

void parseTools::checkStack()
{
	if (stack.getSize() > 0)
	{
		std::cout << "Error: Missing 'closing symbol' either ')' '}' or ']'" << std::endl;
	}
	else if (stack.getSize() < 0)
	{
		std::cout << "Error: Missing 'opening symbol' either '(' '{' or '['" << std::endl;
	}
	else if (stack.getSize() == 0)
	{
		std::cout << "Program success: Accepted" << std::endl;
	}
	else std::cout << "!! Unknown Error !!" << std::endl;
}