#pragma once

#include "main.h"

/*****************************************************************************
# Author:      Patrick Foster
# Assignment:  Final Project
# Date:        2/28/2023
# Description: Input/Output header file.
#
# Input:       None
#
# Output:      None
#
# Sources:     Final Project Specifications
#****************************************************************************/

// Function Prototypes
char getMenuInput();
int getIntAnswer();
bool playAgainMessage();
int showSettings(Settings& settings, ProblemType* problemTypes);

void welcome();
void goodbye();
void showMenu();
void showTitle(const char* titleName);
void addFill(const char fillChar, int fillAmount, int spacesBefore = 0);
void addSpaces(int numSpaces);
void displayProblem(const int* numbers, char symbol, bool showAnswer);
int getNumDigits(int number);
void displayCorrectMessage(bool correctAnswer);
bool loadSettings(Settings& settings, ProblemType* problemTypes);
void saveSettings(Settings& settings, ProblemType* problemTypes);
void createDefaultSaveFile();
