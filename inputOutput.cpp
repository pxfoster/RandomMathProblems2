#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "inputOutput.h"
#include "mathProblems.h"

/*****************************************************************************
# Author:      Patrick Foster
# Assignment:  Final Project - inputOutput.cpp
# Date:        2/28/2023
# Description: This file holds all of the input and output functions
#              that the program uses.
#
# Input:       None
#
# Output:      None
#
# Sources:     Final Project Specifications
#****************************************************************************/

// Name:   getMenuInput()
// Desc:   This function handles input that deals with making menu choices.
//         It also validates the user input before returning.
// Input:  choice as Char
// Output: None
// Return: choice as Char
char getMenuInput()
{
	char choice = 0;

	cout << "Choice: ";
	cin.get(choice);

	while ((choice < '0' || choice > '4') && choice != '9')
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid Input!\n";
		cout << "Choice: ";
		cin.get(choice);
	}

	cin.clear();
	cin.ignore(100, '\n');

	return choice;
}

// Name:   getIntAnswer()
// Desc:   This function handles input that deals with answering a math problem.
//         It also validates the user input before returning.
// Input:  answer as Integer
// Output: None
// Return: answer as Integer
int getIntAnswer()
{
	bool isValid = false;
	int answer = 0;

	cout << "Answer: ";
	cin >> answer;

	while (!cin)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\nInvalid Input\n";
		cout << "Answer: ";
		cin >> answer;
	}

	cin.clear();
	cin.ignore(100, '\n');

	return answer;
}

// Name:   getSettingInput()
// Desc:   This function handles input that deals with changing settings.
//         It also validates the user input before returning.
// Input:  choice as Integer
// Output: None
// Return: choice as Integer
int getSettingInput()
{
	int choice = -1;

	cout << ">> ";
	cin >> choice;
	while (!cin || choice < 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid Input!\n";
		cout << ">> ";
		cin >> choice;
	}
	cin.clear();
	cin.ignore(100, '\n');

	return choice;
}

// Name:   playAgainMessage()
// Desc:   This function handles input that deals with wanting to play again.
//         It also validates the user input before returning.
// Input:  userInput as c-string
// Output: None
// Return: playAgain as Boolean
bool playAgainMessage()
{
	bool isValid = false;
	bool playAgain = false;
	char userInput[21] = { '\0' };
	char answer[5] = { '\0' };

	while (!isValid)
	{
		cout << "Would you like to try again?\n";
		cout << "Enter 'yes' or 'no': ";
		cin.getline(userInput, 20);

		if (cin.fail())
		{
			cout << "\nInvalid Input.\n";
			cin.clear();
			cin.ignore(100, '\n');
		}
		else
		{

			strncpy_s(answer, userInput, 4);

			if (strncmp(answer, "yes", 4) == 0)
			{
				playAgain = true;
				isValid = true;
			}
			else if (strncmp(answer, "no", 4) == 0)
			{
				playAgain = false;
				isValid = true;
			}
			else
			{
				cout << "\nInvalid input.\n";
			}
		}
	}

	return playAgain;
}

// Name:   showSettings(Settings&settings, ProblemType* problemTypes)
// Desc:   This function displays the settings menu to the user.
//         It continuously loops until the user is finished.
// Input:  None
// Output: Settings menu choices and values.
// Return: MAIN_MENU as Constant Integer
int showSettings(Settings& settings, ProblemType* problemTypes)
{
	bool finished = false;
	bool validChoice = false;
	int choice = 0;

	while (!finished)
	{
		validChoice = false;

		showTitle("Settings");
		cout << "First Number Digits: " << settings.firstNumberDigits << endl;
		cout << "Second Number Digits: " << settings.secondNumberDigits << endl;
		cout << endl;
		if (settings.allowNegative)
		{
			cout << "Subtraction with Negative Numbers: True\n";
		}
		else
		{
			cout << "Subtraction with Negative Numbers: False\n";
		}
		cout << endl;
		cout << "| Enter 1 to change number of digits for first number.\n";
		cout << "| Enter 2 to change number of digits for second number.\n";
		cout << "| Enter 3 to toggle allowing negative numbers in subtraction.\n";
		cout << "\n| Enter 0 to go back to the main menu.\n\n";

		while (!validChoice)
		{
			choice = getSettingInput();

			if (choice == 0)
			{
				saveSettings(settings, problemTypes);
				validChoice = true;
				finished = true;
			}
			else if (choice == 1)
			{
				validChoice = true;

				cout << "Enter number of digits for first number:\n";

				settings.firstNumberDigits = getSettingInput();

				if (settings.firstNumberDigits < 1)
				{
					cout << "Digits need to be greater than 0.\n";
					cout << "Defaulting to 1 digit.\n";

					settings.firstNumberDigits = 1;
				}
			}
			else if (choice == 2)
			{
				validChoice = true;

				cout << "Enter number of digits for second number:\n";

				settings.secondNumberDigits = getSettingInput();

				if (settings.secondNumberDigits < 1)
				{
					cout << "Digits need to be greater than 0.\n";
					cout << "Defaulting to 1 digit.\n";

					settings.secondNumberDigits = 1;
				}
			}
			else if (choice == 3)
			{
				validChoice = true;
				settings.allowNegative = !settings.allowNegative;
			}
			else
			{
				cout << "Invalid input!\n";
			}
		}

	}

	return MENU_MAIN;
}

