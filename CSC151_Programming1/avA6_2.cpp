
// avA6_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Name : Adhiti Venkatesh
// Summary : Assignment 6 problem 1
// This program implements sorting of students and grades using pointers.
// It took about 32 hours to write the code
// 12/7/2023 Revision 1.0  Initial version
// 12/8/2023 Revision 1.1  Worked on file input
// 12/9/2023 Revision 1.2  Worked on functions and pointers
// 12/10/2023 Revision 1.3  Worked on functions and pointers
// 12/11/2023 Revision 1.4  Worked on functions and pointers
// 12/12/2023 Revision 1.5  Worked on validations and bug fixes



#include <iostream>
#include <iomanip> 
#include <cmath>
#include <string> //string
#include <array> //array related functions
#include <memory> //for using smart pointers

using namespace std;


// function prototypes

void	readInput(string* name, double* score, int count); //read input and store it in the arrays
void	sort(string* name, double* score, int count); //sorts the scores in ascending fashion
void	swap(string& a, string& b); //swaps string
void	swap(double& a, double& b); //swaps double
double	averageScore(double* score, int count); //returns average score
void	outputResults(string* name, double* score, double avgScore, int studentCount); //output results

int main()
{
	// declaring variables

	int numStudents; // number of students
	string* studentName = nullptr; //dynamically allocate an array of student names. Initialize it to null pointer
	double* scores = nullptr; //dynamically allocate an array of scores. Initialize it to null pointer.
	double avgScore; //average score of all students


	std::cout.setf(ios::fixed); // set fixed format for output
	std::cout.setf(ios::showpoint); // show decimal point and trailing zeros in output
	std::cout.precision(2); // set precision to 2

	//read input name and scores and stores them in array

	cout << "Enter the number of students: ";
	cin >> numStudents;
	cout << endl;

	studentName = new string[numStudents]; //create new student array
	scores = new double[numStudents]; //create new scores array

	//read input
	readInput(studentName, scores, numStudents);
	//sort based on scores. Names should point to the correct score
	sort(studentName, scores, numStudents);
	//find average score
	avgScore = averageScore(scores, numStudents);
	//output results
	outputResults(studentName, scores, avgScore, numStudents);

	//free dynamically allocated memory
	delete[] studentName;
	delete[] scores;

	//make them a null pointer
	studentName = nullptr;
	scores = nullptr;

	return 0; //no return
}


//read input
/* Input format
Enter the number of students: 4

Enter the name of student 1:Peter
Enter test score for Peter:76

Enter the name of student 2:Mary
Enter test score for Mary:95

Enter the name of student 3:John
Enter test score for John:-23
Invalid input. Test score cannot be negative.
Enter test score for John:80

Enter the name of student 4:Anna
Enter test score for Anna:75.4

*/
void readInput(string* name, double* score, int count)
{
	double testscore;
	string studentname;

	for (int i = 0; i < count; i++) //loop through all students
	{
		cout << "Enter the name of student " << i + 1 << ":";
		cin >> studentname;

		name[i] = studentname;
		do //scores should be greater than 0 and less than or equal to 100
		{
			cout << "Enter test score "  << "for " << name[i] << ":";
			cin >> testscore;
			if (testscore < 0)
				cout << "Invalid input. Test score cannot be negative." << endl;
			else if (testscore > 100)
				cout << "Invalid input. Test score cannot be greater than 100." << endl;
		} while (testscore < 0 || testscore>100);
		score[i] = testscore; //store score array
		cout << endl;
	}
}

//sort the score array in ascending (lowest first). Make sure that name array points to correct score
//implements bubble sort

void sort(string* name, double* score, int count)
{

	int maxElement;
	int index;

	//bubble sort alogrithm
	for (maxElement = count - 1; maxElement > 0; maxElement--)
	{
		for (index = 0; index < maxElement; index++)
		{
			if (score[index] > score[index + 1]) //if the first score is greater than second.
			{
				swap(score[index], score[index + 1]); // swap the score
				swap(name[index], name[index + 1]); //swap names as well. 
				//cout << score[index] << score[index + 1] << endl;
			}
		}
	}

}

//overloaded function. switches values.
void swap(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//overloaded function. switches values.
void swap(string& a, string& b)
{
	string temp = a;
	a = b;
	b = temp;
}

//find average scores.
double	averageScore(double* score, int count)
{
	double totalScore=0; //total score

	for (int i = 0; i < count; i++)
		totalScore = totalScore + score[i];

	return (totalScore / count);
}

//Output the results
/* Result format
Sorted list of scores:
Student Name            Test Score
Anna                    75.40
Peter                   76.00
John                    80.00
Mary                    95.00

Average Test Score: 81.60
*/

void outputResults(string* name, double* score, double avgScore, int studentCount)
{
	cout << endl;
	cout << "Sorted list of scores:" << endl;
	cout << "Student Name\t\tTest Score" << endl;

	for (int i = 0; i < studentCount; i++)
		cout << name[i] << "\t\t\t" << score[i] << endl;
	cout << endl;
	cout << "Average Test Score: " << avgScore << endl;
}