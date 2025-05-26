
// avA5_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Name : Adhiti Venkatesh
// Summary : Assignment 5 problem 1
// This program lets user play the game of Rock, Paper, Scissors against the computer
// Computer picks rock or paper or scissors using random number and plays against user
// It took about 18 hours to write the code
// 11/16/2023 Revision 1.0  Initial version
// 11/17/2023 Revision 1.1  Worked on random function
// 11/18/2023 Revision 1.2  Worked on functions
// 11/19/2023 Revision 1.3  Worked on functions
// 11/20/2023 Revision 1.4  Worked on functions
// 11/21/2023 Revision 1.5  Worked on validations
// 11/22/2023 Revision 1.6  Bug Fixes


#include <iostream>
#include <iomanip> 
#include <cmath>
#include <string>			  //string
#include <cstdlib>            // Needed to use rand() and srand()
#include <ctime>              // Needed for system to "seed" the random number generator

using namespace std;

// function prototypes
int getComputerChoice();
void showMenu();
int getMenuChoice();
int playGame(int, int);

int main()
{
	// declaring variables

	int menuchoice, userChoice,computerChoice, gameResult;

	std::cout.setf(ios::fixed); // set fixed format for output
	std::cout.setf(ios::showpoint); // show decimal point and trailing zeros in output
	std::cout.precision(2); // set precision to 2

	do
	{
		computerChoice = getComputerChoice(); //get computer choice before getting user choice
		showMenu();//call showMenu() function
		userChoice = getMenuChoice();
		if (userChoice != 4)//if user does not want to quit, proceed
			gameResult = playGame(userChoice, computerChoice); //play the game
		

	} while (userChoice != 4); //until user quits

	return 0; //no return
}

int getComputerChoice()
{
	const int MAX_NUM = 3;    // To allow numbers between 1 and 3

	unsigned seed;            // Seed for the random number generator
	seed = time(0);           // Assigns a system-generated seed 

	srand(seed);			  // select a random choice

	// return random choice
	return(1 + rand() % MAX_NUM);

}


void showMenu() //shows menu
{

	cout << "\nGame Menu" << endl;
	cout << "---------\n" << endl;

	cout << "1) Rock\n";
	cout << "2) Paper\n";
	cout << "3) Scissors\n";
	cout << "4) Quit\n";
	cout << "Enter your choice: ";
}


int getMenuChoice() //Get choice from menu
{
	int choice;
	cin >> choice; //gets user input
	while (choice < 1 || choice > 4)  //loop until you get a valid choice.
	{
		cout << " The valid choices are 1-4." << "\n Please re-enter: ";
		cin >> choice;
	}
	cout << endl;
	return choice;
}

int playGame (int userChoice, int computerChoice)
{


	switch (userChoice) //output user choice
	{
	case 1:
		cout << "You Selected: Rock" << endl;
		break;
	case 2:
		cout << "You Selected: Paper" << endl;
		break;
	case 3:
		cout << "You Selected: Scissors" << endl;
	}

	switch (computerChoice) //output computer choice
	{
	case 1:
		cout << "Computer Selected: Rock" << endl;
		break;
	case 2:
		cout << "Computer Selected: Paper" << endl;
		break;
	case 3:
		cout << "Computer Selected: Scissors" << endl;
	}

	//for each user choice find out who is the winner based on computer choice

	if (computerChoice == userChoice) //tie game
		cout << "Tie. No Winner." << endl;
	else if (userChoice == 1) //user pick is rock
	{
		switch (computerChoice)
		{
		case 2: //computer pick is paper
			cout << "Computer Wins! Paper wraps Rock." << endl;
			break;
		case 3: //computer pick is scissors
			cout << "You win! Rock smashes Scissors." << endl;
		}
	}
	else if (userChoice == 2) //user pick is Paper
	{
		switch (computerChoice)
		{
		case 1: //computer pick is Rock
			cout << "You Win! Paper wraps Rock." << endl;
			break;
		case 3: //computer pick is scissors
			cout << "Computer wins! Scissors cuts Paper." << endl;
		}
	}
	else // user pick is 3 (Scissors)
	{
		switch (computerChoice)
		{
		case 1: //computer pick is Rock
			cout << "Computer Wins! Rock smashes Scissors." << endl;
			break;
		case 2: //computer pick is Paper
			cout << "You win! Scissors cuts Paper." << endl;
		}
	}
	return 0;
}
