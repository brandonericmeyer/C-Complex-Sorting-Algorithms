//***************************************************************************
//  FILENAME:	 MeyerAravindakshan-assn4-funcs.cpp
//  DESCRIPTION: This program will compare how long it takes to sort a list, 
//				 using various sorting methods.
//  CLASS/DATE:  Adv Programming & Algorithms/Su8w2-Week 6 - 8/3/2015
//  DESIGNER:	 Brandon Meyer/Harsha Aravindakshan
//***************************************************************************

#include "MeyerAravindakshan-assn4-common.h"      // global definitions
#include "MeyerAravindakshan-assn4-funcs.h"		// function definition

//*************************************************************************
//  FUNCTION:					createNumbersForSort
//  DESCRIPTION:				Create a list of numbers to sort.
//  INPUT:       Parameter:     arrayListOne[], arrayListTwo[]
//  OUTPUT: 	 Return value:  arrayListOne, arrayListTwo - identical 
//								100,000 element arrays.
//	CALLS TO:					none
//  IMPLEMENTED BY:				Brandon Meyer
//*************************************************************************
void createNumbersForSort(int arrayListOne[], int arrayListTwo[]) 
{
	int num = 0;

	for (int i = 0; i < NUM_RAND_INTS; i++)
	{
		num = rand() % MAX_NUM + MIN_NUM;

		arrayListOne[i] = num;

		arrayListTwo[i] = num;
	}
}
//*************************************************************************
//  FUNCTION:					sortLists
//  DESCRIPTION:				Sort the lists using methods defined by user.
//  INPUT:       Parameter:     sortMethod, arrayList[], 
//  OUTPUT: 	 Return value:  arrayList[] - newly sorted list. 
//								elapsedTime - Time it took to sort the list.
//	CALLS TO:					bubbleSort, insertionSort, quickSort, or mergeSort
//  IMPLEMENTED BY:				Brandon Meyer
//*************************************************************************
double sortLists(const char &sortMethod, int arrayList[])
{
	double elapsedTime = 0;

	if (sortMethod == 'B')
	{
		elapsedTime = bubbleSort(arrayList, NUM_RAND_INTS);
	}
	else if (sortMethod == 'I')
	{
		// Call insertionSort
	}
	else if (sortMethod == 'M')
	{
		// Call mergeSort
	}
	else if (sortMethod == 'Q')
	{
		elapsedTime = quickSort(arrayList, LEFT_BOUND_ARRAY, NUM_RAND_INTS - 1);
	}
	
	return elapsedTime;
}
//*************************************************************************
//  FUNCTION:					bubbleSort
//  DESCRIPTION:				Sort the list using the bubble sort method.
//  INPUT:       Parameter:     arrayList(One/Two)[], length
//  OUTPUT: 	 Return value:  arrayList(One/Two)[] - Newly sorted array 
//								list one or two depending on user.  
//								elapsedTime - the returned sort time.
//								
//	CALLS TO:					none
//  IMPLEMENTED BY:				Brandon Meyer
//*************************************************************************
double bubbleSort(int arrayList[], const int &length)
{
	double elapsedTime = 0;
	int startTime, endTime; // Used in calculating Elapsed time
	int temp;
	int iteration;
	int index;

	startTime = clock();

	for (iteration = 1; iteration < length; iteration++)
	{
		for (index = 0; index < length - iteration; index++)
		{
			if (arrayList[index] > arrayList[index + 1])
			{
				temp = arrayList[index];

				arrayList[index] = arrayList[index + 1];

				arrayList[index + 1] = temp;
			}
		}
	}

	endTime = clock();

	elapsedTime = endTime - startTime;

	return elapsedTime;
}

//*************************************************************************
//  FUNCTION:					insertionSort
//  DESCRIPTION:				Sort the list using the insertion sort method.
//  INPUT:       Parameter:		arrayList(One/Two)[], length
//  OUTPUT: 	 Return value:  arrayList(One/Two)[] - Newly sorted array 
//								list one or two depending on user.
//								elapsedTime - the returned sort time.
//	CALLS TO:					none
//  IMPLEMENTED BY:				Brandon Meyer
//*************************************************************************
//*************************************************************************
//  FUNCTION:					mergeSort
//  DESCRIPTION:				Sort the list using the merge sort method.
//  INPUT:       Parameter:     arrayList(One/Two)[], length, low, high
//  OUTPUT: 	 Return value:  arrayList(One/Two)[] - Newly sorted array 
//								list one or two depending on user.  
//								elapsedTime - the returned sort time.
//	CALLS TO:					mergeSort(recursion) & mergeFunc
//  IMPLEMENTED BY:				Brandon Meyer
//*************************************************************************
//*************************************************************************
//  FUNCTION:					mergeFunc
//  DESCRIPTION:				Merges low middle and high for mergeSort function.
//  INPUT:       Parameter:     arrayList(One/Two)[], length, low, middle, 
//							    high
//  OUTPUT: 	 Return value:  arrayList(One/Two)[] - Newly sorted array 
//								list one or two depending on user.
//	CALLS TO:					none
//  IMPLEMENTED BY:				Brandon Meyer
//*************************************************************************
//*************************************************************************
//  FUNCTION:					quickSort
//  DESCRIPTION:				Sort the list using quick sort method.
//  INPUT:       Parameter:     arrayList(One/Two)[], left, right
//  OUTPUT: 	 Return value:  arrayList(One/Two)[] - Newly sorted array 
//								list one or two depending on user.
//								elapsedTime - the returned sort time.
//	CALLS TO:					quickSort(recursion)
//  IMPLEMENTED BY:				Brandon Meyer
//*************************************************************************
double quickSort(int arrayList[], int left, int right)
{
	double elapsedTime = 0;
	int startTime, endTime; // Used in calculating Elapsed time

	int i = left;
	int j = right;
	int temp;
	int pivot = arrayList[(left + right) / 2]; // middle index

	startTime = clock();

	while (i <= j)
	{
		while (arrayList[i] < pivot) // Start left hand partition.
		{
			i++;
		}

		while (arrayList[j] > pivot) // Start right hand partition.
		{
			j--;
		}

		if (i <= j) // Swap indices
		{
			temp = arrayList[i];
			arrayList[i] = arrayList[j];
			arrayList[j] = temp;
			i++;
			j--;
		} // end if
	} // end while

	if (left < j) // Check if we need to keep sorting, using recursion.
	{
		quickSort(arrayList, left, j);
	}

	if (i < right) // Check if we need to keep sorting, using recursion.
	{
		quickSort(arrayList, i, right);
	}

	endTime = clock();

	elapsedTime = endTime - startTime;

	return elapsedTime;
}
//*************************************************************************
//  FUNCTION:					verifyList
//  DESCRIPTION:				Verify that the newly sorted array lists are 
//								actually in order.
//  INPUT:       Parameter:     arrayListOne[], arrayListTwo[]
//  OUTPUT: 	 Return value:  exitProgram - boolean value used to exit 
//								program if list was not successfully sorted.
//	CALLS TO:	 none
//  IMPLEMENTED BY:				Brandon Meyer
//*************************************************************************



//Order of ops
// main-> createNumbersForSort -> sortLists(bubbleSort, insertionSort, quickSort, or mergeSort)->verifyList