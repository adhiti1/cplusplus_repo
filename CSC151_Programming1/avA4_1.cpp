
// avA4_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Name : Adhiti Venkatesh
// Summary : Assignment 4 problem 1
// This program gets numbers as input and saves it into a file.  It then reads the file
// and then does numeric processing.
// The most difficult aspect is file processing.
// It took about 12 hours to write the code
// 10/24/2023 Revision 1.0  Initial version
// 10/25/2023 Revision 1.1  Worked through the menu selection and formula
// 10/26/2023 Revision 1.2  Worked on Validation
// 10/27/2023 Revision 1.3  Worked on output section


#include <iostream>
#include <iomanip> 
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ofstream outputFile;  // File stream object
	int inputNumber,totalNumbers;     // individual number and count of numbers
	int outputNumber;
	double sumOfNumbers=0;
	string inputFileName; //file name
	ifstream inputFile; //input file stream

	cout.setf(ios::fixed); // set fixed format for output
	cout.setf(ios::showpoint); // show decimal point and trailing zeros in output
	cout.precision(2); // set precision to 2


	//Get the count of numbers
	cout << "For how many numbers do you want to enter? ";
	cin >> totalNumbers;

	//open file Numbers.txt
	outputFile.open("Numbers.txt");
	// Get the numbers and write it to file
	for (int count = 1; count <= totalNumbers; count++)
	{
		// Get number from user.
		cout << "Enter number " << count << ": ";
		cin >> inputNumber;

		// Write number to the file.
		outputFile << inputNumber << endl;
	}

	// Close the file.
	outputFile.close();
	cout << "Data written to Numbers.txt\n";
	cout << "------------The End for entering data---------\n\n";

	//reading file and performing numeric calculations

	totalNumbers = 0;

	cout << "Enter the filename: ";
	cin >> inputFileName; //get file name

	inputFile.open(inputFileName); //open file
	if (inputFile) //if there are no errors
	{
		cout << "The data from the file " << inputFileName << " are -\n";
		while (inputFile >> outputNumber) { //read file line by line
			cout << outputNumber << endl; //output the number
			sumOfNumbers = sumOfNumbers + outputNumber; //add it to sum
			totalNumbers++; //increment cout of numbers read
		}

		// Close the file.
		inputFile.close();

		//Print details of numbers

		cout << "Number of numbers:\t\t" << totalNumbers << endl;
		cout << "Sum of numbers:\t\t\t" << sumOfNumbers << endl;
		cout << "Average of the numbers:\t\t" << sumOfNumbers / totalNumbers << endl;
	}
	else //error opening file
	{
		// Display an error message.
		cout << "Error opening the file - " << inputFileName << endl;
	}

	return 0; //no return
} //end of program