#include<stdio.h>

int main()
{
    char text[50],str[20],new_text[50];
    int i=0,j=0,n=0,found=0,k,copy_loop=0;
    printf("\nENTER THE MAIN TEXT:-\n");
    gets(text);
    printf("\nENTER THE TEXT TO BE DELETED:-\n");
    gets(str);
    while (text[i]!='\0')
    {
        j=0;k=i;found=0;
        while (text[k]==str[j] && str[j]!='\0')
        {
            k++;
            j++;
        }
        if(str[j]=='\0')
            copy_loop=k;
        new_text[n]=text[copy_loop];
        i++;
        copy_loop++;
        n++;
    }
    new_text[n]='\0';
    printf("\nTHE NEW TEXT IS:-\n");
    puts(new_text);
    printf("\n");
    return 0;
}