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
		cout << "\n === MUSIC PLAYLIST MENU ===\n";
		cout << "\nselect an option\n";
		cout << "\n#1: add a song\n"
			<< "\n#2: show songs by date added\n"
			<< "\n#0: EXIT the program\n";
		// continue needed

		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1:
		{
			myPlayList.addSong();
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
