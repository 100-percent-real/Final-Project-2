/*
TeamName.txt
CMPR 131 - Fall 2025
November 23, 2025
Final Project #2
Collaboration:
Dobritsa Alexey, *Eli Christiansen, Kevin Mabry, Ethan Hoang
 */

#include "PlayList.h"
#include "Utility.h"


PlayList::PlayList()
{
	skipMax = 3;
	songMax = 20;
	maxType = true;
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
		system("cls");
		std::cout << "Playlist is empty.\n";
		return;
	}

	std::cout << std::fixed << std::setprecision(2);

	for (auto it = playList.rbegin(); it != playList.rend(); ++it)
	{
		std::cout << it->songName << " by " << it->artist
			<< " (" << it->genre << ", "
			<< it->duration << " min)\n";
	}

	std::cout << "\nTotal songs: " << playList.size() << std::endl;
	std::cout << "Total duration: " << getTotalDuration() << " minutes\n";
}

void PlayList::printListByInverseDateAdded()
{
	if (playList.empty())
	{
		system("cls");
		std::cout << "Playlist is empty.\n";
		return;
	}

	std::cout << std::fixed << std::setprecision(2);

	for (auto it = playList.begin(); it != playList.end(); ++it)
	{
		std::cout << it->songName << " by " << it->artist
			<< " (" << it->genre << ", "
			<< it->duration << " min)\n";
	}
	std::cout << "\nTotal songs: " << playList.size() << std::endl;
	std::cout << "Total duration: " << getTotalDuration() << " minutes\n";

	/*auto curr = playList.end();
	for (int i = 0; i < playList.size(); i++)
	{

		std::cout << curr->songName << " by " << curr->artist;
		std::cout << " (" << curr->genre << ", ";
		std::cout << curr->duration << " min)\n";
		curr--;

		std::cout << "\nTotal songs: " << playList.size() << std::endl;
		std::cout << "Total duration: " << getTotalDuration() << " minutes\n";
	}*/
}

void PlayList::printListBySongDuration(bool ascending)const
{
	if (playList.empty())
	{
		system("cls");
		std::cout << "Playlist is empty.\n";
		return;
	}

	std::list<Song> sortedList = playList;

	sortedList.sort([ascending](const Song& a, const Song& b) {
		return ascending ? (a.duration < b.duration)
			: (a.duration > b.duration);
		});

	for (const Song& s : sortedList)
	{
		std::cout << s.songName << " by " << s.artist
			<< " (" << s.genre << ", "
			<< s.duration << " min)\n";
	}

	std::cout << "\nTotal songs: " << playList.size() << std::endl;
	std::cout << "Total duration: " << getTotalDuration() << " minutes\n";
}

void PlayList::printGenre(std::string genreChoice) const
{
	bool found = false;
	system("cls");
	std::cout << "Songs with the genre of " << genreChoice << ":" << std::endl;

	for (auto i : playList)
	{
		if (genreChoice == i.genre)
		{
			found = true;
			std::cout << i.songName << " by " << i.artist
				<< " ("
				<< i.duration << " min)\n";
		}
	}

	if (!found)
	{
		std::cout << "No songs found for genre: " << genreChoice << "\n";
	}
}

void PlayList::printArtist(std::string artistName) const
{
	bool found = false;
	system("cls");
	std::cout << "Songs by " << artistName << ":" << std::endl;
	for (auto i : playList)
	{
		if (artistName == i.artist)
		{
			found = true;
			std::cout << i.songName
				<< " (" << i.genre << ", "
				<< i.duration << " min)\n";
		}
	}

	if (!found)
	{
		std::cout << "No songs found for artist: " << artistName << "\n";
	}
}

void PlayList::removeSongByName(std::string name)
{
	for (auto ptr = playList.begin(); ptr != playList.end(); ptr++)
	{
		if (ptr->songName == name)
		{
			playList.erase(ptr);
			system("cls");
			std::cout << "The Song: " << name << " was removed from your playlist\n";
			return;
		}
	}
	system("cls");
	std::cout << "Song you entered: " << name << " is not in your playlist"
		<< " so it was not deleted.\n";
}



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
	std::cout << "Removing " << name << "\n";
}


