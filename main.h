#pragma once

/*****************************************************************************
# Author:      Patrick Foster
# Assignment:  Final Project
# Date:        2/28/2023
# Description: Main header file.
#
# Input:       None
#
# Output:      None
#
# Sources:     Final Project Specifications
#****************************************************************************/

// Constants for menu choices
const int MENU_MAIN = 0;
const int MENU_ADDITION = 1;
const int MENU_SUBTRACTION = 2;
const int MENU_MULTIPLICAITON = 3;
const int MENU_DIVISION = 4;
const int MENU_SETTINGS = 9;

// Constant for max number of problem types
const int NUMBER_OF_TYPES = 4;

// Constants for problemTypes array of structures index
const int TYPE_ADDITION = 0;
const int TYPE_SUBTRACTION = 1;
const int TYPE_MULTIPLICATION = 2;
const int TYPE_DIVISION = 3;

// Constants for c-string sizes
const int MAX_STRING_LENGTH = 20;
const int ERROR_MESSAGE_LENGTH = 45;
const int TITLE_LENGTH = 15;

// Structure for program settings
struct Settings
{
	int firstNumberDigits;
	int secondNumberDigits;
	bool allowNegative;
};

// Structure for problem types
struct ProblemType
{
	char title[TITLE_LENGTH];
	char symbol;
};
