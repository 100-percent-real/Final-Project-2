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
	int choice;

	do
	{
		cout << "\n ===== MUSIC PLAYLIST MENU =====\n";
		cout << "\nselect an option\n";
		cout << "\n#1: Add a song\n"
			<< "\n#2: Show songs by date added\n"
			<< "\n#3: Delete a song\n"
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
			string name;
			cout << "Which song you want to delete:\n";
			getline(cin, name);
			//cin.ignore();
			myPlayList.removeSong(name);

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