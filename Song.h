/*
TeamName.txt
CMPR 131 - Fall 2025
November 23, 2025
Final Project #2
Collaboration:
Dobritsa Alexey, *Eli Christiansen, Kevin Mabry, Ethan Hoang
 */
#pragma once

#include<iostream>
#include<iomanip>
#include<string>
#include<list>
using namespace std;

struct Song
{
	string artist;
	string songName;
	string genre;
	double duration = 0.0;
	int skipCounter = 0;
};
