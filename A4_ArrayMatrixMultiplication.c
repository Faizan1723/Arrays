#include<stdio.h>
#include<stdlib.h>
int main()
{
    int row1,column1;
    int row2,column2;
    int i,j,k;

    printf("ENTER THE NO. OF ROWS AND COLUMNS IN MATRIX 1:-\n");
    scanf("%d%d",&row1,&column1);
    printf("ENTER THE NO. OF ROWS AND COLUMNS IN MATRIX 2:-\n");
    scanf("%d%d",&row2,&column2);

    int array1[row1][column1];
    int array2[row2][column2];
    int array3[row1][column2]; 

    printf("\nENTER THE ELEMENTS OF MATRIX 1:-\n");
    for(i=0;i<row1;i++)
        for(j=0;j<column1;j++)
        {
            printf("ENTER ELEMENT [%d][%d]:",i+1,j+1);
            scanf("%d",&array1[i][j]);
        }

    printf("\nENTER THE ELEMENTS OF MATRIX 2:-\n");
    for(i=0;i<row2;i++)
        for(j=0;j<column2;j++)
        {
            printf("ENTER ELEMENT [%d][%d]:",i+1,j+1);
            scanf("%d",&array2[i][j]);
        }

    if(row2==column1)
    {
        for(i=0;i<row1;i++)
        {
            for(j=0;j<column2;j++)
            {
                array3[i][j]=0;
                for(k=0;k<column1;k++)
                {
                    array3[i][j]=array3[i][j]+array1[i][k]*array2[k][j];
                }
            }
        }
    }
    else
        printf("MULTIPLICATION NOT POSSIBLE!");
        
    printf("\nTHE MULTIPLICATION OF MATRIX 1 AND MATRIX 2 IS:-\n");
    for(i=0;i<row1;i++)
    {
        for(j=0;j<column2;j++)
        {
            printf("%d\t",array3[i][j]);
        }
        printf("\n");
    }
}