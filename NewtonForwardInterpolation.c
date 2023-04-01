#include<stdio.h>
#include<stdlib.h>
void particular_soln(int,int,int,int,int,int,int);
int n;
int sum=0;
void polynomial(int h,int x0,int y1,int y2,int y3,int y4,int y5)
{
    char ch='x';
    int data=x0;

    int i,m=1;
    printf("THE POLYNOMIAL IS: \nf(x)= ");
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            printf("%d",y1);
        }
        if(i==1)
        {
            if(y2==0)
                printf("0");
            else
            {
                if(data==0 && h==1)
                    printf("%d%c",y2,ch);
                else if(data!=0 && h==1)
                    printf("(%c-%d)*%d",ch,data,y2);
                else
                    printf("((%c-%d)/%d)",ch,data,h,y2);
            }
        }
        if(i==2)
        {
            if(y3==0)
                printf("0");
            else
            {
                if(data==0 && h==1)
                    printf("(%c(%c-%d)/%d!)*(%d)",ch,ch,m,m+1,y3);
                else if(data!=0 && h==1)
                    printf("((%c-%d)(%c+(%d))/%d!)*(%d)",ch,data,ch,-data-m,m+1,y3);
                else
                    printf("[{((%c-%d)/%d)((%c-%d)/%d)-%d}/!%d]*(%d)",ch,data,h,ch,data,h,m,m+1,y3);
            }
        }
        if(i==3)
        {
            if(y4==0)
                printf("0");
            else
            {
                if(data==0 && h==1)
                    printf("(%c(%c-%d)(%c-%d)/%d!)*(%d)",ch,ch,m,ch,m+1,m+2,y4);
                else if(data!=0 && h==1)
                    printf("((%c-%d)(%c+(%d))(%c+(%d))/%d!)*(%d)",ch,data,ch,-data-m,ch,-data-m+1,m+2,y4);
                else
                    printf("[{((%c-%d)/%d)*(((%c-%d)/%d)-%d)*(((%c-%d)/%d)-%d)}/!%d]*(%d)",ch,data,h,ch,data,h,m,ch,data,h,m+1,m+2,y4);
            }
        }
        if(i==4)
        {
            if(y5==0)
                printf("0");
            else
            {
                if(data==0 && h==1)
                    printf("(%c(%c-%d)(%c-%d)(%c-%d)/%d!)*(%d)",ch,ch,m,ch,m+1,ch,m+2,m+3,y5);
                else if(data!=0 && h==1)
                    printf("{((%c-%d)*(%c+(%d))*(%c+(%d))/%d!}*(%d)",ch,data,ch,-data-m,ch,-data-m+1,-data-m+2,m+3,y4);
                else
                    printf("[{((%c-%d)/%d)*(((%c-%d)/%d)-%d)*(((%c-%d)/%d)-%d)*((%c-%d)/%d)}/!%d]*(%d)",ch,data,h,ch,data,h,m,ch,data,h,m+1,ch,data,h,m+2,m+3,y4);
            }   
        }
    
        if(i!=n-1)
        {
            printf("   +   ");
        }
    }
    particular_soln(x0,h,y1,y2,y3,y4,y5);
}
void fwrd_difference(int h,int* array1,int* array2)
{
    int i,j,k,l,m;
    int y1,y2,y3,y4,y5;

    int arr1[n-1];
    int arr2[n-2];
    int arr3[n-3];
    int arr4[n-4];
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            y1=array2[0];
        }
        else if(i==1)
        {
            for(j=0;j<n-1;j++)
            {
                arr1[j]=array2[j+1]-array2[j];
            }
        }
        else if(i==2)
        {
            for(k=0;k<n-2;k++)
            {   
                arr2[k]=arr1[k+1]-arr1[k];
            }
        }
        else if(i==3)
        {
            for (l=0;l<n-3;l++)
            {
                arr3[l]=arr2[l+1]-arr2[l];
            }
        }
        else if(i==4)
        {
            for(m=0;m<n-4;m++)
            {
                arr4[m]=arr3[m+1]-arr3[m];
            }
        }
    }
    y2=arr1[0];
    y3=arr2[0];
    y4=arr3[0];
    y5=arr4[0];
    printf("%d %d %d %d %d\n",y1,y2,y3,y4,y5);
    polynomial(h,array1[0],y1,y2,y3,y4,y5);
}
int fact(int n)
{
    int x=1,fact=1;
    while(x<=n)
    {
        fact=fact*x;
        x++;
    }
    return fact;
}
void particular_soln(int x0,int h,int y1,int y2,int y3,int y4,int y5)
{
    int choice;
    printf("\nDO YOU WANT TO CALCULATE A PARTICULAR SOLUTION(YES->1/NO->0): ");
    scanf("%d",&choice);
    if(choice)
    {
        int x;
        printf("ENTER THE PARTICULAR VALUE OF X: ");
        scanf("%d",&x);
        int p=(x-x0)/h;
        printf("%d",p);
        int i;
        for(i=0;i<n;i++)
        {
            
            if(i==0)
                sum=sum+y1;
            if(i==1)
                sum=sum+(((p*(p-1))/fact(i+1))*y2);
            if(i==2)
                sum=sum+(((p*(p-1)*(p-2))/fact(i+1))*y3);
            if(i==3)
                sum=sum+(((p*(p-1)*(p-1)*(p-2))/fact(i+1))*y4);
            if(i==4)
                sum=sum+(((p*(p-1)*(p-2)*(p-3))/fact(i+1))*y5);
        }
        printf("\nTHE PARTICULAR SOLUTION OF THE PLYNOMIAL IS %d",sum);//FOR X=10,P.S=959220 BUT P.S SHOULD BE 1000
    }
    else
        return;
}
int main()
{
    printf("ENTER THE NO. OFF INDEPENDENT VARIABLES: ");
    scanf("%d",&n);
    int array1[n];
    int array2[n];
    for(int i=0;i<n;i++)
    {
        printf("ENTER X(%d):",i);
        scanf("%d",&array1[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("ENTER Y(%d):",i);
        scanf("%d",&array2[i]);
    }
    int h;
    h=array1[1]-array1[0];
    printf("COMMON DIFFERENCE(h): %d\n",h);
    fwrd_difference(h,array1,array2);

    return 0;
}