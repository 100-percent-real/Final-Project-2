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
using namespace std;

void displayMenu();
int getValidChoice();
void processChoice(PlayList&);


int main()
{
	PlayList myPlayList;

	processChoice(myPlayList);
}
// End of main.cpp

/*
	Function: displayMenu
	Description:
	Displays the main menu options to the user.
*/
void displayMenu()
{
	cout << "\n=== MUSIC PLAYLIST MENU ===\n";
	cout << "\nSelect an option:\n\n";
	cout << "    #1: add a song\n"
		<< "    #2: remove a song\n"
		<< "    #3: show songs by date added\n"
		<< "    #4: show songs by duration\n"
		<< "    #5: show songs in a certain genre\n"
		<< "    #6: show songs by a certain artist\n"
		<< "    #7: change the maximum skips a song can have before automatic removal\n"
		<< "    #8: change the maximum number of songs in your playlist before automatic removal\n"
		<< "    #9: change the type of maximum your playlist uses(maximum songs or skips)\n"
		<< "    #10: listen to your play list\n"
		<< "    #11: EXIT the program\n";
}

/*
	Function: getValidChoice
	Description:
	Validates and retrieves the user's menu choice.
	Handles invalid inputs and restricts excessive invalid attempts.
	Returns:
	- A valid choice (1 to 11) or -1 to indicate too many invalid attempts.
*/
int getValidChoice()
{
	int choice;
	int attempts = 0;
	const int maxRetries = 3; // Maximum number of retries

	while (attempts < maxRetries)
	{
		cout << "\nEnter your choice: ";

		// Validate numeric input
		if (!(cin >> choice))
		{
			cin.clear(); // Clear error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
			cout << "Invalid input. Please enter a number between 1 and 11.\n";
			attempts++;
			continue;
		}

		// Validate range
		if (choice < 1 || choice > 11)
		{
			cout << "Sorry. That is not a selection.\n";
			attempts++;
			continue;
		}

		return choice; // Valid input
	}

	// Too many invalid attempts
	system("cls");
	cout << "Too many invalid attempts. Returning to the main menu.\n";
	system("pause");
	system("cls");
	return -1; // Indicate return to main menu
}

/*
	Function: processChoice
	Description:
	Processes the user's menu choice and executes the corresponding functionality.
	Handles invalid inputs and returns to the menu when necessary.
	Parameters:
	- candidateList: The list of candidates to operate on.
*/
void processChoice(PlayList& myPlayList)
{
	short int choice;

	// Display menu initially
	displayMenu();

	while (true)
	{
		choice = getValidChoice(); // Get a validated choice

		if (choice == -1)
		{ // Return to menu after retries
			displayMenu();
			continue;
		}
		if (choice == 11)
		{ // Exit option
			system("cls");
			cout << "Thanks for using the program\n";
			system("pause");
			return;
		}

		switch (choice)
		{
		case 1:
		{
			system("cls");
			myPlayList.addSong();
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "What is the name of the song you would like to remove?\n";

			string name = getValidMenuString();

			if (name.empty())
			{
				system("cls");
				cout << "Failed to remove song due to invalid name. Returning to previous menu.\n";
				system("pause");
				system("cls");
				break;
			}

			myPlayList.removeSongByName(name);
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			system("cls");
			int orderChoice = -1;

			cout << "Would you like to print from:\n"
				<< "1. Newest to oldest\n"
				<< "2. Oldest to newest\n";

			cout << "\nEnter your choice: ";
			orderChoice = getValidNumber(1, 2);

			if (orderChoice == -1) // Exceeded attempts
				break;

			system("cls");
			if (orderChoice == 1)
			{
				system("cls");
				cout << "Songs By date added(new-old):\n";
				myPlayList.printListByDateAdded();
			}
			else if (orderChoice == 2)
			{
				system("cls");
				cout << "Songs By date added(old-new):\n";
				myPlayList.printListByInverseDateAdded();
			}
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			system("cls");
			cout << "Would you like to print from:\n"
				<< "1. longest-shortest\n"
				<< "2. shortest to longest\n"
				<< "\nEnter your choice: ";

			int orderChoice = getValidNumber(1, 2);

			if (orderChoice == -1)
				break;

			if (orderChoice == 1)
			{
				system("cls");
				cout << "Songs By duration(longest-shortest):\n";
				myPlayList.printListBySongDuration(false);
			}
			else if (orderChoice == 2)
			{
				system("cls");
				cout << "Songs By duration(shortest to longest):\n";
				myPlayList.printListBySongDuration(true);
			}
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "What genre would you like to see?\n";

			string genreChoice = getValidMenuStringNoDigits();

			if (genreChoice.empty())
			{
				system("cls");
				std::cout << "Failed to look for genre due to invalid name. Returning to previous menu.\n";
				system("pause");
				system("cls");
				break;
			}

			myPlayList.printGenre(genreChoice);
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "What artist would you like to see?\n";

			string artistChoice = getValidMenuString();

			if (artistChoice.empty())
			{
				system("cls");
				std::cout << "Failed to look for artist due to invalid name. Returning to previous menu.\n";
				system("pause");
				system("cls");
				break;
			}

			myPlayList.printArtist(artistChoice);
			system("pause");
			system("cls");
			break;
		}
		case 7:
		{
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "What would you like the maximum number of skips to be ? \n";

			int x;

			while (true)
			{
				cout << "\nEnter your choice: ";
				x = getValidPositiveInt("");

				if (x == -1)  // Too many failed attempts in validator
				{
					system("cls");
					cout << "Failed to change maximum skip limit. Returning to previous menu.\n";
					system("pause");
					system("cls");
					goto end_case_7;
				}

				if (x > 1000) // Out of allowed range
				{
					cout << "Invalid option. Skip limit must be between 0 and 1000. Try again: ";
					continue;
				}

				break;
			}

			myPlayList.changeSkipMax(x);
			system("pause");
			system("cls");
		end_case_7:
			break;
		}
		case 8:
		{
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "What would you like the maximum number of songs to be?\n"
				<< "\nEnter your choice: ";

			int x;

			while (true)
			{
				x = getValidPositiveInt("");

				if (x == -1) // Too many failures from utility
				{
					system("cls");
					cout << "Failed to change maximum song limit. Returning to previous menu.\n";
					system("pause");
					system("cls");
					goto end_case_8;
				}

				if (x > 9999) // Out of allowed range
				{
					cout << "Invalid option. Song limit must be between 1 and 9999. Try again: ";
					continue;
				}

				break;
			}

			myPlayList.changeSongMax(x);
			system("pause");
			system("cls");
		end_case_8:
			break;

		}
		case 9:
		{
			system("cls");
			myPlayList.switchMaxType();
			system("pause");
			system("cls");
			break;
		}
		case 10:
		{
			system("cls");
			myPlayList.startPlayList();
			system("pause");
			system("cls");
			break;
		}
		default:
			break;
		}

		displayMenu(); // Redisplay the menu
	}
}