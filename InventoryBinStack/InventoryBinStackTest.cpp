// Written by Zack Rosales
// Advanced C++ Programming ITSE 2431 1001
// Program from page 1099, #12

#include <fstream> // for using files
#include <iostream> // for cout and cin
#include <iomanip> // for formatting
#include <cstdlib> // for rand and srand
#include <vector> // for vectors
#include <cctype> // for character functions
#include <cstring> // for C-strings
#include <ctime> // for using time/date functions
#include <algorithm> // for STL algorithms
#include "conio.h" 
#include "Inventory.h"
#include "DynamicStack.h"
using namespace std;

// global constants
static const int EXIT = 0,
				 ADD = 1,
				 REMOVE = 2;

// method prototypes
int menu(int);
void addItem(DynamicStack<Inventory>&);
void removeItem(DynamicStack<Inventory>&);
void displayRemaining(DynamicStack<Inventory>&);

int main() // main method start
{
	// local variable
	int choice;

	// creating stack
	DynamicStack<Inventory> stack;

	do
	{
		choice = menu(stack.getSize());
		if (choice == ADD)
		{
			addItem(stack);
		} // end if
		else if (choice == REMOVE)
		{
			removeItem(stack);
		} // end else if
	} while (choice != EXIT);

	displayRemaining(stack);

	cout << "Have a good day.";
	_getch();
	return 0;
} // main method end

// menu method displays menu options and returns user selection
int menu(int size) // menu method start
{
	// local variable
	int choice,
		max;

	if (size == 0)
	{
		cout << "Stack is empty. Please add an inventory item to enable additional option.\n\n";
		max = 1;
	} // end if

	cout << "Please choose an operation to perform:\n";
	cout << "1. Add a new item\n";

	if (size != 0)
	{
		cout << "2. Remove an item\n";
		max = 2;
	} // end if

	cout << "0. Exit the program\n";
	cout << "Enter selection: ";
	cin >> choice;

	// input validation
	while (choice < 0 || choice > max)
	{
		cout << "You did not enter a valid selection. Please try again.\n";
		cout << "Enter selection (0 - " << max << "): ";
		cin >> choice;
	} // end while

	cout << "\n";

	return choice;
} // menu method end

// addItem method gets info from user and adds Inventory item to stack
void addItem(DynamicStack<Inventory> &stack) // addItem method start
{
	// local variables
	int serial,
		lot;
	string date;
	Inventory item;

	// getting input from user
	cout << "Enter the item serial number: ";
	cin >> serial;
	cout << "Enter the lot number: ";
	cin >> lot;
	cout << "Enter the date of manufacture: ";
	cin >> date;

	item.setSerial(serial);
	item.setLot(lot);
	item.setDate(date);

	stack.push(item);

	cout << "\nItem added to stack.\n";
} // addItem method end

// removeItem method removes item from stack
void removeItem(DynamicStack<Inventory> &stack) // removeItem method start
{
	// local variable
	char choice;

	Inventory item = stack.pop();

	// displaying top stack item
	cout << "The following item is being removed:\n\n";
	cout << "Serial Number: " << item.getSerial() << "\n";
	cout << "Lot Number: " << item.getLot() << "\n";
	cout << "Manufacture Date: " << item.getDate() << "\n\n";
	cout << "Are you sure you want to remove this item? (\'Y\' or \'N\'): ";
	cin >> choice;

	// input validation
	while (!(toupper(choice) == 'Y' || toupper(choice) == 'N'))
	{
		cout << "You did not enter a valid option. Please try again.\n";
		cout << "Are you sure you want to remove this item? (\'Y\' or \'N\'): ";
		cin >> choice;
	} // end while

	if (toupper(choice) == 'N')
	{
		stack.push(item);
	} // end if
	else
	{
		cout << "Item has been removed.\n\n";
	} // end else
} // removeItem method end

// displayRemaining method displays any remaining items on the stack before exiting program
void displayRemaining(DynamicStack<Inventory> &stack) // displayRemaining method start
{
	if (stack.getSize() > 0)
	{
		cout << "Removing ramining items from stack:\n\n";
		while (stack.getSize() > 0)
		{
			Inventory item(stack.pop());
			cout << "Serial Number: " << item.getSerial() << "\n";
			cout << "Lot Number: " << item.getLot() << "\n";
			cout << "Manufacture Date: " << item.getDate() << "\n\n";
		} // end while
		cout << "All items removed. Stack is now empty.\n\n";
	} // end if
} // displayRemaining method end