// Name:   welcome()
// Desc:   This function displays a welcome message.
// Input:  None
// Output: None
// Return: None
void welcome()
{
	addFill('=', 47);
	cout << "| " << setw(18) << "Welcome to my Random Math Problems Program! |\n";
	addFill('=', 47);
}

// Name:   goodbye()
// Desc:   This function displays a goodbye message.
// Input:  None
// Output: None
// Return: None
void goodbye()
{
	cout << endl;
	addFill('=', 23);
	cout << "| " << setw(18) << "I hope you had fun! |\n";
	addFill('=', 23);
}

// Name:   showTitle(const char* titleName)
// Desc:   This function displays a title for the current program state.
// Input:  None
// Output: None
// Return: None
void showTitle(const char* titleName)
{
	cout << endl;
	addFill('=', int(strlen(titleName)) + 10);
	cout << "|    " << titleName << "    |\n";
	addFill('=', int(strlen(titleName)) + 10);
	cout << endl;
}

// Name:   showMenu()
// Desc:   This function displays the main menu.
// Input:  None
// Output: None
// Return: None
void showMenu()
{
	showTitle("Menu");
	cout << "| Enter 1 for Addition\n";
	cout << "| Enter 2 for Subtraction\n";
	cout << "| Enter 3 for Multiplication\n";
	cout << "| Enter 4 for Division\n";
	cout << endl;
	cout << "| Enter 9 for Settings\n";
	cout << "| Enter 0 to Quit\n";
	cout << endl;
}

// Name:   addFill(char fillChar, int fillAmount, int spacesBefore)
// Desc:   This function is used to help format the UI by filling spaces
//         with a chosen character.
// Input:  None
// Output: None
// Return: None
void addFill(char fillChar, int fillAmount, int spacesBefore)
{
	if (spacesBefore > 0)
	{
		cout << setw(spacesBefore) << " " << setfill(fillChar) << setw(fillAmount) << fillChar << setfill(' ');
	}
	else
	{
		cout << setfill(fillChar) << setw(fillAmount) << fillChar << setfill(' ');
	}

	cout << endl;
}

// Name:   addSpaces(int numSpaces)
// Desc:   This function is used to help format the layout of the UI
//         by adding extra spaces.
// Input:  None
// Output: None
// Return: None
void addSpaces(int numSpaces)
{
	if (numSpaces > 0)
	{
		cout << setw(numSpaces) << " ";
	}
}

// Name:   displayProblem(const int* numbers, char symbol, bool showAnswer)
// Desc:   This function formats and displays a math problem.
// Input:  None
// Output: None
// Return: None
void displayProblem(const int* numbers, char symbol, bool showAnswer)
{
	// Figure out the number of digits for each random number
	int firstNumberDigits = getNumDigits(numbers[FIRST_NUMBER]);
	int secondNumberDigits = getNumDigits(numbers[SECOND_NUMBER]);
	int numberAnswerDigits = getNumDigits(numbers[CORRECT_ANSWER]);
	int largest = numberAnswerDigits;

	if (largest < firstNumberDigits)
	{
		largest = firstNumberDigits;
	}

	if (largest < secondNumberDigits)
	{
		largest = secondNumberDigits;
	}

	// These declarations are used for formatting the problem
	int spacesToSymbol = 4;
	int spacesIncludeSymbol = spacesToSymbol + 2;
	int extraSpacesFirstNum = largest - firstNumberDigits;
	int extraSpacesSecondNumber = largest - secondNumberDigits;
	int extraSpacesAnswer = largest - numberAnswerDigits;

	addSpaces(spacesIncludeSymbol + extraSpacesFirstNum);
	cout << numbers[FIRST_NUMBER] << endl;
	addSpaces(spacesToSymbol);
	cout << symbol;
	addSpaces(1 + extraSpacesSecondNumber);
	cout << numbers[SECOND_NUMBER] << endl;
	addFill('-', 2 + largest + 2, 4);

	if (showAnswer)
	{
		if (numbers[CORRECT_ANSWER] > 0)
		{
			addSpaces(spacesIncludeSymbol + extraSpacesAnswer);
		}
		else
		{
			// Account for - symbol in negative numbers
			addSpaces(spacesIncludeSymbol + extraSpacesAnswer - 1);
		}

		cout << numbers[CORRECT_ANSWER] << endl;
	}
}

