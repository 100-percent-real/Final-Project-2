#pragma once

#include"Song.h"

class PlayList
{
private:
	list<Song> playList;
public:
	PlayList();
	int getTotalDuration()const;
	void printListByDateAdded()const;
	void printListByInverseDateAdded()const;
	void printListBySongDurration()const;
	void printListByGenre()const;
	void printListByArtist()const;
	void removeSong(string name);
	void addSong(string name, double duration, string artist, string genre); 
	void shortenTo(int x); 
	void changeAutoDeleteThreshhold(int x);
	void switchMaximumtype(); 
	void changeCapacity(int x);
	~PlayList();
};
