/*
* name: Love calculator;
* author: Maruf Arafat;
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

float percent_of_love(char *name, char *crush);
float auto_random(void);

int main(void)
{
	/* declare variable */
	char name[15], crush[15];	// string.
	float love=0;

	printf("\\-----------------------------------------------------------------------------\\\n");
	printf("\\------------------------- Love calculation ----------------------------------\\\n");
	//printf("\\-------------------- programmer: Maruf Arafat -------------------------------\\\n");
	printf("\\-----------------------------------------------------------------------------\\\n");
	printf("\n");
	printf("\n");
	printf("\n");

	int i;
	while(i != 0){
		/* input nickname */
		printf("Enter your nickname: ");
		scanf("%s", name);

		/* input crush name */
		printf("Enter crush name: ");
		scanf("%s", crush);

		/* find percent of love */
		love = percent_of_love(name, crush);

		/* check condition. if love calue greater then 100 then make it 100. */
		if (love > 100)
		{
			love = 100;
		}

		printf("%s %.0f%% crush %s", name, love, crush);
		printf("\n\n");
	}


	return 0;
}

/*
* name: percent_of_love();
* input: two string;
* output: an int;
* desc: first make two string upparcase. finding first charecter of ascii value then adding two ascii value of variable.
		then devided value of spacial percent.
*/

float percent_of_love(char name[15],char crush[15]){
	int name_value_of_ascii = toupper(name[0]);
	int crush_value_of_ascii = toupper(crush[0]);
	float persent, love;

	persent = name_value_of_ascii + crush_value_of_ascii;

	love = persent / auto_random();

	return love;
}
/*
* name: auto_random();
* input: nothing;
* output: floating point;
*/
float auto_random(void){
	time_t t;
	srand((unsigned) time(&t));
	if ((rand() % 4) > 0)
	{
		return rand() % 4;
	}
	else return 1.7;
	
}