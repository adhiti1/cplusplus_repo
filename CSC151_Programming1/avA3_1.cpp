
// avA3_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Name : Adhiti Venkatesh
// Summary : Assignment 3 problem 1
// This program is a geometry calculator
// It computes area of a circle, rectangle, and triangle based on user selection.
// Program validates selection of menu and input validation
// The most difficult aspect is working out selection menu and area calculation based on inputs.
// It took about 8 hours to write the code
// 10/10/2023 Revision 1.0  Initial version
// 10/11/2023 Revision 1.1  Worked through the menu selection and formula
// 10/12/2023 Revision 1.2  Worked on Validation
// 10/14/2023 Revision 1.3  Worked on output section


#include <iostream>
#include <iomanip> 
#include <cmath>
using namespace std;

int main()
{
	// declaring variables
	int menu_selection =1; //variable for menu. Initialize variable so it can start loop.
	double length, width; //variables for rectangle
	double radius; //variable for circle
	double base, height; //variables for triangle
	double area; //area variable for output

	cout.setf(ios::fixed); // set fixed format for output
	cout.setf(ios::showpoint); // show decimal point and trailing zeros in output
	cout.precision(2); // set precision to 2


	// get inputs
	while (menu_selection != 4) { // loop until user wants to quit
		cout << "Geometry Calculator" << endl;
		cout << "1. Calculate the Area of a Circle" << endl;
		cout << "2. Calculate the Area of a Rectangle" << endl;
		cout << "3. Calculate the Area of a Triangle" << endl;
		cout << "4. Quit." << endl;
		cout << "Enter your choice (1-4):";
		cin >> menu_selection;

		if (menu_selection < 1 or menu_selection>4) { //ensure it is valid input
				cout << "Choice should be between 1 and 4" << endl;
				continue;
			}

		if (menu_selection == 4) { //exit loop and return when selection is 4
			break;
		}

		if (menu_selection == 1) { //circle
		
			cout << "Enter the Circle's radius:\t" ;
			cin >> radius;
			while (radius < 0) { //validate radius is not negative. loop until positive
				cout << "Radius cannot be negative." << endl;
				cout << "Enter the Circle's radius:\t";
				cin >> radius;
			}
			area = (22.0 / 7.0) * radius * radius; //using 22/7 rather than 3.14
			cout << "Area of Circle is \t" << std::setw(12) << area;
		}

		if (menu_selection == 2) { //rectangle
			cout << "Enter the length of Rectangle:\t";
			cin >> length;
			while (length < 0) {  //loop until length is positive
				cout << "Length cannot be negative." << endl;
				cout << "Enter the length of Rectangle:\t";
				cin >> length;
			}
			
			cout << "Enter the width of Rectangle:\t";
			cin >> width;
			while (width < 0) {
				cout << "Width cannot be negative." << endl;
				cout << "Enter the width of Rectangle:\t";
				cin >> width;
			}
			area = length * width * 1.0; //using 1.0 to convert into double
			cout << "Area of Rectangle is \t" << std::setw(12) << area;
		}

		if (menu_selection == 3) { //triangle
			cout << "Enter the base of Triangle:\t";
			cin >> base;
			while (base < 0) { //loop until base is positive
				cout << "Base cannot be negative." << endl;
				cout << "Enter the base of Triangle:\t" ;
				cin >> base;
			}

			cout << "Enter the height of Triangle:\t" ;
			cin >> height;
			while (height < 0) { //loop until height is positive
				cout << "Height cannot be negative." << endl;
				cout << "Enter the height of Triangle:\t" ;
				cin >> height;
			}
			area = base * height * 0.5; 
			cout << "Area of Triangle is \t" << std::setw(12) << area; 
		}



		cout << endl;
		cout << endl;
	}
	return 0; //no return
} //end of program