void PlayList::addSong()
{
	std::string name;
	std::string artist;
	std::string genre;
	double duration = 0.0;

	std::system("cls");
	std::cout << "Entering song's information\n";

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	name = getValidStringUnlimited("Enter song name: ");
	artist = getValidStringUnlimited("Enter artist name: ");
	genre = getValidStringNoDigitsUnlimited("Enter genre: ");

	std::cout << "Enter Duration (minutes): ";
	duration = getValidDouble(0.0, 1000.0);

	if (duration == -1)
	{
		system("cls");
		std::cout << "Failed to add song due to invalid duration. Returning to previous menu.\n";
		return;
	}

	std::system("cls");

	Song newSong;
	newSong.songName = name;
	newSong.duration = duration;

	newSong.artist = artist;
	newSong.genre = genre;
	newSong.skipCounter = 0;

	playList.push_back(newSong);

	std::cout << "Song has been successfully added!\n";
	removalCheck();
}

void PlayList::startPlayList()
{
	if (playList.empty())
	{
		system("cls");
		std::cout << "Playlist is empty.\n";
		return;
	}

	auto temp = playList.begin();
	char choice1 = 'N';
	char choice2 = 'N';
	const int maxAttempts = 3;
	int attempts;

	do
	{
		temp = playList.begin();
		do
		{
			system("cls");
			std::cout << "Playing:\n";

			std::cout << temp->songName << " by " << temp->artist
				<< " (" << temp->genre << ", "
				<< temp->duration << " min)\n";

			attempts = 0;
			std::cout << "skip song (Y/N): ";
			std::cin >> choice1;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			while (attempts < maxAttempts && (toupper(choice1) != 'Y' && toupper(choice1) != 'N'))
			{
				std::cout << "Invalid input. Please choose Y or N: ";
				std::cin >> choice1;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				attempts++;
			}
			if (attempts >= maxAttempts)
			{
				system("cls");
				std::cout << "Too many invalid attempts. Returning to previous menu.\n";
				system("pause");
				system("cls");
				return;
			}
			if (toupper(choice1) == 'Y')
			{
				temp->skipCounter++;
			}
			temp++;

		} while (temp != playList.end());

		attempts = 0;
		system("cls");
		std::cout << "Would you like to listen to your playlist again? (Y/N): ";
		std::cin >> choice2;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


		while (attempts < maxAttempts && (toupper(choice2) != 'Y' && toupper(choice2) != 'N'))
		{
			std::cout << "Invalid input.\nPlease choose Y or N: ";
			std::cin >> choice2;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			attempts++;
		}
		if (attempts >= maxAttempts)
		{
			system("cls");
			std::cout << "Too many invalid attempts. Returning to previous menu.\n";
			system("pause");
			system("cls");
			return;
		}
	} while (toupper(choice2) != 'N');

	removalCheck();
}

void PlayList::changeSkipMax(int x)
{
	if (skipMax == x)
	{
		system("cls");
		std::cout << "Playlist auto delete threshold was already at " << skipMax << " skips.\n";
	}
	else
	{
		system("cls");
		skipMax = x;
		std::cout << "Playlist auto delete threshold changed to " << skipMax << " skips.\n";
		//removeSongsBySkipCounter(skipMax);
		removalCheck();
	}
}

void PlayList::switchMaxType()
{
	std::cout << "What kind of maximum would you like?\n"
		<< "1. Maximum number of skips before removal.\n"
		<< "2. Maximum number of songs before removal.\n"
		<< "\nEnter your choice: ";

	int choice2 = getValidNumber(1, 2);

	if (choice2 == -1)
		return;

	bool choice1 = (choice2 == 1);

	if (choice1 != maxType)
	{
		maxType = choice1;
		removalCheck();
	}
	else
	{
		system("cls");
		std::cout << "Maximum type is already set to that.\n";;
	}
}

void PlayList::changeSongMax(int x)
{
	if (songMax == x)
	{
		system("cls");
		std::cout << "Maximum Song threshold was already at " << songMax << " songs.\n";
	}
	else
	{
		system("cls");
		songMax = x;
		std::cout << "Maximum Song threshold changed to " << songMax << " songs.\n";

		if (playList.size() > songMax)
		{
			std::cout << "Removing excess songs...\n";
			removalCheck();
		}
		else
		{
			std::cout << "No removal performed.\n";
		}
	}
}

void PlayList::removalCheck()
{
	if (playList.empty())
	{
		system("cls");
		std::cout << "Playlist is empty.\n";
		return;
	}

	// True == Maximum number of skips
	if (maxType) // Max skips
	{
		auto curr = playList.begin();
		while (curr != playList.end())
		{
			if (curr->skipCounter > skipMax)
			{
				std::cout << "Deleting " << curr->songName << std::endl;
				curr = playList.erase(curr);  // erase returns the next valid iterator
			}
			else
			{
				++curr;
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


PlayList::~PlayList()
{

}