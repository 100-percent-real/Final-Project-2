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
	skipMax = 3;
	songMax = 20;
}

double PlayList::getTotalDuration() const
{
	double total = 0.0;
	for (const Song& s : playList)
	{
		total += s.duration;
	}
	return total;
}

void PlayList::printListByDateAdded() const
{
	if (playList.empty())
	{
		cout << "Playlist is empty.\n";
		return;
	}

	cout << std::fixed << std::setprecision(2);
	for (const Song& s : playList)
	{
		cout << s.songName << " by " << s.artist
			<< " (" << s.genre << ", "
			<< s.duration << " min)\n";
	}

	cout << "\nTotal songs: " << playList.size() << endl;
	cout << "Total duration: " << getTotalDuration() << " minutes\n";
}

void PlayList::printListByInverseDateAdded()
{
	if (playList.empty())
	{
		cout << "Playlist is empty.\n";
		return;
	}
	/*
	std::list<Song>::iterator curr;
	curr = playList.end();
	for (auto i : playList)
	{
		cout << curr->songName << " by " << curr->artist
			<< " (" << curr->genre << ", "
			<< curr->duration << " min)\n";
		curr--;
	*/
	
	for (auto it = playList.rbegin(); it != playList.rend(); ++it)
	{
		cout << it->songName << " by " << it->artist
			<< " (" << it->genre << ", "
			<< it->duration << " min)\n";
	}
		cout << "\nTotal songs: " << playList.size() << std::endl;
		cout << "Total duration: " << getTotalDuration() << " minutes\n";
}

void PlayList::printListBySongDuration(bool ascending)const
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

void PlayList::printGenre(string genreChoice) const
{
	cout << "Songs with the genre of  " << genreChoice << ":" << endl;
	for (auto i : playList)
	{
		if (genreChoice == i.genre) // compared it to artist, so i assume copy paste and didnt change it
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

/*
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
*/
void PlayList::removeMostSkippedSong()
{
	std::list<Song>::iterator i;
	std::list<Song>::iterator j;
	i = playList.begin();
	j = playList.begin();
	for (auto c : playList)
	{
		if (i->skipCounter > j->skipCounter)
		{
			j = i;
		}
		i++;
	}
	std::string name = j->songName;
	playList.erase(j);
	std::cout << name << " was removed from your play list.";
}


void PlayList::addSong()
{
	std::string name;
	std::string artist;
	std::string genre;
	double duration = 0.0;

	std::system("cls");
	std::cout << "Entering song's information\n";

	std::cout << "Enter song name: ";
	std::getline(std::cin, name);
	std::cout << "Enter artist name: ";
	std::getline(std::cin, artist);

	std::cout << "Enter genre: ";
	std::getline(cin, genre);

	std::cout << "Enter Duration (minutes): ";
	cin >> duration;
	cin.ignore();

	std::system("cls");

	Song newSong;
	newSong.songName = name;
	newSong.duration = duration;

	newSong.artist = artist;
	newSong.genre = genre;
	newSong.skipCounter = 0;

	playList.push_back(newSong);

	std::cout << "\nSong has been successfully added!\n";
	removalCheck();
}

void PlayList::startPlayList()
{
	if (playList.empty())
	{
		cout << "Playlist is empty.\n";
		return;
	}

	auto temp = playList.begin();
	char choice1;
	char choice2;
	do
	{
		do
		{
			system("cls");
			cout << temp->artist << endl;
			cout << temp->duration << endl;
			cout << temp->genre << endl;
			cout << temp->songName << endl << endl;

			do
			{
				cout << "skip song (Y/N)" << endl;
				cin >> choice1;

				if (toupper(choice1) == 'Y')
				{
					temp->skipCounter++;
				}
				else if (toupper(choice1) != 'N')
				{
					cout << "Please choose Y or N" << endl;
				}
			} while (toupper(choice1) != 'N' && toupper(choice1) != 'Y'); // added toupper(choice1)

			temp++;
		} while (temp != playList.end());

		cout << "Would you like to listen to your playlist again?(Y/N)\n";
		cin >> choice2;
		while (toupper(choice2) != 'Y' && toupper(choice2) != 'N')
		{
			cout << "Error. invalid input.\nPlease choose Y or N\n";
			cin >> choice2;
		}
		if (toupper(choice2) == 'Y')
		{
			temp = playList.begin();   // this is needed for program not to crash
		}
	} while (toupper(choice2) != 'N');
	removalCheck();
}

void PlayList::changeSkipMax(int x)
{
	if (x < 0)
	{
		cout << "Auto delete threshhold must be positive.\n";
		return;
	}
	if (skipMax == x)
	{
		cout << "Playlist auto delete threshhold was already at " << skipMax << " skips.\n";
	}
	else
	{
		skipMax = x;
		cout << "Playlist auto delete threshhold changed to " << skipMax << " skips.\n";
		removalCheck();
	}
}

void PlayList::switchMaxType()
{
	int choice = 1;
	// True == Maximum number of skips
	// False == maximum number of songs
	cout << "What kind of maximum would you like?\n";
	cout << "1.Maximum number of skips before removal.\n";
	cout << "2.Maximum number of songs before removal.\n";
	cin >> choice;
	if (choice != 1)
	{
		maxType = false;
		removalCheck();
	}
}

void PlayList::changeSongMax(int x)
{
	if (x < 0)
	{

		cout << "Maximum Song Threshhold must be positive.\n";
		return;
	}
	if (songMax == x)
	{
		cout << "Maximum Song threshhold was already at " << skipMax << " songs.\n";
	}
	else
	{
		songMax = x;
		cout << "Maximum Song threshhold changed to " << skipMax << " songs.\n";

		removalCheck();
	}
}

void PlayList::removalCheck()
{
	if (!playList.empty())
	{
		// True == Maximum number of skips
		if (maxType)
		{
			list<Song>::iterator curr1;
			list<Song>::iterator curr2;
			curr1 = playList.begin();
			curr2 = playList.begin();
			for (auto i : playList)
			{
				if (curr1->skipCounter > skipMax)
				{
					curr2++;
					playList.erase(curr1);
					curr1 = curr2;
				}
			}
		}
		else
		{
			// False == maximum number of songs
			while (playList.size() > songMax)
			{
				removeMostSkippedSong();
			}
		}
	}
}


PlayList::~PlayList()
{

}