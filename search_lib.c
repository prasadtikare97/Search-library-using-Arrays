//including user defined function
#include "search_lib.h"
//function  initializeRandom
void initializeRandom()
{
	//seeding for the random number to get generated at the given time
	srand(time(0)); // Using current time for each execution

}
//function initializeList(dtype *list, int length, dtype value)
void initializeList(dtype *list, int length, dtype value)
{
	
	int i;
	//run loop till length
	for(i=0;i<length;i++)
	{
		//put the value in the length
		list[i]=value;
	}
}
//function initializeRandom
void initializeRandomList(dtype *list, int length, int min, int max)
{
	int i;
	//running loop until length
	for(i=0;i<length;i++)
	{
		//generating random values from 1-3 and storing in the list
		list[i]=rand() % (max-min + 1) + min ;
	}
}
//function isFullList
bool isFullList(dtype *list, int length, dtype empty_value)
{
	int i;
	////running loop until length
	for(i=0;i<length;i++)
	{
		//check if the list array 
		if(list[i] == empty_value){
			
			return false;
		}
	}
	return true;	
}
//function getChoiceYN
char getChoiceYN()
{
	//declaring a variable 
	char choice;
    char lowerChoice;
	
    while (1) {
    	//initializinh
        scanf(" %c", &choice);
        //making it lower case
        lowerChoice = tolower(choice);
	//checking if it has yes or no
        if (lowerChoice == 'y' || lowerChoice == 'n') {
            return lowerChoice;
        } else {
            printf("Invalid option. Please type 'y' to play or 'n' to exit.\n");
        }
    }

}
//function getNumberRange
int getNumberRange(dtype min, dtype max)
{
	//declaration
	int input_number;
	int valid_num=0;
	//do while loop
	do{
		printf("\nEnter a number to search in the range [1-3], inclusive (0 to exit):");
		//asking input from user
		scanf(SPECIFIER,&input_number);
		//checking incase user has put 0
		if(input_number==0)
		{
			return 0;
		}
		//if input number is between minimum and maximum value
		else if(input_number >=min && input_number <=max)
		{
			
			valid_num=1;
			return input_number;
		}
		else
		{
			printf("Invalid option. Please enter a value within the range 1-3 (or 0 to exit):");
		}
		//checking if its not valid number
	}while(!valid_num);
}
// function getFirstOccurrence
int getFirstOccurrence(dtype element, const dtype *myList)
{
	int i;
	for(i=0;i<LENGTH;i++)
	{
		// if mylist is that element
		if(myList[i] == element){
			//then return the index
			return i;
		}
	}
	//else not found
	return NOT_FOUND;
}
//function getLastOccurrence
int getLastOccurrence(dtype element, const dtype *myList)
{
	//declaring variables
	int j,count;
	
	for(j=0;j<LENGTH;j++)
	{
		//if mylist has that element
		if(myList[j] == element){
			//then count becomes j
			count=j;
		}
	}
	return count;
}
//function for getAllOccurrencesStatic

int getAllOccurrencesStatic(dtype element, const dtype *myList, dtype *occurrences)
{
	//decalario
	int k,value=0;
	for(k=0;k<LENGTH;k++)
	{
		//checking if k is that element
		if(myList[k] == element)
		{
			//if the value is less than length
			if(value < LENGTH)
			{
				//adding the value in occuerence array
			occurrences[value]=k;
			}
		value++;
		}		
		
	}
	// 
	return (value > 0) ? value : NOT_FOUND;
}
//function  getAllOccurrencesDynamic
dtype* getAllOccurrencesDynamic(dtype element, const dtype *myList, int *count)
{
	int i,j,value=0;
	//dyamic memory allocation
		int* occurrences = (int*) calloc(*count,sizeof(int));

	for(i=0;i<LENGTH;i++)
	{
		//checking if lists contain element
		if(myList[i] == element)
		{
			occurrences[value]=i;
			value++;
		}
	}
	if (occurrences == NULL) {
        // Memory allocation failed, return NULL.
        return NULL;
    }

    return occurrences;

}
// function printContiguousList
void printContiguousList(const dtype *mylist, int length)
{
	int i;
	for(i=0;i<length;i++)
	{
	printf(SPECIFIER ,mylist[i]);
	if (i < length-1) 
	{
        printf(", "); // Add a comma and space between values except for the last one.
    }
	}
}
