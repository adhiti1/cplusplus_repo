
// avA1_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Name : Adhiti Venkatesh
// Summary : Assignment 1 problem 2
// This code is meant to compute monthly payment on a loan
// It takes loan amount, annual interest rate, and number of monthly payments as input. 
// The most difficult aspect is working out the formula, printing output, and learning syntax
// It took about 4 hours to write the code
// 09/16/2023 Revision 1.0  Initial version
// 09/17/2023 Revision 1.1  Worked through formula by splitting it up
// 09/19/2023 Revision 1.2  Worked on output section
// 09/22/2013 Revision 1.3  Added comments and organized the code

#include <iostream>
#include <iomanip> 
#include <cmath>
using namespace std;

int main()
{
	// declaring variables

	double loan_amount, interest_rate, monthly_payment, total, monthly_interest_rate, total_interest;

	double powerpart;
	int number_of_months;

	// get inputs
	cout << "Loan amount: $";
	cin >> loan_amount;
	cout << "Annual interest rate (in the format .12 (for 12%): ";
	cin >> interest_rate;
	cout << "Number of monthly payments to be made: ";
	cin >> number_of_months;
	cout << endl;

	// compute monthly interest rate
	monthly_interest_rate = interest_rate / 12.0; 

	// calculate value of power function. this simplifies code of final formula
	powerpart = pow((1 + monthly_interest_rate), number_of_months);

	//calculate monthly payment
	monthly_payment = loan_amount* monthly_interest_rate * powerpart
									/ 
									(powerpart - 1);
	total = monthly_payment * number_of_months; //total payment
	
	total_interest = total - loan_amount; // total interest 
	
	
	cout.setf(ios::fixed); // set fixed format for output
	cout.setf(ios::showpoint); // show decimal point and trailing zeros in output
	cout.precision(2); // set precision to 2
	
	cout << endl;
	cout << " - - Loan Report - -";
	cout << endl;
	cout << endl;

	// \t puts a tab in the output
	cout << "Loan Amount:\t\t\t$" << std::setw(12) << loan_amount; //setw function sets output width
	
	cout << endl;

	//print monthly interest rate as a percent by multiplying by 100
	cout << "Monthly Interest Rate:\t\t" << std::setw(12) << monthly_interest_rate * 100 << "%";
	cout << endl;
	cout.precision(0);
	cout << "Number of Payments:\t\t" << std::setw(13) << number_of_months;
	cout << endl;
	cout.precision(2);
	cout << "Monthly Payments:\t\t$" << std::setw(12)<<  monthly_payment;
	cout << endl;
	cout << "Amount Paid Back:\t\t$" << std::setw(12)<< total;
	cout << endl;
	cout << "Interest Paid:\t\t\t$" << std::setw(12)<< total_interest;
	cout << endl;

	return 0; //no return
} //end of program