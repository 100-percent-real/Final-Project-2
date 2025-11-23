/*
TeamName.txt
CMPR 131 - Fall 2025
November 23, 2025
Final Project #2
Collaboration:
Dobritsa Alexey, *Eli Christiansen, Kevin Mabry, Ethan Hoang
 */
#include "PlayList.h"

int main()
{
	PlayList myPlayList;
	short int choice;

	do
	{
		std::cout << "\n === MUSIC PLAYLIST MENU ===\n";
		cout << "\nselect an option\n";
		cout << "\n#1: add a song\n"
			<< "\n#2: remove a song\n"
			<< "\n#3: show songs by date added\n"
			<< "\n#4: show songs by duration\n"
			<< "\n#5: show songs in a certain genre\n"
			<< "\n#6: show songs by a certain artist\n"
			<< "\n#7: change the maximum skips a song can have before automatic removal\n"
			//<< "\n#7: change the maximum song in your playlist automatic removal\n"
			//<< "\n#7: change the type of maximum your playlist uses(maximum songs or skips)\n"
			<< "\n#8: listen to your play list\n"
			<< "\n#0: EXIT the program\n";

		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1:
		{
			myPlayList.addSong();
			break;
		}
		case 2:
		{
			system("cls");
			string name;
			cout << "What is the name of the song you would like to remove?\n";
			getline(cin, name);
			myPlayList.removeSongByName(name);
			break;
		}
		case 3:
		{
			int orderChoice = 0;
			system("cls");
			cout << "Would you like to print from:\n1. Newest to oldest\n2. Oldest to newest\n";
			cin >> orderChoice;
			if (orderChoice == 1)
			{
				cout << "Songs By date added(new-old):\n";
				myPlayList.printListByDateAdded();
			}
			else if (orderChoice == 2)
			{
				cout << "Songs By date added(old-new):\n";
				myPlayList.printListByInverseDateAdded();
			}
			else
			{
				cout << "Error. Invalid input. Please choose 1 or 2\n";
			}

			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			int orderChoice = 0;
			system("cls");
			cout << "Would you like to print from:\n1. longest-shortest\n2. shortest to longest\n";
			cin >> orderChoice;

			if (orderChoice == 1)
			{
				cout << "Songs By duration(longest-shortest):\n";
				myPlayList.printListBySongDuration(false);
			}
			else if (orderChoice == 2)
			{
				cout << "Songs By duration(shortest to longest):\n";
				myPlayList.printListBySongDuration(true);
			}
			else
			{
				cout << "Error. Invalid input. Please choose 1 or 2\n";
			}
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			system("cls");
			string genreChoice;
			cout << "What genre would you like to see?\n";
			getline(cin, genreChoice);
			myPlayList.printGenre(genreChoice);
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			system("cls");
			string artistChoice;
			cout << "What artist would you like to see?\n";
			getline(cin, artistChoice);
			myPlayList.printArtist(artistChoice);
			system("pause");
			system("cls");
			break;
		}
		case 7:
		{
			system("cls");
			myPlayList.switchMaxType();
			system("pause");
			system("cls");
			break;
		}
		case 8:
		{
			system("cls");
			myPlayList.startPlayList();
			system("pause");
			system("cls");
			break;
		}
		case 0:
		{
			system("cls");
			cout << "\nThanks for using the program\n";
			system("pause");
			return 0;
		}
		default:
		{
			system("cls");
			cout << "invalid choice, try again...\n";
		}
		}
	} while (choice != 0);

	return 0;
}
// End of main.cpp