#include "main.h"
#include "inputOutput.h"
#include "mathProblems.h"

/*****************************************************************************
# Author:      Patrick Foster
# Assignment:  Final Project
# Date:        2/28/2023
# Description: This is the main entry point for the program.
#
# Input:       None
#
# Output:      None
#
# Sources:     Final Project Specifications
#****************************************************************************/

// Main Function
int main()
{
	bool playing = true;
	bool menuChoiceValid = false;
	int currentState = MENU_MAIN;
	char userChoice = '\0';
	Settings settings = { 0 };
	ProblemType problemTypes[NUMBER_OF_TYPES] = { 0 };

	srand((unsigned int)time(0));

	welcome();

	playing = loadSettings(settings, problemTypes);

	while (playing)
	{
		switch (currentState)
		{
			case MENU_MAIN:
				menuChoiceValid = false;
				userChoice = '\0';
				showMenu();
				while (!menuChoiceValid)
				{
					userChoice = getMenuInput();

					if (userChoice == '0')
					{
						playing = false;
						menuChoiceValid = true;
					}
					else if (userChoice == '1')
					{
						currentState = MENU_ADDITION;
						menuChoiceValid = true;
					}
					else if (userChoice == '2')
					{
						currentState = MENU_SUBTRACTION;
						menuChoiceValid = true;
					}
					else if (userChoice == '3')
					{
						currentState = MENU_MULTIPLICAITON;
						menuChoiceValid = true;
					}
					else if (userChoice == '4')
					{
						currentState = MENU_DIVISION;
						menuChoiceValid = true;
					}
					else if (userChoice == '9')
					{
						currentState = MENU_SETTINGS;
						menuChoiceValid = true;
					}
				}
				break;

			case MENU_ADDITION:
				createMathProblem(settings, problemTypes[TYPE_ADDITION]);
				if (!playAgainMessage())
				{
					currentState = MENU_MAIN;
				}
				break;

			case MENU_SUBTRACTION:
				createMathProblem(settings, problemTypes[TYPE_SUBTRACTION]);
				if (!playAgainMessage())
				{
					currentState = MENU_MAIN;
				}
				break;

			case MENU_MULTIPLICAITON:
				createMathProblem(settings, problemTypes[TYPE_MULTIPLICATION]);
				if (!playAgainMessage())
				{
					currentState = MENU_MAIN;
				}
				break;

			case MENU_DIVISION:
				createMathProblem(settings, problemTypes[TYPE_DIVISION]);
				if (!playAgainMessage())
				{
					currentState = MENU_MAIN;
				}
				break;

			case MENU_SETTINGS:
				currentState = showSettings(settings, problemTypes);
				break;

			default:
				break;
		}
	}

	goodbye();

	return 0;
}
