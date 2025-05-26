
// avA3_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Name : Adhiti Venkatesh
// Summary : Assignment 3 problem 2
// This program computes interest on savings account balance on a monthly basis for 3 months
// It takes starting balance, annual interest rate as inputs.
// For each month it takes deposits and withdrawals as inputs. 
// It outputs monthly interest and ending balance on a monthly basis
// It also generates Quarterly savings account statement
// The most difficult aspect is working out inputs, outputs, monthly calculations,
//  and finding duration of program execution
// It took about 24 hours to write the code
// 10/14/2023 Revision 1.0  Initial version
// 10/15/2023 Revision 1.1  Version to capture input until validated
// 10/16/2023 Revision 1.2  Worked on output section
// 10/17/2013 Revision 1.3  fixed issues with inputs
// 10/18/2013 Revision 1.4  Worked on Quarterly savings account statement
// 10/19/2013 Revision 1.5  Worked on fixing bugs
// 10/20/2013 Revision 1.6  Worked on fixing bugs
// 10/21/2013 Revision 1.7  Finding duration of program execution so we can output the duration. 

#include <iostream>
#include <iomanip> 
#include <cmath>
#include <chrono> //header for calculating time and duration of execution
using namespace std;

int main()
{
	// Record start time.  Needed so that we can output time taken to run program.
	auto start = std::chrono::high_resolution_clock::now();

	// declaring variables

	double starting_balance = -1.0; //starting balance is -ve so it gets into loop
	double annual_interest = 0.0; 
	
	double ending_balance, qtr_ending_balance=0.0;
	double monthly_deposit, monthly_withdrawal, monthly_interest;
	
	//Qtr variables are used for running totals.
	double qtr_starting_balance = 0.0, qtr_deposit = 0.0, qtr_withdrawal = 0.0, qtr_interest = 0.0;
	
	cout.setf(ios::fixed); // set fixed format for output
	cout.setf(ios::showpoint); // show decimal point and trailing zeros in output
	cout.precision(2); // set precision to 2



	// get inputs
	while (starting_balance < 0) { //validate starting balance so it is positive
		cout << "Enter the starting balance on the account: ";
		cin >> starting_balance;
		if (starting_balance < 0)
			cout << "Starting balance should be greater than zero. Re-enter starting balance." << endl;
	}

	cout << "Enter the annual interest rate on the account (e.g. 0.04): ";
	cin >> annual_interest;
	qtr_starting_balance = starting_balance; //initialize quarter starting balance
	ending_balance = starting_balance; //initialize ending balance

	for ( int num_months = 1; num_months <=3; num_months++) // loop for 3 months
	{
		cout << endl;
		cout << "Month " << num_months << endl;

		monthly_deposit = -1.0; //initialize monthly deposit to be -ve so it can get into loop
		while (monthly_deposit < 0) {
			cout << "Total deposit for this month: \t\t";
			cin >> monthly_deposit;
			if (monthly_deposit < 0)
				cout << "Total deposit cannot be negative. Re-enter deposit amount." << endl;
		}
		qtr_deposit += monthly_deposit; //add monthly deposit to quarterly balance
		
		monthly_withdrawal = -1.0;  //initialize the withdrawal amount to be -ve so it can get into loop
		while (monthly_withdrawal < 0) {
			cout << "Total withdrawal for this month: \t";
			cin >> monthly_withdrawal;
			if (monthly_withdrawal < 0) //ensure withdrawal is not negative
				cout << "Total withdrawal cannot be negative." << endl;
			if (monthly_withdrawal > ending_balance) { //ensure withdrawal is not more than ending balance.
				cout << "Total withdrawal cannot be more than remaining balance. Re-enter withdrawal amount." << endl;
				monthly_withdrawal = -1.0; //reinitialize it so it loops back and user can enter it again
			}
		}
		qtr_withdrawal += monthly_withdrawal; //add monthly withdrawal to quarterly withdrawal

		ending_balance = starting_balance + monthly_deposit - monthly_withdrawal; // calculate ending balance
		cout << "Interest received for this month \t";
		monthly_interest = ((starting_balance + ending_balance) / 2) * annual_interest / 12; //calculate monthly interest
		qtr_interest += monthly_interest; //add monthly interest to quarterly interest

		cout << "$" << monthly_interest << endl;
		ending_balance += monthly_interest;
		cout << "Ending monthly balance \t\t\t$" << ending_balance << endl;

		starting_balance = ending_balance; //starting balance for next month is ending balance for current month
	
	}
	//finding quarterly balance
	qtr_ending_balance = qtr_starting_balance+qtr_interest+qtr_deposit-qtr_withdrawal;

	cout << endl << endl << endl;

	cout << "Quarterly Savings Account Statement" << endl << endl;

	cout << "Starting balance:\t\t  $" << std::setw(12) << qtr_starting_balance; //setw function sets output width
	cout << endl;
	cout << "Total deposit:\t\t\t+ $" << std::setw(12) << qtr_deposit;
	cout << endl;
	cout << "Total withdrawal:\t\t- $" << std::setw(12) << qtr_withdrawal;
	cout << endl;
	cout << "Total interest:\t\t\t+ $" << std::setw(12) << qtr_interest;
	cout << endl;
	cout << "\t\t\t\t" << std::string(16, '-') << endl; //string function is replicate '-' 16 times
	cout << endl;
	cout << "Ending balance:\t\t\t  $" << std::setw(12) << qtr_ending_balance;
	cout << endl << endl << endl;


	// Record end time
	auto finish = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsed = finish - start; //find duration between start and finish

	cout << "Process exited after " << elapsed.count() << " seconds with return value 0";
	return 0; //no return
} //end of program