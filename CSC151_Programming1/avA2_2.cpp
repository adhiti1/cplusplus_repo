
// avA2_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Name : Adhiti Venkatesh
// Summary : Assignment 2 problem 2
// This program computes shipping charges
// It takes weight of package and distance to be shipped as input. 
// It outputs shipping charges.
// The most difficult aspect is working out the formula, printing output, and learning syntax
// It took about 12 hours to write the code
// 10/2/2023 Revision 1.0  Initial version
// 10/3/2023 Revision 1.1  Version to capture input until validated
// 10/4/2023 Revision 1.2  Worked on output section
// 10/5/2013 Revision 1.3  Fixed code for scenario when distance shipped is less than 500

#include <iostream>
#include <iomanip> 
#include <cmath>
using namespace std;

int main()
{
	// declaring variables

	double package_weight = 0.0, distance_shipped = 0.0;
	double rate_per_500_miles;
	double shipping_Charge;


	// get inputs
	
	while (package_weight < 2.0 or package_weight > 20.0) {
		cout << "Weight Of Package (in kgs). Weight should be between 2 Kgs and 20 Kgs. : ";
		cin >> package_weight;
			}
	while (distance_shipped < 10.0 or distance_shipped > 3000.0) {
		cout << "Distance shipped (in MileS). Distance should be between 10 miles to 3000 Miles : ";
		cin >> distance_shipped;
	}

	if ( package_weight <= 2.0 ) {
		rate_per_500_miles = 1.1;
	} 
	else if (package_weight > 2.0 and package_weight <= 6.0) {
		rate_per_500_miles = 2.2;
	}
	else if (package_weight > 6.0 and package_weight <= 10.0) {
		rate_per_500_miles = 3.7;
	}
	else {
		rate_per_500_miles = 4.8;
	}

	if (distance_shipped <= 500) {
		shipping_Charge = 1.1;
	}
	else 
		shipping_Charge = rate_per_500_miles * distance_shipped / 500.0;


	cout.setf(ios::fixed); // set fixed format for output
	cout.setf(ios::showpoint); // show decimal point and trailing zeros in output
	cout.precision(2); // set precision to 2


	// \t puts a tab in the output
	cout << "Weight of Package:\t\t\t" << std::setw(12) << package_weight; //setw function sets output width
	cout << endl;
	cout << "Distance shipped:\t\t\t" << std::setw(12) << distance_shipped;
	cout << endl;

	cout << "Shipping Charges:\t\t\t$" << std::setw(11) << shipping_Charge; //setw function sets output width
	cout << endl;

	return 0; //no return
} //end of program