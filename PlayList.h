/*
TeamName.txt
CMPR 131 - Fall 2025
November 23, 2025
Final Project #2
Collaboration:
Dobritsa Alexey, *Eli Christiansen, Kevin Mabry, Ethan Hoang
 */
#pragma once

#include"Song.h"
#include"HelperArray.h"

class PlayList
{
	friend class PrintedArray;
private:
	list<Song> playList;
	bool maxType;
	// True == Maximum number of skips
	// False == maximum number of songs
public:
	PlayList();
	int getTotalDuration()const;

	void printListByDateAdded()const;
	void printListByInverseDateAdded();
	void printListBySongDurration()const;
	void printGenre(string genreChoice)const;
	void printArtist(string artistName)const;

	void removeSongByName(string name);
	void removeSongsBySkipCounter(int numberOfSkips);
	void removeOneSongBySkipCounter(int numberOfSkips);

	void addSong();

	void shortenTo(int x);
	void changeAutoDeleteThreshhold(int x);
	void switchMaxType();
	void changeCapacity(int x);

	void removalCheck();
	~PlayList();
};
