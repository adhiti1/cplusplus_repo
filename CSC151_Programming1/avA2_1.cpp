
// avA2_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Name : Adhiti Venkatesh
// Summary : Assignment 2 problem 1
// This program computes profit or loss of stock transaction
// It takes number of shares purchased, price of purchase, number sold, price sold as input. 
// The most difficult aspect is working out the formula, printing output, and learning syntax
// It took about 4 hours to write the code
// 09/27/2023 Revision 1.0  Initial version
// 09/28/2023 Revision 1.1  Worked through the formula
// 09/29/2023 Revision 1.2  Worked on output section


#include <iostream>
#include <iomanip> 
#include <cmath>
using namespace std;

int main()
{
	// declaring variables

	double shares_purchased, price_purchased,shares_sold, price_sold;
	double commission_purchase = 0.02;
	double commission_sale = 0.02;
	double total_purchase_price, total_sale_price;
	double profit_loss;
	

	// get inputs
	cout << "Number of shares purchased: ";
	cin >> shares_purchased;
	cout << "Purchase price per share: ";
	cin >> price_purchased;
	cout << "Number of shares sold: ";
	cin >> shares_sold;
	cout << "Sale price per share: ";
	cin >> price_sold;
	cout << endl;

	// compute total purchase price including commission
	total_purchase_price = shares_purchased*price_purchased;

	// compute total sale price including commission
	total_sale_price = shares_sold * price_sold ;

	// calculate profit or loss
	
	profit_loss = total_sale_price - total_purchase_price;

	

	cout.setf(ios::fixed); // set fixed format for output
	cout.setf(ios::showpoint); // show decimal point and trailing zeros in output
	cout.precision(2); // set precision to 2

	cout << endl;
	cout << " - - Stock Transaction Report - -";
	cout << endl;
	cout << endl;

	// \t puts a tab in the output
	cout << "Purchase Price:\t\t\t$" << std::setw(12) << total_purchase_price; //setw function sets output width
	cout << endl;
	cout << "Commssion for Share Purchase:\t$" << std::setw(12) << commission_purchase*total_purchase_price;
	cout << endl;

	cout << "Sale Price:\t\t\t$" << std::setw(12) << total_purchase_price; //setw function sets output width
	cout << endl;
	cout << "Commssion for Share Sale:\t$" << std::setw(12) << commission_sale * total_sale_price;
	cout << endl;

	cout << "Profit Or Loss:\t\t\t$" << std::setw(12) << total_sale_price - total_purchase_price; //setw function sets output width
	cout << endl;

	return 0; //no return
} //end of program