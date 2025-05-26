
// avA4_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Name : Adhiti Venkatesh
// Summary : Assignment 4 problem 2
// This program calculates hospital charges and outputs a report to file.
// The most difficult aspect is working out functions and file output.
// It took about 22 hours to write the code
// 10/29/2023 Revision 1.0  Initial version
// 10/30/2023 Revision 1.1  Worked on functions
// 10/31/2023 Revision 1.2  Worked on functions
// 11/01/2023 Revision 1.3  Worked on functions
// 11/02/2023 Revision 1.4  Worked on validations
// 11/03/2023 Revision 1.5  Worked on output file
// 11/04/2023 Revision 1.6  Worked on output file
// 11/05/2023 Revision 1.7  Bug Fixes


#include <iostream>
#include <iomanip> 
#include <cmath>
#include <string> //string
#include <fstream> //file header
using namespace std;

// function prototypes
double patientCharges(int, double, double, double);
double patientCharges(double, double);
void outputChargesReport(int, double, double, double);
void outputChargesReport(double, double);
double validateData(double, string);
double validateData(int, string);

int main()
{
	// declaring variables

	char patientInd;
	int daysSpent;
	double serviceCharges, medicationCharges, dailyRate;

	std::cout.setf(ios::fixed); // set fixed format for output
	std::cout.setf(ios::showpoint); // show decimal point and trailing zeros in output
	std::cout.precision(2); // set precision to 2


	cout << "This program will compute patient hospital charges." << endl;
	
	do //Get in-patient or Out-patient indicator. Try to validate until user enters correct indicator
	{
		cout << "Enter I for in-patient or O for out-patient: ";
		cin >> patientInd;
		cout << patientInd << endl;
	} while ((patientInd !='i' && patientInd != 'I' )&& (patientInd != 'o' && patientInd != 'O'));

	if (patientInd == 'i' || patientInd == 'I')
	{ //If In-patient; get 4 values
		do
		{
			cout << "Number of days in the hospital: ";
			cin >> daysSpent;	
		} while (validateData(daysSpent, "Days spent should be greater than zero.") <0);

		do
		{
			cout << "Daily Room Rate: ";
			cin >> dailyRate;
		} while (validateData(dailyRate, "Daily Room Rate should be greater than zero.") < 0);


		do
		{
			cout << "Lab fees and other service charges: ";
			cin >> serviceCharges;
		} while (validateData(serviceCharges, "Lab fees and other service charges should be greater than zero.") < 0);


		do
		{
			cout << "Medication charges: ";
			cin >> medicationCharges;
		} while (validateData(medicationCharges, "Medication charges should be greater than zero.") < 0);

		//Call function to generate output report.  
		//This function also calls a sub-function to get total charges
		outputChargesReport(daysSpent, dailyRate, serviceCharges, medicationCharges);
	}
	else // Out-patient 
	{

		do
		{
			cout << "Lab fees and other service charges: ";
			cin >> serviceCharges;
		} while (validateData(serviceCharges, "Lab fees and other service charges should be greater than zero.") < 0);


		do
		{
			cout << "Medication charges: ";
			cin >> medicationCharges;
		} while (validateData(medicationCharges, "Medication charges should be greater than zero.") < 0);

		//Call function to generate output report.  
		//This function also calls a sub-function to get total charges

		outputChargesReport(serviceCharges, medicationCharges);
	}
	return 0; //no return
}

double patientCharges(int daysSpent, double dailyRate, double serviceCharges, double medicationCharges)
{
//returns total charges for inpatient.  Overloaded function
	return (daysSpent*dailyRate)+serviceCharges+medicationCharges;
}


double patientCharges(double serviceCharges, double medicationCharges)
{
//returns total charges for outpatient. Overloaded function
	return serviceCharges+medicationCharges;
}

void outputChargesReport(int daysSpent, double dailyRate, double serviceCharges, double medicationCharges)
{

	std::cout.setf(ios::fixed); // set fixed format for output
	std::cout.setf(ios::showpoint); // show decimal point and trailing zeros in output
	std::cout.precision(2); // set precision to 2

	double totalCharges;
	ofstream outputFile;  // File stream object

	totalCharges = patientCharges(daysSpent, dailyRate, serviceCharges, medicationCharges);

	//open file Numbers.txt
	outputFile.open("Hospital.txt");

	if (outputFile) //No error opening file
	{
		outputFile << "*****************************************" << endl;
		outputFile << "Hospital Billing Statement" << endl;
		outputFile << "*****************************************" << endl;
		outputFile << "Room charges \t\t$" << std::setw(12) << daysSpent * dailyRate << endl;
		outputFile << "Lab & Services \t\t$" << std::setw(12) << serviceCharges << endl;
		outputFile << "Medication \t\t$" << std::setw(12) << medicationCharges << endl;
		outputFile << "Total charges \t\t$" << std::setw(12) << totalCharges << endl;
		outputFile << "*****************************************" << endl;

		// Close the file.
		outputFile.close();
		cout << "The billing report has been written to hospital.txt file.";
	}
	else //error opening the file
	{
		cout << "There is an error opening the file hospital.txt.";
	}

	/*
	cout << "Room charges \t\t$" << std::setw(12)  << daysSpent * dailyRate << endl;
	cout << "Lab & Services \t\t$" << std::setw(12)  << serviceCharges << endl;
	cout << "Medication \t\t$" << std::setw(12)  << medicationCharges << endl;
	cout << "Total charges \t\t$" << std::setw(12)  << totalCharges << endl;
*/

}

void outputChargesReport(double serviceCharges, double medicationCharges)
{
	std::cout.setf(ios::fixed); // set fixed format for output
	std::cout.setf(ios::showpoint); // show decimal point and trailing zeros in output
	std::cout.precision(2); // set precision to 2


	double totalCharges;
	ofstream outputFile;  // File stream object

	totalCharges = patientCharges(serviceCharges, medicationCharges);

	//open file Numbers.txt
	outputFile.open("Hospital.txt");
	if (outputFile) // no error opening the file
	{
		outputFile << "*****************************************" << endl;
		outputFile << "Hospital Billing Statement" << endl;
		outputFile << "*****************************************" << endl;
		outputFile << "Lab & Services \t\t$" << std::setw(12) << serviceCharges << endl;
		outputFile << "Medication \t\t$" << std::setw(12) << medicationCharges << endl;
		outputFile << "Total charges \t\t$" << std::setw(12) << totalCharges << endl;
		outputFile << "*****************************************" << endl;

		// Close the file.
		outputFile.close();
		cout << "The billing report has been written to hospital.txt file.";
	}
	else //error opening file
	{
		cout << "There is an error opening the file hospital.txt.";
	}
	/*
	cout << "Lab & Services \t\t$" << std::setw(12)  << serviceCharges << endl;
	cout << "Medication \t\t$" << std::setw(12)  << medicationCharges << endl;
	cout << "Total charges \t\t$" << std::setw(12)  << totalCharges << endl;
	*/

}


double validateData(double variableValue, string outputMessage)
{ //validate and ensure number greater than zero.
	if (variableValue <= 0)
	{
		cout << outputMessage << endl;
		return -1; // error code
	}
	else
		return 0;
}

double validateData(int variableValue, string outputMessage)
{ //validate and ensure number greater than 0. overloaded function
	if (variableValue <= 0)
	{
		cout << outputMessage << endl;
		return -1;// error code
	}
	else
		return 0;
}
