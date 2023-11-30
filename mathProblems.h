#pragma once

#include <random>

/*****************************************************************************
# Author:      Patrick Foster
# Assignment:  Final Project
# Date:        2/28/2023
# Description: Math problems header file.
#
# Input:       None
#
# Output:      None
#
# Sources:     Final Project Specifications
#****************************************************************************/

// Constants for numbers array index
const int FIRST_NUMBER = 0;
const int SECOND_NUMBER = 1;
const int CORRECT_ANSWER = 2;
const int USER_ANSWER = 3;

// Function Prototypes
void createMathProblem(const Settings& settings, const ProblemType& currentType);
int setupRandomNumber(int numDigits);
void checkAnswer(const int* numbers);
