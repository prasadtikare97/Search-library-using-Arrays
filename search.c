#include"search_lib.h"
//main function 
int main()
{
// initialize the random number generator
initializeRandom(); //initil
//declaring
dtype myList[LENGTH];
dtype occurrences[LENGTH];
 dtype *dynamic_occurrences;

// declare the variable to store the user's choice
char choice;

int number1=0,number2=0,number3=0;
//function call to add random number in list
initializeRandomList(myList, LENGTH, RANGE_MIN, RANGE_MAX);
//checking if list is empty or full
 int check= isFullList(myList,LENGTH,EMPTY_VALUE);
 //printf("\nCheck is %d :",check);
do	{
//if list is ful
if(check ==1)
{	//getting the element 
		dtype element = getNumberRange(RANGE_MIN, RANGE_MAX);
//printContiguousList(myList,LENGTH);
//end the program if list is empty
if(element ==0)
{
	printf("\nProgram ended.\n");
	return 0;
}
//adding the count of user input
if(element ==1)
{
	number1=1;
}
else if(element == 2)
{
	number2=1;
}
else{
	number3=1;
}
//printing message
printf("\nSearching for " SPECIFIER , element);
//getting first occurence
int first_occ = getFirstOccurrence(element,myList);
//checking if value isnot present
if(first_occ == -1){
	printf("\nValue not found!");
	return;
}
else
{
	//performing first last and static and dynamic printing
	printf("\nFirst Occurrence: " SPECIFIER , first_occ);
	printf("\nLast Occurrence: " SPECIFIER , getLastOccurrence(element, myList));
	int totalOccurrencesStatic=getAllOccurrencesStatic(element,myList, occurrences);
	printf("\nAll Occurrences (static):");
	
	printContiguousList(occurrences,totalOccurrencesStatic);
		int j;
		int count =0;
		//getting the length of the dynamic list count
		for (j=0;j<LENGTH;j++)
		{
		if(myList[j] == element)
		{
			(count)++;
		}	
		}
	 dynamic_occurrences =getAllOccurrencesDynamic(element,myList, &count);
	printf("\nAll Occurrences (dynamic): " );
	
	if(dynamic_occurrences != 0){
		printContiguousList(dynamic_occurrences,count);
	}
	free(dynamic_occurrences);//free the dyanmic memory
	printf("\nTotal Occurrences : %d",count);
}


//ask for user to input again
printf("\nDo you want to search for another value [y|n]? ");
		// Read the choice
		//call get choice function
		choice = getChoiceYN();
		//check if user has entered or searched all the values
	if(choice=='y' && number1==1 && number2==1 && number3==1)
	{
		printf("\nYou have already searched for all the possible values in the list.");
		printf("\nDo you want to generate new values for the list [y|n]?");
		choice = getChoiceYN();
		//if user has said yes
		if(choice=='y')
		{
			initializeRandomList(myList, LENGTH, RANGE_MIN, RANGE_MAX);
			number1=0;
			number2=0;
			number3=0;
		}
 

	}
}
else{
return 0;
}

}while (choice!='n' );
if(number1==1 && number2==1 && number3==1 && choice=='n'){
	printf("\nThanks for searching. Come back if needed!");


}
// end the program
printf("\nProgram ended.\n");
return 0;	
}

