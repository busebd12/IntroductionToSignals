#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void quitHandler(int myInt);
void alarmHandler(int myInt);

int main()
{
	bool myBool=true;

	// set signal handlers
     	signal ( SIGALRM, alarmHandler);
     	signal ( SIGINT,  quitHandler );

     	while(myBool)
     	{
		char input[20];
		
		printf("Enter your username: ");
		alarm(5);
		scanf("%s",input);//reads in user input

		//checks if user types exit
		if(strcmp(input,"exit")==0)
		{
		    myBool=false;
		    exit(0);	
		}

		printf("Your username is: %s \n", input);
    	}
    	return 0;

}

//changes the action taken when ctrl C is pressed
void quitHandler(int myInt)
{
	printf("\nOh, you thought I was going to quit? False! Please type exit to quit\n");
	return;
}

void alarmHandler( int theAlarm ) 
{
    printf("\nTime's up! Enter your username:\n");
    alarm(5);
    return;
}