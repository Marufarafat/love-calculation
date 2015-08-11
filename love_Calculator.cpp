
/*  
* name: Love Calculator;
* language: c;
* author: Maruf Arafat;
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

int same_Lenth(char *name, char *crush);
int match_love(char *name, char *crush);
int first_Char_Match(char *name,char *crush);
int last_Char_Match(char *name,char *crush);
int ascii_match(char *name, char *crush);
int oddOrNot(char *name);

int main(void){
	/* declare variable */
	char name[15], crush[15];	// string.
	int lenLove, macLove, fcLove, lcLove, ascii_m;	// for percentege
	int love;
	bool name_digit = false, crush_digit = false;

	/* input nickname */
	printf("Enter your nickname: ");
	scanf("%s", name);

	/* input crush name */
	printf("Enter crush name: ");
	scanf("%s", crush);

	for (int i = 0; i < strlen(name); i++)
	{
		if (isdigit(name[i]))
		{
			name_digit = true;
			break;
		} 
	}

	for (int i = 0; i < strlen(crush); i++)
	{
		if (isdigit(crush[i]))
		{
			crush_digit = true;
			break;
		}
	}

	lenLove = same_Lenth(name, crush);
	macLove = match_love(name, crush);
	fcLove = first_Char_Match(name,crush);
	lcLove = last_Char_Match(name, crush);
	ascii_m = ascii_match(name, crush);

	love = lenLove + macLove + fcLove + lcLove + ascii_m;

	if (name_digit == true || crush_digit == true)
	{
		printf("You can't use number\n");
	} else {
		printf("%s %d%% crush %s", name, love, crush);
		printf("\n");
	}

	return 0;

}

/*
* name: same_Lenth();
* input: two array;
* output: integer;
* description: compare two array lenth. if same then return 20 or plus 3, minus 3 then return 10;
*/
int same_Lenth(char name[15], char crush[15]){

	/* declare variable */
	int name_Lenth = strlen(name);
	int crush_Lenth = strlen(crush);
	int s_Lenth;

	/* check condition true then 20 or 10 else 0 */
	if (crush_Lenth == name_Lenth) s_Lenth = 20;
	else if(name_Lenth < crush_Lenth + 3) s_Lenth = 10;
	else if(name_Lenth > crush_Lenth + 3) s_Lenth = 10;
	else s_Lenth = 0;

	return s_Lenth;
}

/*
* name: match_love();
* input: two array;
* output: interger;
* description: first check how much charecter match from two array. than minus this value from 20. then this value 
			from devided lenth of two array.
*/
int match_love(char name[15], char crush[15]){

	/* declare variable */
	int match_L=0, name_Crush_Lenth, sum;
	char mcl[30]={0};
	int m_love;

	/* finding match charecter */
	for (int i = 0; i < strlen(name); i++)
	{
		for (int j = 0; j < strlen(crush); j++)
		{
			if(name[i] == crush[j]){
				match_L++;
			}
		}
	}

	/* adding two string on mcl[] array */
	strcat(mcl, name);
	strcat(mcl, crush);

	name_Crush_Lenth = strlen(mcl);		// finding lenth of mcl[]
	sum = 20 - match_L;					// match_L minus from 20 and assign on sum variable
	m_love = sum / name_Crush_Lenth + 10;	// devided sum from lenth of mcl[].

	return m_love;
}

/* 
* name: first_Char_Match();
* input: two array
* output: integer;
* description: matching name array on last half charecter of crush string.
*/
int first_Char_Match(char name[15],char crush[15]){

	/* decler variable */
	char name_First_Char = name[0]; 	// assign first charecter of name
	int lcMatch, oddNot;
	oddNot = oddOrNot(crush) / 2; // find half lenth of crush string


	/* check first charecter of name with last half charecter of crush. */
	for (int i = 0; i < oddNot; i++)
	{
		if (name_First_Char == crush[oddNot+i]) {
			lcMatch = 10;
			break;
		}
		else lcMatch = 5;
	}
	return lcMatch;
}

/*
* name: last_Char_Match();
* input: two string
* output: an integer
* description: matching last charecter of name with first half charecter of crush
*/
int last_Char_Match(char name[],char crush[]){
	int lest_of_name = strlen(name);		// find strlen
	char name_last_Char = name[lest_of_name-1]; // assign last charecter of of name_last_char
	int fcMatch = 0, oddNot;
	oddNot = oddOrNot(crush) / 2; 	// find half value of crush

	/* check first charecter of name with first half charecter of crush. */
	for (int i = 0; i < oddNot; i++)
	{
		if (name_last_Char == crush[i]) {
			fcMatch = 10;
			break;
		}
		else fcMatch = 5;
	}

	return fcMatch;
}

/*
* name: ascii_match();
* input: two string
* output: an integer 
* description: match chrecter of name and crush. find there ascii value. then devided to 122
*/
int ascii_match(char name[],char crush[]){

	/* declare variable */
	int ascii_value=0;
	int value_of_love;

	/* adding ascii value of matching charecter */
	for (int i = 0; i < strlen(name); i++)
	{
		for (int j = 0; j < strlen(crush); j++)
		{
			if (name[i] == crush[j])
			{
				ascii_value += name[i];
			}
		}
	}

	value_of_love = ascii_value / 122;			// devided ascii_value from 122

	/* if value of love grater then 20 then make it 20. */
	if (value_of_love < 20)	ascii_value = 20;
	else ascii_value = value_of_love;
	return ascii_value;
}


/*
* name: oddOrNot();
* input: an string.
* output: half even number of this string.
* description: first check string lenth is even or odd. if lenth is odd then make it even.
*/
int oddOrNot(char name[15]){
	int even;

	/* check lenth even or odd. if odd it will add 1 and make it even. */
	if (strlen(name) % 2 == 0) even = strlen(name) ;
	else even = strlen(name) + 1;

	return even;
}