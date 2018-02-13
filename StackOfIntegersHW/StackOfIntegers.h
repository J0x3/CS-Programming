#pragma once
class StackOfIntegers
{
public:
	StackOfIntegers();
	bool isEmpty() const;
	int peek() const;
	void push(int value);
	int pop();
	int getSize() const;
	~StackOfIntegers();
	void clnStk();
private:
	int elements[800];
	int size;
};