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


class PlayList
{
	friend class PrintedArray;
private:
	list<Song> playList;
	bool maxType;

	// True == Maximum number of skips
	// False == maximum number of songs
	int skipMax;
	int songMax;
public:
	PlayList();
	double getTotalDuration()const;

	void printListByDateAdded()const;
	void printListByInverseDateAdded();
	void printListBySongDuration(bool ascending)const;
	void printGenre(string genreChoice)const;
	void printArtist(string artistName)const;

	void removeSongByName(string name);
	//void removeSongsBySkipCounter(int numberOfSkips);
	void removeMostSkippedSong();

	void addSong();
	void startPlayList();


	void changeSkipMax(int x);
	void switchMaxType();
	void changeSongMax(int x);

	void removalCheck();
	~PlayList();
};
