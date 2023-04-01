#include<stdio.h>
int row;
void func(int array[])
{
    int i;
    for(i=0;i<3;i++)
    {
        printf("%d ",array[i]);
    }
}

void read(int matrix[row][row],int row)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<row;j++)
        {
            if(i==j)
            matrix[i][j]=0;

            else if(i>j)
            matrix[i][j]=-1;

            else
            matrix[i][j]=1;
        }
    }
}
void display(int matrix[row][row],int row)
{
    for(int i=0;i<row;i++)
    {
        printf("\n");
        for(int j=0;j<row;j++)
            printf("\t%2d",matrix[i][j]);
    }
}
int main()
{
    int array[2][3]={{1,2,3},{4,5,6}};
    func(array[0]);
    printf("ENTER THE NO. OF ROWS OF THE SQAURE MATRIX:");
    scanf("%d",&row);
    int matrix[row][row];
    read(matrix,row);
    display(matrix,row);
    return 0;
}
