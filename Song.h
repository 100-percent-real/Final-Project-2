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
	double duration;
	int skipCounter;
	Song* next;
};