/*
TeamName.txt
CMPR 131 - Fall 2025
November 23, 2025
Final Project #2
Collaboration:
Dobritsa Alexey, *Eli Christiansen, Kevin Mabry, Ethan Hoang
 */

#include "Utility.h"
#include <string>
#include <algorithm>
using namespace std;

int getValidNumber(int min, int max)
{
    string input;
    int attempts = 0;
    const int maxAttempts = 3;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (attempts < maxAttempts)
    {
        getline(cin, input);

        if (input.empty())
        {
            cout << "Input cannot be empty. Try again: ";
            attempts++;
            continue;
        }

        // Reject decimals
        if (input.find('.') != std::string::npos)
        {
            cout << "Input cannot be a decimal. Try again: ";
            attempts++;
            continue;
        }

        // Ensure all characters are digits (allow negative only if allowed)
        bool valid = true;
        for (char c : input)
        {
            if (!isdigit(c) && !(c == '-' && input.size() > 1))
            {
                valid = false;
                break;
            }
        }

        if (!valid)
        {
            cout << "Invalid input. Please enter a number: ";
            attempts++;
            continue;
        }

        // Convert to number
        int value = stoi(input);

        // Check range
        if (value < min || value > max)
        {
            cout << "Invalid option. Please enter a number between "
                << min << " and " << max << ": ";
            attempts++;
            continue;
        }

        return value; // Valid input
    }

    system("cls");
    cout << "Too many invalid attempts. Returning to previous menu.\n";
    system("pause");
    system("cls");
    return -1;
}
int getValidPositiveInt(const string& prompt)
{
    string input;
    int attempts = 0;
    const int maxAttempts = 3;

    while (attempts < maxAttempts)
    {
        cout << prompt;
        getline(cin, input);

        if (input.empty())
        {
            cout << "Input cannot be empty. Try again: ";
        }
        else
        {
            bool hasDecimal = (input.find('.') != string::npos);

            // Allow negative or positive sign but only at beginning
            bool isNumber =
                (all_of(input.begin(), input.end(), ::isdigit)) ||
                ((input[0] == '-' || input[0] == '+') &&
                    all_of(input.begin() + 1, input.end(), ::isdigit));

            if (hasDecimal)
            {
                cout << "Invalid option. Please enter a number greater than 0: ";
            }
            else if (!isNumber)
            {
                cout << "Invalid input. Please enter a number: ";
            }
            else
            {
                int value = stoi(input);
                if (value > 0)
                    return value;
                else
                    cout << "Invalid option. Please enter a number greater than 0: ";
            }
        }

        attempts++;
    }

    return -1;
}
double getValidDouble(double min, double max)
{
    double value;
    int attempts = 0;
    const double maxAttempts = 3;

    while (attempts < maxAttempts)
    {
        if (!(cin >> value))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
        }
        else if (value < min || value > max)
        {
            cout << "Invalid option. Please enter a number between "
                << min << " and " << max << ": ";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        attempts++;
    }

    return -1;
}
string getValidMenuString()
{
    string input;
    const int maxAttempts = 3;
    int attempts = 0;

    while (attempts < maxAttempts)
    {
        getline(cin, input);

        if (input.empty())
        {
            if (attempts >= maxAttempts)
                break;

            cout << "Input cannot be empty. Try again: ";
            attempts++;
            continue;
        }

        return input; // Valid input
    }

    return ""; // Return empty if too many failures
}
string getValidMenuStringNoDigits()
{
    string input;
    const int maxAttempts = 3;
    int attempts = 0;

    while (attempts < maxAttempts)
    {
        getline(cin, input);

        if (input.empty())
        {
            if (attempts >= maxAttempts)
                break;

            cout << "Input cannot be empty. Try again: ";
            attempts++;
            continue;
        }

        if (any_of(input.begin(), input.end(), ::isdigit))
        {
            cout << "Invalid input. Input cannot contain numbers. Try again: ";
            attempts++;
            continue;
        }


        return input; // Valid input
    }

    return ""; // Return empty if too many failures
}
string getValidStringNoDigits()
{
    string input;
    int attempts = 0;
    const int maxAttempts = 3;

    while (attempts < maxAttempts)
    {
        getline(cin, input);

        if (input.empty())
        {
            cout << "Input cannot be empty. Try again: ";
            attempts++;
            continue;
        }

        bool hasDigit = false;
        for (char c : input)
        {
            if (isdigit(static_cast<unsigned char>(c)))
            {
                hasDigit = true;
                break;
            }
        }

        if (!hasDigit)
        {
            return input;
        }

        cout << "Invalid input. Genre cannot contain numbers. Try again: ";
        attempts++;
    }

    return "INVALID";
}
string getValidStringUnlimited(const string& prompt)
{
    string input;
    cout << prompt;

    while (true)
    {
        getline(cin, input);

        if (input.empty())
        {
            cout << "Input cannot be empty. Try again: ";
            continue;
        }

        return input;
    }
}
string getValidStringNoDigitsUnlimited(const string& prompt)
{
    string input;
    cout << prompt;

    while (true)
    {
        getline(cin, input);

        if (input.empty())
        {
            cout << "Input cannot be empty. Try again: ";
            continue;
        }

        if (any_of(input.begin(), input.end(), ::isdigit))
        {
            cout << "Input cannot contain digits. Try again: ";
            continue;
        }

        return input;
    }
}
string getValidNonEmptyString(const string& prompt)
{
    string input;
    int attempts = 0;
    const int maxAttempts = 3;

    while (attempts < maxAttempts)
    {
        cout << prompt;
        getline(cin, input);

        if (input.empty())
        {
            cout << "Input cannot be empty. Try again.\n";
            attempts++;
            continue;
        }
        return input;
    }

    return "INVALID";
}