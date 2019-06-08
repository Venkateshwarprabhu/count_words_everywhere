#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char* cleaner();/**Function that cleans the file**/
void main()
{
FILE * file_ptr;
char temp,*char_arr;
int letters=-1,i;
int words=0;/****T know why you've used words=0 , take a look at your logs****/
file_ptr=fopen("/home/venkateshwar/wordstore.txt","r"); /**Opening the FILE to be counted**/
/**Counting the number of letters**/
while(!feof(file_ptr))
{
temp=fgetc(file_ptr);
letters++;
}
printf("\nTOTAL NO OF LETTERS IN THE FILE : %d",letters);
fclose(file_ptr);/**Closing the File**/
char_arr=cleaner(letters);/**Function calling**/
/**Counting Words**/
for(i=0;i<letters;i++)
{
char_arr[i]==' '&&char_arr[i+1]!=' '?words++:words;
}
printf("\nTOTAL NO OF WORDS:%d",words);
printf("\n*%s*",char_arr);/**Cleaned File Stored as String**/
}
/**Cleaning Function**/
char* cleaner(int no_of_char)
{
FILE * file_ptr2=fopen("/home/venkateshwar/wordstore.txt","r");/**Opening the File again**/
char *seive,bo;
int j=0,k=0;
seive=(char*)malloc(no_of_char*sizeof(char));/**Dynamic Allocation of array to hold the input from the file**/
/**Reading input from the File**/
while(k < no_of_char)
{
bo=fgetc(file_ptr2);
seive[j++]=bo;
k++;
}
/**Removing new line characters from the input**/
for(j=0;j<no_of_char;j++)
{
seive[j]=='\n'?seive[j]=' ':seive[j];
}
fclose(file_ptr2);/**File Closed**/
return seive;/**Returning the String with the input**/
}


