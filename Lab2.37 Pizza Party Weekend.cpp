// Lab2.37 Pizza Party Weekend.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Adhiti Venkatesh
// 5/24/2025
// This program was created in Visual studio and copied into zybooks
// calculate the cost of hosting three pizza parties on Friday, Saturday and Sunday. 
// Read from input the number of people attending, 
// the average number of slices per person and the cost of one pizza. Dollar values are output with two decimal points
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    
    int numPeople1;
    double avgSlice1;
    double costOnePizza1;
    int numPeople2;
    double avgSlice2;
    double costOnePizza2;
    int numPeople3;
    double avgSlice3;
    double costOnePizza3;

    int numPizza;
    double totCost;
    double weekendTotal=0;

    cin >> numPeople1;
    cin >> avgSlice1;
    cin >> costOnePizza1;
    cin >> numPeople2;
    cin >> avgSlice2;
    cin >> costOnePizza2;
    cin >> numPeople3;
    cin >> avgSlice3;
    cin >> costOnePizza3;

    numPizza =  ceil(avgSlice1*numPeople1 / 8);
    totCost = numPizza * costOnePizza1;

    cout << "Friday Night Party"<<endl;
    cout << numPizza << " Pizzas: ";
    cout << fixed << setprecision(2);
    cout << "$" << totCost << endl;
    cout << "Tax: $" << 0.07 * totCost << endl;
    cout << "Delivery: $" << 0.2 * 1.07* totCost << endl;//delivery charge includes tax
    cout << "Total: $" << totCost + 0.07 * totCost + 0.2 * 1.07 * totCost << endl <<endl;
    weekendTotal = weekendTotal + totCost + 0.07 * totCost + 0.2 * 1.07* totCost; 

    if (numPeople2 > 0) {
        numPizza = ceil(avgSlice2 * numPeople2 / 8);
        totCost = numPizza * costOnePizza2;

        cout << "Saturday Night Party" << endl;
        cout << numPizza << " Pizzas: ";
        cout << fixed << setprecision(2);
        cout << "$" << totCost << endl;
        cout << "Tax: $" << 0.07 * totCost << endl;
        cout << "Delivery: $" << 0.2 * 1.07 * totCost << endl; // delivery includes tax
        cout << "Total: $" << totCost + 0.07 * totCost + 0.2 * 1.07 * totCost << endl << endl;;
        weekendTotal = weekendTotal + totCost + 0.07 * totCost + 0.2 *1.07* totCost;
    }
    if (numPeople3 > 0) {
        numPizza = ceil(avgSlice3 * numPeople3 / 8);
        totCost = numPizza * costOnePizza3;

        cout << "Sunday Night Party" << endl;
        cout << numPizza << " Pizzas: ";
        cout << fixed << setprecision(2);
        cout << "$" << totCost << endl;
        cout << "Tax: $" << 0.07 * totCost << endl;
        cout << "Delivery: $" << 0.2 * 1.07*totCost << endl;
        cout << "Total: $" << totCost + 0.07 * totCost + 0.2 *1.07* totCost << endl<<endl;
        weekendTotal = weekendTotal + totCost + 0.07 * totCost + 0.2 *1.07* totCost;
    }

    if (numPeople2 > 0)
        cout << "Weekend Total: $" << weekendTotal << endl;
    return 0;

}
