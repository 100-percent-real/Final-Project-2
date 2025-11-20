/*
TeamName.txt
CMPR 131 - Fall 2025
November 23, 2025
Final Project #2
Collaboration:
Dobritsa Alexey, Eli Christiansen, Kevin Mabry, Ethan Hoang
 */
#include "PlayList.h"

int main()
{
	PlayList myPlayList;
	short int choice;

	do
	{
		cout << "\n === MUSIC PLAYLIST MENU ===\n";
		cout << "\nselect an option\n";
		cout << "\n#1: add a song\n"
			<< "\n#2: show songs by date added\n"
			<< "\n#3: show songs by duration\n"
			<< "\n#4: change playlist capacity\n"
			<< "\n#0: EXIT the program\n";
		// continue needed

		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1:
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
			getline(cin, genre);

			cout << "Enter Duration (minutes): ";
			cin >> duration;
			cin.ignore();

			system("cls");

			myPlayList.addSong(name, duration, artist, genre);
			cout << "\nSong has been successfully added!\n";
			break;
			system("cls");
		}
		case 2:
		{
			system("cls");
			cout << "Songs By date added:\n";
			myPlayList.printListByDateAdded();

			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			system("cls");
			cout << "Show songs By duration:\n";
			cout << "1. Shortest to longest\n";
			cout << "2. Longest to shortest\n";

			int orderChoice;
			cin >> orderChoice;
			cin.ignore();

			myPlayList.printListBySongDuration(orderChoice == 1);

			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			system("cls");
			int newCapacity;
			cout << "Enter new playlist capacity: ";
			cin >> newCapacity;
			cin.ignore();
			myPlayList.changeCapacity(newCapacity);

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