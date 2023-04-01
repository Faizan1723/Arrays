#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char str[20];
    char temp;
    int i=0,j=0;
    printf("ENTER THE STRING:-\n");
    gets(str);
    j=strlen(str)-1;
    while (i<j)
    {
        temp=str[j];
        str[j]=str[i];
        str[i]=temp;
        i++;
        j--;
    }
    printf("THE REVERSED STRING IS:-\n");
    puts(str);

    return 0;
}