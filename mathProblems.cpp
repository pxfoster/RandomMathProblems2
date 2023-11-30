#include "main.h"
#include "mathProblems.h"
#include "inputOutput.h"

/*****************************************************************************
# Author:      Patrick Foster
# Assignment:  Final Project
# Date:        2/28/2023
# Description: This file takes care of the creation of a math problem and
#              checking answers to see if they are correct.
#
# Input:       None
#
# Output:      None
#
# Sources:     Final Project Specifications
#****************************************************************************/

// Name:   createMathProblem(const Settings& settings, const ProblemType& problemType)
// Desc:   This function creates a math problem based on the settings and problem
//         type passed in.
// Input:  None
// Output: None
// Return: None
void createMathProblem(const Settings& settings, const ProblemType& currentType)
{
	int numbers[4] = { 0 };

	//Set up the problem
	numbers[FIRST_NUMBER] = setupRandomNumber(settings.firstNumberDigits);
	numbers[SECOND_NUMBER] = setupRandomNumber(settings.secondNumberDigits);
	numbers[CORRECT_ANSWER] = 0;
	numbers[USER_ANSWER] = 0;

	// Keeping larger numbers on top
	if (!settings.allowNegative && numbers[SECOND_NUMBER] > numbers[FIRST_NUMBER])
	{
		int tempValue = numbers[FIRST_NUMBER];
		numbers[FIRST_NUMBER] = numbers[SECOND_NUMBER];
		numbers[SECOND_NUMBER] = tempValue;
	}

	if (strncmp(currentType.title, "Addition", strlen(currentType.title)) == 0)
	{
		numbers[CORRECT_ANSWER] = numbers[FIRST_NUMBER] + numbers[SECOND_NUMBER];
	}
	else if (strncmp(currentType.title, "Subtraction", strlen(currentType.title)) == 0)
	{
		numbers[CORRECT_ANSWER] = numbers[FIRST_NUMBER] - numbers[SECOND_NUMBER];
	}
	else if (strncmp(currentType.title, "Multiplication", strlen(currentType.title)) == 0)
	{
		numbers[CORRECT_ANSWER] = numbers[FIRST_NUMBER] * numbers[SECOND_NUMBER];
	}
	else if (strncmp(currentType.title, "Division", strlen(currentType.title)) == 0)
	{
		numbers[CORRECT_ANSWER] = numbers[FIRST_NUMBER] / numbers[SECOND_NUMBER];

		// Make the first number evenly divisable
		numbers[FIRST_NUMBER] = numbers[CORRECT_ANSWER] * numbers[SECOND_NUMBER];
	}

	showTitle(currentType.title);
	displayProblem(numbers, currentType.symbol, false);
	numbers[USER_ANSWER] = getIntAnswer();
	addFill('!', 20, 0);
	checkAnswer(numbers);
	displayProblem(numbers, currentType.symbol, true);
	addFill('!', 20, 0);
}

// Name:   setupRandomNumber(int numDigits)
// Desc:   This function creates a random number based on the number
//         of digits passed in.
// Input:  None
// Output: None
// Return: number as Integer
int setupRandomNumber(int numDigits)
{
	int maxRandom = 0;
	int number = 0;

	for (int i = 0; i < numDigits; i++)
	{
		if (i != 0)
		{
			maxRandom *= 10;
		}

		maxRandom++;
	}

	maxRandom *= 9;

	// Adding 1 so zero isn't used
	number = (rand() % maxRandom) + 1;

	return number;
}

// Name:   checkAnswer(const int* numbers)
// Desc:   This function checks to see if an answer is correct
//         or wrong.
// Input:  None
// Output: None
// Return: None
void checkAnswer(const int* numbers)
{
	if (numbers[USER_ANSWER] == numbers[CORRECT_ANSWER])
	{
		displayCorrectMessage(true);
	}
	else
	{
		displayCorrectMessage(false);
	}
}
