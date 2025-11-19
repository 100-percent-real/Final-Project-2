/*
TeamName.txt
CMPR 131 - Fall 2025
November 23, 2025
Final Project #2
Collaboration:
Dobritsa Alexey, *Eli Christiansen, Kevin Mabry, Ethan Hoang
 */
#pragma once

#ifndef HELPERARRAY_H
#define HELPERARRAY_H
#include <vector>
#include <string>
using namespace std;

class PrintedArray
{
public:
	
	PrintedArray(int x)
	{
		arr.reserve(x);
	}
	bool has(string x)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			if (x == arr[i])
			{
				return true;
			}
		}
		return false;
	}
	vector<string> getArr()
	{
		return arr;
	}
	void assignAt(string name)
	{
		arr[noe] = name;
	}
private:
	int noe;
	vector<string> arr;

};









#endif HELPERARRAY_H
