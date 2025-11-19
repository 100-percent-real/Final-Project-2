/*
TeamName.txt
CMPR 131 - Fall 2025
November 23, 2025
Final Project #2
Collaboration:
Dobritsa Alexey, *Eli Christiansen, Kevin Mabry, Ethan Hoang
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

void PlayList::printListByInverseDateAdded() 
{
	playList.reverse();
	printListByDateAdded();
	playList.reverse();
}

void PlayList::printListBySongDurration() const
{
	Song max = playList.front();
	PrintedArray myArray = PrintedArray(playList.size());

	for (auto i: playList)
	{
		
			
		for (auto j: playList)
		{

			if (j.duration > max.duration && !myArray.has(j.songName) )
			{
				max = j;

			}
		}
		cout << max.songName << " by " << max.artist
			<< " (" << max.genre << ", "
			<< max.duration << " min)\n\n";
		myArray.assignAt(max.songName);
	}

}

void PlayList::printGenre(string genreChoice) const
{
	cout << "Songs by " << genreChoice << ":" << endl;
	for (auto i : playList)
	{
		if (genreChoice == i.artist)
		{
			cout << i.songName << " by " << i.artist
				<< " (" << i.genre << ", "
				<< i.duration << " min)\n\n";
		}
	}

}

void PlayList::printArtist(string artistName) const
{
	cout << "Songs by " << artistName << ":" << endl;
	for (auto i : playList)
	{
		if (artistName == i.artist)
		{
			cout << i.songName << " by " << i.artist
				<< " (" << i.genre << ", "
				<< i.duration << " min)\n\n";
		}
	}

}

void PlayList::removeSongByName(string name)
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

void PlayList::removeSongsBySkipCounter(int numberOfSkips)
{
	for (auto ptr = playList.begin(); ptr != playList.end(); ptr++)
	{
		if (ptr->skipCounter >= numberOfSkips)
		{
			string name = ptr->songName;
			playList.erase(ptr);
			cout << "\nThe Song: " << name << " was removed from your playlist\n";
			
		}
	}
}

void PlayList::removeOneSongBySkipCounter(int numberOfSkips)
{
	for (auto ptr = playList.begin(); ptr != playList.end(); ptr++)
	{
		if (ptr->skipCounter == numberOfSkips)
		{
			string name = ptr->songName;
			playList.erase(ptr);
			cout << "\nThe Song: " << name << " was removed from your playlist\n";
			return;
		}
	}
	cout << "No songs were removed.\n";
}


void PlayList::addSong()
{
	string name;
	string artist;
	string genre;
	double duration = 0.0;

	system("cls");
	cout << "Entering song's information\n";

	cout << "Enter song name: ";
	getline(cin, name);

	cout << "Enter artist name: ";
	getline(cin, artist);

	cout << "Enter genre: ";
	int g = -1;
	cout << "What is the genre of the song?\n";
	cout << "1.Pop\n";
	cout << "2.Rock\n";
	cout << "3.Jazz\n";
	cout << "4.Hip-hop\n";
	cout << "5.Alt\n";
	cout << "6.Latin\n";
	cout << "7.Classical\n";
	cout << "8.Other\n";
	cin >> g;
	while (g < 1 || g>8)
	{
		cout << "Invalid input, try again.";
			cin >> g;
	}
	if (g == 1)
	{
		genre = "Pop";
	}
	else if (g == 2)
	{
		genre = "Rock";
	}
	else if (g == 3)
	{
		genre = "Jazz";
	}
	else if (g == 4)
	{
		genre = "Hip-hop";
	}
	else if (g == 5)
	{
		genre = "Alt";
	}
	else if (g == 6)
	{
		genre = "Latin";
	}
	else if (g == 7)
	{
		genre = "Classical";
	}
	else if (g == 8)
	{
		genre = "Other";
	}


	cout << "Enter Duration (minutes): ";
	cin >> duration;
	cin.ignore();

	system("cls");

	
	Song newSong;
	newSong.songName = name;
	newSong.duration = duration;

	newSong.artist = artist;
	newSong.genre = genre;
	newSong.skipCounter = 0;

	playList.push_back(newSong);

	cout << "\nSong has been successfully added!\n";

}

void PlayList::shortenTo(int x)
{
	

}

void PlayList::changeAutoDeleteThreshhold(int x)
{

}

void PlayList::switchMaxType()
{

}

void PlayList::changeCapacity(int x)
{

}

PlayList::~PlayList()
{

}