// Name:   getNumDigits(int number)
// Desc:   This function is a helper function that figures out
//         the number of digits in a number and returns it.
// Input:  None
// Output: None
// Return: digits as Integer
int getNumDigits(int number)
{
	int rem = 1;
	int testDigit = 1;
	int digits = 0;

	while (rem != 0)
	{
		rem = number / testDigit;
		if (rem != 0)
		{
			testDigit *= 10;
			digits += 1;
		}
	}

	return digits;
}

// Name:   displayCorrectMessage()
// Desc:   This function displays a correct or incorrect message to the user.
// Input:  None
// Output: None
// Return: None
void displayCorrectMessage(bool correctAnswer)
{
	if (correctAnswer)
	{
		cout << "You are correct!\n";
	}
	else
	{
		cout << "You are incorrect.\n";
		cout << "\nThe correct answer is:\n";
	}
}

// Name:   loadSettings(Settings& settings, ProblemType* problemTypes)
// Desc:   This function loads settings and problem type information
//         from a settings file.
// Input:  file as Ifstream
// Output: None
// Return: true on success or false on failure
bool loadSettings(Settings& settings, ProblemType* problemTypes)
{
	ifstream file;
	char text[MAX_STRING_LENGTH] = { '\0' };
	char errorMessage[45] = { '\0' };
	bool success = true;

	file.open("settings.txt");

	if (file)
	{
		file.getline(text, MAX_STRING_LENGTH, '\n');

		if (strncmp(text, "Settings", MAX_STRING_LENGTH) != 0)
		{
			strncpy_s(errorMessage, "ERROR: Invalid Settings File!",
				ERROR_MESSAGE_LENGTH);
			success = false;
		}

		file.getline(text, MAX_STRING_LENGTH, '=');
		if (strncmp(text, "firstNumDigits", MAX_STRING_LENGTH) == 0)
		{
			file >> settings.firstNumberDigits;
		}
		else
		{
			strncpy_s(errorMessage, "ERROR: Settings file has been corrupted!",
				ERROR_MESSAGE_LENGTH);
			success = false;
		}
		file.ignore(5, '\n');

		file.getline(text, MAX_STRING_LENGTH, '=');
		if (strncmp(text, "secondNumDigits", MAX_STRING_LENGTH) == 0)
		{
			file >> settings.secondNumberDigits;
		}
		else
		{
			strncpy_s(errorMessage, "ERROR: Settings file has been corrupted!",
				ERROR_MESSAGE_LENGTH);
			success = false;
		}
		file.ignore(5, '\n');

		file.getline(text, MAX_STRING_LENGTH, '=');
		if (strncmp(text, "subtractNegNumbers", MAX_STRING_LENGTH) == 0)
		{
			file.getline(text, MAX_STRING_LENGTH, '\n');

			if (_strnicmp(text, "true", MAX_STRING_LENGTH) == 0)
			{
				settings.allowNegative = true;
			}
			else if (_strnicmp(text, "false", MAX_STRING_LENGTH) == 0)
			{
				settings.allowNegative = false;
			}
			else
			{
				strncpy_s(errorMessage, "ERROR: subtractNegNumbers has invalid value!",
					ERROR_MESSAGE_LENGTH);
				success = false;
			}
		}
		else
		{
			strncpy_s(errorMessage, "ERROR: Settings file has been corrupted!",
				ERROR_MESSAGE_LENGTH);
			success = false;
		}

		file.getline(text, MAX_STRING_LENGTH, '=');
		if (strncmp(text, "addTitle", MAX_STRING_LENGTH) == 0)
		{
			file.getline(problemTypes[TYPE_ADDITION].title, TITLE_LENGTH, '\n');
		}
		else
		{
			strncpy_s(errorMessage, "ERROR: Settings file has been corrupted!",
				ERROR_MESSAGE_LENGTH);
			success = false;
		}
		file.getline(text, MAX_STRING_LENGTH, '=');
		if (strncmp(text, "addSymbol", MAX_STRING_LENGTH) == 0)
		{
			file >> problemTypes[TYPE_ADDITION].symbol;
		}
		else
		{
			strncpy_s(errorMessage, "ERROR: Settings file has been corrupted!",
				ERROR_MESSAGE_LENGTH);
			success = false;
		}
		file.ignore(5, '\n');

		file.getline(text, MAX_STRING_LENGTH, '=');
		if (strncmp(text, "subtractTitle", MAX_STRING_LENGTH) == 0)
		{
			file.getline(problemTypes[TYPE_SUBTRACTION].title, TITLE_LENGTH, '\n');
		}
		else
		{
			strncpy_s(errorMessage, "ERROR: Settings file has been corrupted!",
				ERROR_MESSAGE_LENGTH);
			success = false;
		}
		file.getline(text, MAX_STRING_LENGTH, '=');
		if (strncmp(text, "subtractSymbol", MAX_STRING_LENGTH) == 0)
		{
			file >> problemTypes[TYPE_SUBTRACTION].symbol;
		}
		else
		{
			strncpy_s(errorMessage, "ERROR: Settings file has been corrupted!",
				ERROR_MESSAGE_LENGTH);
			success = false;
		}
		file.ignore(5, '\n');

		file.getline(text, MAX_STRING_LENGTH, '=');
		if (strncmp(text, "multiplyTitle", MAX_STRING_LENGTH) == 0)
		{
			file.getline(problemTypes[TYPE_MULTIPLICATION].title, TITLE_LENGTH, '\n');
		}
		else
		{
			strncpy_s(errorMessage, "ERROR: Settings file has been corrupted!",
				ERROR_MESSAGE_LENGTH);
			success = false;
		}
		file.getline(text, MAX_STRING_LENGTH, '=');
		if (strncmp(text, "multiplySymbol", MAX_STRING_LENGTH) == 0)
		{
			file >> problemTypes[TYPE_MULTIPLICATION].symbol;
		}
		else
		{
			strncpy_s(errorMessage, "ERROR: Settings file has been corrupted!",
				ERROR_MESSAGE_LENGTH);
			success = false;
		}
		file.ignore(5, '\n');

		file.getline(text, MAX_STRING_LENGTH, '=');
		if (strncmp(text, "divisionTitle", MAX_STRING_LENGTH) == 0)
		{
			file.getline(problemTypes[TYPE_DIVISION].title, TITLE_LENGTH, '\n');
		}
		else
		{
			strncpy_s(errorMessage, "ERROR: Settings file has been corrupted!",
				ERROR_MESSAGE_LENGTH);
			success = false;
		}
		file.getline(text, MAX_STRING_LENGTH, '=');
		if (strncmp(text, "divisionSymbol", MAX_STRING_LENGTH) == 0)
		{
			file >> problemTypes[TYPE_DIVISION].symbol;
		}
		else
		{
			strncpy_s(errorMessage, "ERROR: Settings file has been corrupted!",
				ERROR_MESSAGE_LENGTH);
			success = false;
		}
		file.ignore(5, '\n');

		file.close();
	}
	else
	{
		strncpy_s(errorMessage, "ERROR: Could not load settings file!",
			ERROR_MESSAGE_LENGTH);
		success = false;
	}

	if (!success)
	{
		cout << errorMessage << endl;
		cout << "A new file has been created. Please run the program again." << endl;
		createDefaultSaveFile();
	}

	return success;
}

