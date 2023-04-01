#include<stdio.h>
#include<stdlib.h>
int main()
{
    int row1,column1;
    int i,j;
    printf("ENTER THE NO. OF ROWS AND COLUMN IN THE MATRIX:\n");
    scanf("%d%d",&row1,&column1);
    int array1[row1][column1];
    int row2=column1,column2=row1;
    int array2[row2][column2];
    printf("ENTER THE ELEMENTS OF THE MARIX:-\n");
    for(i=0;i<row1;i++)
        for (j=0;j<column1;j++)
        {
            printf("ENTER A[%d][%d]:",i+1,j+1);
            scanf("%d",&array1[i][j]);
        }
    printf("TRANSPOSE OF THE MATRIX IS:-\n");
    for(i=0;i<row1;i++)
        for (j=0;j<column1;j++)
        {
            array2[j][i]=array1[i][j];
        }   
    for(i=0;i<row1;i++)
    {
        for (j=0;j<column1;j++)
        {
            printf("%d\t",array2[i][j]);
        }
        printf("\n");
    }
    return 0;
}