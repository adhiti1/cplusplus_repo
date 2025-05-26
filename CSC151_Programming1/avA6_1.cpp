
// avA6_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Name : Adhiti Venkatesh
// Summary : Assignment 6 problem 1
// This program implements grade book.
// This program uses arrays to get student scores and computes a grade.
// It took about 30 hours to write the code
// 12/4/2023 Revision 1.0  Initial version
// 12/5/2023 Revision 1.1  Worked on file input
// 12/6/2023 Revision 1.2  Worked on functions
// 12/7/2023 Revision 1.3  Worked on functions and arrays
// 12/8/2023 Revision 1.4  Worked on functions and arrays
// 12/9/2023 Revision 1.5  Worked on validations
// 12/10/2023 Revision 1.6  Bug Fixes


#include <iostream>
#include <iomanip> 
#include <cmath>
#include <string> //string
#include <array> //array related functions

using namespace std;


// function prototypes
void	getStudentGrade( double[], string[], int);  //get student grade based on average score
void	getAverageScore( double score[][4], double averageScore[], double dropped[],int,int); //finds average score
double	getLowestScore( double[][4],int, int); //finds lowest score
int		getLowestScorecount(double[][4], int, int, double); //finds count of lowest scores
void	outputResults(string[],double[], double[], string[],int); //outputs results
void	readInput(double score[][4], string[], int, int); //read input and store it in the arrays

int main()
{
	// declaring variables

	const int STUDENTS = 5; //max number of students
	const int SCORES = 4; //max number of scores

	string names[STUDENTS]; //array containing student names
	string grades[STUDENTS]; //array containing student grades
	double droppedScore[STUDENTS]; //array containing lowest score that is dropped from average
	double averageScore[STUDENTS]; //array of avg scores for each student
	double testScores[STUDENTS][SCORES]; //multi dimension array containing studens and scores

	
	
	std::cout.setf(ios::fixed); // set fixed format for output
	std::cout.setf(ios::showpoint); // show decimal point and trailing zeros in output
	std::cout.precision(2); // set precision to 2

	//read input name and scores and stores them in array
	readInput(testScores, names, STUDENTS, SCORES);
	//finds average score after removing lowest scores
	getAverageScore(testScores, averageScore,droppedScore, STUDENTS, SCORES);
	//gets student grade based on average scores
	getStudentGrade(averageScore, grades, STUDENTS);
	//output results
	outputResults(names, droppedScore, averageScore, grades, STUDENTS);
	return 0; //no return
}


//read input
/*
Enter the name of student 1:Peter
Enter test score 1 for Peter:90
Enter test score 2 for Peter:80
Enter test score 3 for Peter:70
Enter test score 4 for Peter:85
Enter the name of student 2:Sam
Enter test score 1 for Sam:69
Enter test score 2 for Sam:76
Enter test score 3 for Sam:78
Enter test score 4 for Sam:56
Enter the name of student 3:Smith
Enter test score 1 for Smith:74
Enter test score 2 for Smith:79
Enter test score 3 for Smith:85
Enter test score 4 for Smith:84
Enter the name of student 4:Mary
Enter test score 1 for Mary:78
Enter test score 2 for Mary:75
Enter test score 3 for Mary:79
Enter test score 4 for Mary:86
Enter the name of student 5:Sue
Enter test score 1 for Sue:85
Enter test score 2 for Sue:83
Enter test score 3 for Sue:94
Enter test score 4 for Sue:72
*/

void readInput(double score[][4], string studentName[], int student, int scores)
{
	string name;
	double testscore;

	for (int i = 0; i < student; i++) //loop through all students
	{
		cout << "Enter the name of student " << i + 1 << ":";
		cin >> name;
		studentName[i] = name;
		for (int j = 0; j < scores; j++) // get scores for each student
		{
			do //scores should be greater than 0 and less than or equal to 100
			{
				cout << "Enter test score " << j + 1 << " for " << name << ":";
				cin >> testscore;
			} while (testscore<0 || testscore>100);
			score[i][j] = testscore; //store score in multi-dimensional array

		}
	}

}

//find lowest score in array
double	getLowestScore( double arrayNum[][4],int student, int arrayLength)
{

	double lowest = arrayNum[student][0]; //intiialize first element as lowest 
	for (int count = 1; count < arrayLength; count++) //start from 2nd element
	{
		if (arrayNum[student][count] < lowest)
			lowest = arrayNum[student][count];
	}
	return lowest;

}

//find number of lowest scores. 
//out of the 4 scores you could have all scores be same or have more than 1 lowest score
int	getLowestScorecount(double arrayNum[][4], int student, int arrayLength,double lowestscore)
{
	int lowestscorecount = 0;

	for (int count = 0; count < arrayLength; count++) //start from 2nd element
	{
		if (arrayNum[student][count] == lowestscore)
			lowestscorecount++;
	}
	return lowestscorecount;

}


// function creates average score for student by dropping lowest score
// if the student gets same score for all tests then average score is the first score as you cannot drop all scores
// if the student gets same lowest score for 2 tests then average should remove the 2 tests from denominator

void	getAverageScore( double score[][4], double averageScore[], double dropped[], int student, int scores)
{
	double lowestScore, totalscore;
	int lowestscorecount;


	for (int i = 0; i < student; i++)
	{
		lowestScore = getLowestScore(score, i, scores); //get lowest score for student
		dropped[i] = lowestScore; //record dropped score
		lowestscorecount = getLowestScorecount(score, i, scores, lowestScore);
		totalscore = 0.0; //initialize total score for each student

		for (int j = 0; j < scores; j++)
		{
			if (score[i][j] != lowestScore) //if it is not lowest score then use it for average
				totalscore = totalscore + score[i][j];
		}
		if (lowestscorecount == scores) // all scores are same
			averageScore[i] = lowestScore; //average is same as lowest score
		else //remove the count of lowest scores from total scores.
			averageScore[i] = totalscore / (scores - lowestscorecount); 
//		cout << totalscore << " " << averageScore[i] << endl;
	}

}

//store student grades in array

void	getStudentGrade( double avgscore[], string grades[], int student)
{
	double score;

	for (int i = 0; i < student; i++)
	{
		score = avgscore[i];
		if (score >= 90.0)
			grades[i] = 'A';
		else if (score >= 80.0 && score < 90.0)
			grades[i] = 'B';
		else if (score >= 70.0 && score < 80.0)
			grades[i] = 'C';
		else if (score >= 60.0 && score < 70.0)
			grades[i] = 'D';
		else
			grades[i] = 'F';
	}
}

//Output results
/*
Results :
Student Name            Dropped Score           Average Score           Grade
Peter                           70.00                   85.00           B
Sam                             56.00                   74.33           C
Smith                           74.00                   82.67           B
Mary                            75.00                   81.00           B
Sue                             72.00                   87.33           B
*/

void outputResults(string name[], double dropped[], double average[], string grade[], int student)
{
	cout << endl << endl << "Results :" << endl;
	cout << "Student Name\t\tDropped Score\t\tAverage Score\t\tGrade" << endl;
	for (int i = 0; i < student; i++)
	{
		cout << name[i];
		cout << "\t\t\t\t";
		cout << dropped[i];
		cout << "\t\t\t";
		cout << average[i];
		cout << "\t\t";
		cout << grade[i];
		cout << endl;

	}
}