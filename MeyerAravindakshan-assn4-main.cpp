//***************************************************************************
//  FILENAME:	 MeyerAravindakshan-assn4-main.cpp
//  DESCRIPTION: This program will compare how long it takes to sort a list, 
//				 using various sorting methods.
//  CLASS/DATE:  Adv Programming & Algorithms/Su8w2-Week 6 - 8/3/2015
//  DESIGNER:	 Brandon Meyer/Harsha Aravindakshan
//***************************************************************************

#include "MeyerAravindakshan-assn4-common.h"      // global definitions
#include "MeyerAravindakshan-assn4-funcs.h"		// function definition

int main( )
{
	char userChoiceOne, userChoiceTwo;
	int sortTimes = 0;
	int arrayListOne[NUM_RAND_INTS];
	int arrayListTwo[NUM_RAND_INTS];
	double elapsedTimeOne = 0;
	double elapsedTimeTwo = 0;

	//Order of ops
	// main-> createNumbersForSort -> sortLists(bubbleSort, insertionSort, quickSort, or mergeSort)->verifyList
	
	do
	{
		cout << "Choose two sorts you wish to compare:" << endl;
		cout << setw(10) << "B = Bubble sort" << endl
			<< setw(10) << "I = Insertion sort" << endl
			<< setw(10) << "M = Merge sort" << endl
			<< setw(10) << "Q = Quick sort" << endl
			<< setw(10) << "E = Exit program" << endl << endl;

		cout << "Enter two letter choices (or EE to exit): ";

		cin >> userChoiceOne >> userChoiceTwo; // User input

		userChoiceOne = toupper(userChoiceOne); // Uppercase choice

		userChoiceTwo = toupper(userChoiceTwo); // Uppercase choice

		if (userChoiceOne == 'E' || userChoiceTwo == 'E') // Exit program option
		{
			cout << endl << "Good-Bye." << endl;

			return 5;
		}

		string testOne, testTwo;

		if (userChoiceOne == 'B')
		{
			testOne = "Bubble Sort";
		}
		else if (userChoiceOne == 'I')
		{
			testOne = "Insertion Sort";
		}
		else if (userChoiceOne == 'M')
		{
			testOne = "Merge Sort";
		}
		else if (userChoiceOne == 'Q')
		{
			testOne = "Quick Sort";
		}

		if (userChoiceTwo == 'B')
		{
			testTwo = "Bubble Sort";
		}
		else if (userChoiceTwo == 'I')
		{
			testTwo = "Insertion Sort";
		}
		else if (userChoiceTwo == 'M')
		{
			testTwo = "Merge Sort";
		}
		else if (userChoiceTwo == 'Q')
		{
			testTwo = "Quick Sort";
		}

		createNumbersForSort(arrayListOne, arrayListTwo); // Generate random array's.

		cout << endl << "Enter the number of times to repeat each sort (1 or more): ";

		cin >> sortTimes;

		double *resultArrayOne = new double[sortTimes]; // Dynamically allocated result array.

		double *resultArrayTwo = new double[sortTimes]; // Dynamically allocated result array.

		for (int i = 0; i < sortTimes; i++)
		{
			cout << endl << "Starting sort #" << i + 1 << "..." << endl;

			elapsedTimeOne = sortLists(userChoiceOne, arrayListOne); // Run sort method for choice 1.

			cout << setw(10) << testOne << " time " << elapsedTimeOne << endl; // Display elapsed time for first sort method.

			resultArrayOne[i] = elapsedTimeOne; // Set result from test in to dynamic array.

			elapsedTimeTwo = sortLists(userChoiceTwo, arrayListTwo); // Run sort method for choice 2.

			cout << setw(10) << testTwo << " time " << elapsedTimeTwo << endl; // Display elapsed time for second sort method.

			resultArrayTwo[i] = elapsedTimeTwo; // Set result from test in to dynamic array.

		}
		// ************************************ Calculate averages*******************************************
		double sumOne;
		double sumTwo;
		double averageOne;
		double averageTwo;

		sumOne = 0;
		sumTwo = 0;
		averageOne = 0;
		averageTwo = 0;

		for (int i = 0; i < sortTimes; i++)
		{
			sumOne += resultArrayOne[i];

			sumTwo += resultArrayTwo[i];
		}

		averageOne = sumOne / sortTimes;

		averageTwo = sumTwo / sortTimes;


		// ************************************ Results section*******************************************
		cout << endl << "SORTING RESULTS" << endl; // Start of results section.

		// Dashed line
		cout << setfill('-') << setw(15) << " "; // Creates dashes '-'.
		cout << setfill(' ') << endl; // Resets back to blank space.

		// ************************************ User choice ONE display*******************************************
		if (userChoiceOne == 'B')
		{
			cout << setw(20) << "Bubble Sort" << setw(10) << averageOne << " clock ticks on average" << endl;
		}
		else if (userChoiceOne == 'I')
		{
			cout << setw(20) << "Insertion Sort" << setw(10) << averageOne << " clock ticks on average" << endl;
		}
		else if (userChoiceOne == 'M')
		{
			cout << setw(20) << "Merge Sort" << setw(10) << averageOne << " clock ticks on average" << endl;
		}
		else if (userChoiceOne == 'Q')
		{
			cout << setw(20) << "Quick Sort" << setw(10) << averageOne << " clock ticks on average" << endl;
		}

		// ************************************ User choice TWO display*******************************************
		if (userChoiceTwo == 'B')
		{
			cout << setw(20) << "Bubble Sort" << setw(10) << averageTwo << " clock ticks on average" << endl;
		}
		else if (userChoiceTwo == 'I')
		{
			cout << setw(20) << "Insertion Sort" << setw(10) << averageTwo << " clock ticks on average" << endl;
		}
		else if (userChoiceTwo == 'M')
		{
			cout << setw(20) << "Merge Sort" << setw(10) << averageTwo << " clock ticks on average" << endl;
		}
		else if (userChoiceTwo == 'Q')
		{
			cout << setw(20) << "Quick Sort" << setw(10) << averageTwo << " clock ticks on average" << endl;
		}

		delete[] resultArrayOne; // De-Allocate dynamic result array.

		delete[] resultArrayTwo; // De-Allocate dynamic result array.

		cout << endl;

	} while (userChoiceOne == 'E' || userChoiceTwo == 'E');

   	system("Pause");
   	return 0;
}
