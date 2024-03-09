// inclusion guards
#ifndef SEARCH_LIB
#define SEARCH_LIB
// header files
#include <stdio.h>
#include <stdlib.h> // for rand, srand
#include <time.h> // for time
#include <ctype.h> // for tolower
#include <stdbool.h> // for bool data type
// global constants
#define LENGTH 10
#define NOT_FOUND -1
#define SPECIFIER "%d"
#define RANGE_MAX 3
#define RANGE_MIN 1
#define EMPTY_VALUE 0
// data type definition
typedef int dtype;
// function prototypes
void initializeRandom();
void initializeList(dtype *list, int length, dtype value);
void initializeRandomList(dtype *list, int length, int min, int max);
bool isFullList(dtype *list, int length, dtype empty_value);
char getChoiceYN();
int getNumberRange(dtype min, dtype max);
int getFirstOccurrence(dtype element, const dtype *myList);
int getLastOccurrence(dtype element, const dtype *myList);
int getAllOccurrencesStatic(
dtype element, const dtype *myList, dtype *occurrences);
dtype* getAllOccurrencesDynamic(dtype element, const dtype *myList, int *count);
void printContiguousList(const dtype *mylist, int length);
// end SEARCH_LIB
#endif

