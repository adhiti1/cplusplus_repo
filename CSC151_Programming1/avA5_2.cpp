
// avA5_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Name : Adhiti Venkatesh
// Summary : Assignment 5 problem 2
// This program reads a file and performs number analysis
// This program uses an array to read in the file and performs basic math analysis
// It took about 24 hours to write the code
// 11/21/2023 Revision 1.0  Initial version
// 11/22/2023 Revision 1.1  Worked on file input
// 11/23/2023 Revision 1.2  Worked on functions
// 11/25/2023 Revision 1.3  Worked on functions
// 11/26/2023 Revision 1.4  Worked on functions
// 11/27/2023 Revision 1.5  Worked on validations
// 11/28/2023 Revision 1.6  Bug Fixes


#include <iostream>
#include <iomanip> 
#include <cmath>
#include <string> //string
#include <array> //array related functions
#include <fstream> //file related functions


using namespace std;

// function prototypes
double	sumArray(const double[], int);  //calculates sum of numbers stored in array
double	getHighest(const double[], int); //finds highest number in array
double	getLowest(const double[], int); //finds lowest number in array
void outputArray(const double[], int, string); //outputs contents of array

int main()
{
	// declaring variables

	const int MAX = 1000; //max number of array elements
	double arrayNum[MAX]; //array of numbers
	int arrayLength =0; // length of array
	double inputNumber; //number from file input
	string inputFileName; //file name
	ifstream inputFile; //input file stream

	double minNumber, MaxNumber, SumNumbers;


	std::cout.setf(ios::fixed); // set fixed format for output
	std::cout.setf(ios::showpoint); // show decimal point and trailing zeros in output
	std::cout.precision(2); // set precision to 2

	cout << "Please enter the name of file that contains series of numbers: ";
	cin >> inputFileName; //get file name
	inputFile.open(inputFileName); //open file
	if (inputFile) //if there are no errors
	{
		while (inputFile >> inputNumber) { //read file line by line
			//cout << inputNumber << endl; //output the number
			arrayNum[arrayLength] = inputNumber;
			arrayLength++; //increment cout of numbers read
		}

		// Close the file.
		inputFile.close();

		outputArray(arrayNum, arrayLength,inputFileName);

		SumNumbers = sumArray(arrayNum, arrayLength);
		minNumber = getLowest(arrayNum, arrayLength);
		MaxNumber = getHighest(arrayNum, arrayLength);

		cout << "The file has " << arrayLength << " numbers." << endl;
		cout << "The highest value is " << MaxNumber << endl;
		cout << "The lowest value is " << minNumber << endl;
		cout << "The sum of the numbers is " << SumNumbers << endl;
		cout << "The average of the numbers is " << SumNumbers / arrayLength << endl;
	}
	else //error opening file
	{
		// Display an error message.
		cout << "Error opening the file - " << inputFileName << endl;
	}

	
	return 0; //no return
}

//output contents of array
void outputArray(const double arrayNum[], int arrayLength, string fileName)
{
	cout << "The contents of " << fileName << " is:" << endl;
	for (int count = 0; count < arrayLength; count++)
		cout << arrayNum[count]<<endl;
	cout << endl;
}

//find sum of elements in array
double	sumArray(const double arrayNum[], int arrayLength)
{
	double total = 0.0; //initializing it as a double
	for (int count = 0; count < arrayLength; count++)
		total += arrayNum[count];
	return total;

}

//find highest element in array
double	getHighest(const double arrayNum[], int arrayLength)
{
	double highest = arrayNum[0]; //initialize first element as highest and then do comparison
	for (int count = 1; count < arrayLength; count++) //start from 2nd element
	{
		if (arrayNum[count] > highest)
			highest = arrayNum[count];
	}
	return highest;
}

//find lowest element in array
double	getLowest(const double arrayNum[], int arrayLength)
{

	double lowest = arrayNum[0]; //intiialize first element as lowest 
	for (int count = 1; count < arrayLength; count++) //start from 2nd element
	{
		if (arrayNum[count] < lowest)
			lowest = arrayNum[count];
	}
	return lowest;

}
