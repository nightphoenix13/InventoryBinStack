// Written by Zack Rosales
// Advanced C++ Programming ITSE 2431 1001
// Program from page 1099, #12
// Class definition for DynamicStack

#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

using namespace std;

template <class T>
class DynamicStack
{
private:
	struct StackNode
	{
		T value;
		StackNode *next;
	}; // struct end

	StackNode *top;
	int size;

public:
	// exception class
	class EmptyStack
	{};

	// constructor
	DynamicStack()
	{
		top = NULL;
		size = 0;
	} // constructor end

	// destructor
	~DynamicStack()
	{
		StackNode *nodePtr,
				  *nextNode;

		nodePtr = top;

		while (nodePtr != NULL)
		{
			nextNode = nodePtr->next;
			delete nodePtr;
			nodePtr = nextNode;
		} // end while
	} // destructor end

	// push method adds value onto the stack
	void push(T val) // push method start
	{
		StackNode *newNode;

		newNode = new StackNode;
		newNode->value = val;

		if (getSize() == 0)
		{
			top = newNode;
			newNode->next = NULL;
		} // end if
		else
		{
			newNode->next = top;
			top = newNode;
		} // end else

		size++; // increases size by 1
	} // push method end

	// pop method removes value from stack and copies it to value passed as argument
	T pop() // pop method start
	{
		T val;

		StackNode *temp;

		if (getSize() == 0)
		{
			throw EmptyStack();
		} // end if
		else
		{
			val = top->value;
			temp = top->next;
			delete top;
			top = temp;

			size--; // decreases size by 1
		} // end else

		return val;
	} // pop method end

	// getSize method returns the stack size
	int getSize() // getSize method start
	{
		return size;
	} // getSize method end
};

#endif