
// avA1_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Name : Adhiti Venkatesh
// Summary : Assignment 1 problem 1
// This code is meant to compute gallons of paint 
// The most difficult aspect is working out the formula, making sure 
// output is decimal and learning syntax.
// 
// It took about 30 minutes to write the code.
// 
// 09/16/2013 Revision 1.0  Initial version
// 09/22/2013 Revision 1.1  Added comments and organized the code

#include <iostream>
#include <iomanip> 
using namespace std;

int main()
{
	// declaring variables

	double gallons;
	const double fence_length = 100.0; //put decimal point so gallons will be in decimal
	const double fence_width = 6.0;
	const double paint_spread = 340.0;
	
	//formula to compute gallons needed

	gallons = (fence_length * fence_width * 2 * 2) / paint_spread;

	std::cout.precision(6); //set precision of decimal to 6
	cout << gallons;
	cout << " gallons of paint are needed to paint" << endl;
	cout << "2 coats on each side of a 100 x 6 foot fence." << endl;


	return 0; //no return
} //end of program