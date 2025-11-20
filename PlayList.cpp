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
	capacity = 100;
}

double PlayList::getTotalDuration() const
{
	double total = 0.0;
	for (const Song& s : playList)
		total += s.duration;
	return total;
}

void PlayList::printListByDateAdded() const
{
	if (playList.empty())
	{
		cout << "Playlist is empty.\n";
		return;
	}

	cout << fixed << setprecision(2);
	for (const Song& s : playList)
	{
		cout << s.songName << " by " << s.artist
			<< " (" << s.genre << ", "
			<< s.duration << " min)\n";
	}

	cout << "\nTotal songs: " << playList.size() << endl;
	cout << "Total duration: " << getTotalDuration() << " minutes\n";
}

void PlayList::printListByInverseDateAdded() const
{

}

void PlayList::printListBySongDuration(bool ascending) const
{
	if (playList.empty())
	{
		cout << "Playlist is empty.\n";
		return;
	}

	list<Song> sortedList = playList;

	sortedList.sort([ascending](const Song& a, const Song& b) {
		return ascending ? (a.duration < b.duration)
			: (a.duration > b.duration);
	});

	cout << fixed << setprecision(2);
	for (const Song& s : sortedList)
	{
		cout << s.songName << " by " << s.artist
			<< " (" << s.genre << ", "
			<< s.duration << " min)\n";
	}
}

void PlayList::printListByGenre() const
{

}

void PlayList::printListByArtist() const
{

}

void PlayList::removeSong(string name)
{
	for (auto ptr = playList.begin(); ptr != playList.end(); ptr++)
	{
		if (ptr->songName == name)
		{
			playList.erase(ptr);
			cout << "\nThe Song: " << name << " was removed from your playlist\n";
			return;
		}
	}

	cout << "Song you entered " << name << " is not in your playlist"
		<< " so it was not deleted.\n";
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
	if (x <= 0)
	{
		cout << "Capacity must be greater than 0.\n";
		return;
	}

	capacity = x;
	cout << "Playlist capacity changed to " << capacity << " songs.\n";

	while (playList.size() > capacity)
	{
		playList.pop_back();
	}
}

PlayList::~PlayList()
{

}