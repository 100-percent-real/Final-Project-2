/*
TeamName.txt
CMPR 131 - Fall 2025
November 23, 2025
Final Project #2
Collaboration:
Dobritsa Alexey, Eli Christiansen, Kevin Mabry, Ethan Hoang
 */
#include"PlayList.h"

PlayList::PlayList()
{

}

int PlayList::getTotalDuration() const
{
	return 69;
}

void PlayList::printListByDateAdded() const
{
	for (const Song& s : playList)
	{
		cout << s.songName << " by " << s.artist
			<< " (" << s.genre << ", "
			<< s.duration << " min)\n\n";
	}
}

void PlayList::printListByInverseDateAdded() const
{

}

void PlayList::printListBySongDurration() const
{

}

void PlayList::printListByGenre() const
{

}

void PlayList::printListByArtist() const
{

}

void PlayList::removeSong(string name)
{

}

void PlayList::addSong(string name, double duration, string artist, string genre)
{
	Song newSong;
	newSong.songName = name;
	newSong.duration = duration;
	newSong.artist = artist;
	newSong.genre = genre;
	newSong.skipCounter = 0;

	playList.push_back(newSong);
}

void PlayList::shortenTo(int x)
{

}

void PlayList::changeAutoDeleteThreshhold(int x)
{

}

void PlayList::switchMaximumtype()
{

}

void PlayList::changeCapacity(int x)
{

}

PlayList::~PlayList()
{

}