// Name:   saveSettings(Settings& settings, ProblemType* problemTypes)
// Desc:   This function saves settings and problem type information
//         to a settings file.
// Input:  None
// Output: file as Ofstream
// Return: None
void saveSettings(Settings& settings, ProblemType* problemTypes)
{
	ofstream file;
	char firstNumDigits[MAX_STRING_LENGTH] = "firstNumDigits=";
	char secondNumDigits[MAX_STRING_LENGTH] = "secondNumDigits=";
	char subtractNegNumbers[MAX_STRING_LENGTH] = "subtractNegNumbers=";
	char addTitle[MAX_STRING_LENGTH] = "addTitle=";
	char addSymbol[MAX_STRING_LENGTH] = "addSymbol=";
	char subtractTitle[MAX_STRING_LENGTH] = "subtractTitle=";
	char subtractSymbol[MAX_STRING_LENGTH] = "subtractSymbol=";
	char multiplyTitle[MAX_STRING_LENGTH] = "multiplyTitle=";
	char multiplySymbol[MAX_STRING_LENGTH] = "multiplySymbol=";
	char divisionTitle[MAX_STRING_LENGTH] = "divisionTitle=";
	char divisionSymbol[MAX_STRING_LENGTH] = "divisionSymbol=";

	char firstNumber[5] = { '\0' };
	char secondNumber[5] = { '\0' };

	_itoa_s(settings.firstNumberDigits, firstNumber, 10);
	_itoa_s(settings.secondNumberDigits, secondNumber, 10);

	strncat_s(firstNumDigits, firstNumber, MAX_STRING_LENGTH);
	strncat_s(secondNumDigits, secondNumber, MAX_STRING_LENGTH);

	// Just going to overwrite the file since it is so small
	file.open("settings.txt");
	if (file)
	{
		file.write("Settings", 8);
		file.put('\n');
		file.write(firstNumDigits, strlen(firstNumDigits));
		file.put('\n');
		file.write(secondNumDigits, strlen(secondNumDigits));
		file.put('\n');
		file.write(subtractNegNumbers, strlen(subtractNegNumbers));
		if (settings.allowNegative)
		{
			file.write("true", 4);
		}
		else
		{
			file.write("false", 5);
		}
		file.put('\n');
		file.write(addTitle, strlen(addTitle));
		file.write(problemTypes[TYPE_ADDITION].title, strlen(problemTypes[TYPE_ADDITION].title));
		file.put('\n');
		file.write(addSymbol, strlen(addSymbol));
		file.put(problemTypes[TYPE_ADDITION].symbol);
		file.put('\n');
		file.write(subtractTitle, strlen(subtractTitle));
		file.write(problemTypes[TYPE_SUBTRACTION].title, strlen(problemTypes[TYPE_SUBTRACTION].title));
		file.put('\n');
		file.write(subtractSymbol, strlen(subtractSymbol));
		file.put(problemTypes[TYPE_SUBTRACTION].symbol);
		file.put('\n');
		file.write(multiplyTitle, strlen(multiplyTitle));
		file.write(problemTypes[TYPE_MULTIPLICATION].title, strlen(problemTypes[TYPE_MULTIPLICATION].title));
		file.put('\n');
		file.write(multiplySymbol, strlen(multiplySymbol));
		file.put(problemTypes[TYPE_MULTIPLICATION].symbol);
		file.put('\n');
		file.write(divisionTitle, strlen(divisionTitle));
		file.write(problemTypes[TYPE_DIVISION].title, strlen(problemTypes[TYPE_DIVISION].title));
		file.put('\n');
		file.write(divisionSymbol, strlen(divisionSymbol));
		file.put(problemTypes[TYPE_DIVISION].symbol);
		file.put('\n');

		file.close();
	}
}

// Name:   createDefaultSaveFile()
// Desc:   This function creates a default save file in case
//         something is wrong with the original.
// Input:  None
// Output: None
// Return: None
void createDefaultSaveFile()
{
	Settings settings = { 0 };
	ProblemType problemTypes[NUMBER_OF_TYPES] = { 0 };

	settings.firstNumberDigits = 2;
	settings.secondNumberDigits = 1;
	settings.allowNegative = false;

	strncpy_s(problemTypes[TYPE_ADDITION].title, "Addition", TITLE_LENGTH);
	problemTypes[TYPE_ADDITION].symbol = '+';
	strncpy_s(problemTypes[TYPE_SUBTRACTION].title, "Subtraction", TITLE_LENGTH);
	problemTypes[TYPE_SUBTRACTION].symbol = '-';
	strncpy_s(problemTypes[TYPE_MULTIPLICATION].title, "Multiplication",
		TITLE_LENGTH);
	problemTypes[TYPE_MULTIPLICATION].symbol = 'x';
	strncpy_s(problemTypes[TYPE_DIVISION].title, "Division", TITLE_LENGTH);
	problemTypes[TYPE_DIVISION].symbol = '/';

	saveSettings(settings, problemTypes);
}
