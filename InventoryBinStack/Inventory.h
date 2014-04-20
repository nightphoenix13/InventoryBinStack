// Written by Zack Rosales
// Advanced C++ Programming ITSE 2431 1001
// Program from page 1099, #12
// Inventory class definition file

#ifndef INVENTORY_H
#define INVENTORY_H

#include <string> // for strings
using namespace std;

class Inventory
{
private:
	// class attributes
	int serial,
		lot;
	string date;

	// class set method
	void setClass(int s, int l, string d)
	{
		setSerial(s);
		setLot(l);
		setDate(d);
	} // class set method end
public:
	// constructor
	Inventory(int s = 0, int l = 0, string d = "")
	{
		setClass(s, l, d);
	} // constructor end

	// copy constructor
	Inventory(Inventory &item)
	{
		setClass(item.getSerial(), item.getLot(), item.getDate());
	} // copy constructor end

	// set methods
	void setSerial(int s) // serial set method start
	{
		serial = s;
	} // serial set method end

	void setLot(int l) // lot set method start
	{
		lot = l;
	} // lot set method end

	void setDate(string d) // date set method start
	{
		date = d;
	} // date set method end

	// get methods
	int getSerial() // serial get method start
	{
		return serial;
	} // serial get method end

	int getLot() // lot get method start
	{
		return lot;
	} // lot get method end

	string getDate() // date get method start
	{
		return date;
	} // date get method end
};

#endif