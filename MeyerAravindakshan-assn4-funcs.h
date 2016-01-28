//***************************************************************************
//  CODE FILENAME:  MeyerAravindakshan-assn4-funcs.h
//  DESCRIPTION:    Prototypes of functions 
//  FUNCTIONS:      createNumbersForSort - Generates arrays with 100,000 random numbers.
//					sortLists - Sort the lists using methods defined by user.
//***************************************************************************/ 

void createNumbersForSort(int arrayListOne[], int arrayListTwo[]);
double sortLists(const char &sortMethod, int arrayList[]);
double bubbleSort(int arrayList[], const int &length);
double quickSort(int arrayList[], int left, int right);