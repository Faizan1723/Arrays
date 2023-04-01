#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int coef;
    int expo;
    struct node* link;
};
struct node* insert(struct node* head, int coef,int expo )
{
    struct node* temp;
    struct node* newp=(struct node*)malloc(sizeof(struct node));
    newp->coef=coef;
    newp->expo=expo;
    newp->link=NULL;

    if(head==NULL || expo>head->expo)
    {
        newp->link=head;
        head=newp;
    }
    else
    {
        temp=head;
        while(temp->link!=NULL && temp->link->expo>expo)
        {
            temp=temp->link;
        }
        newp->link=temp->link;
        temp->link=newp;
    }  
    return head;
}
struct node*create(struct node* head)
{
    int n;
    int i;
    int coef;
    int expo;
    printf("ENTER THE NO. OF TERMS IN THE POLYNOMIALS: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("ENTER THE COEFFICIENT OF TERM %d: ",i+1);
        scanf("%d",&coef);
        printf("ENTER THE EXPONENT OF TERM %d: ",i+1);
        scanf("%d",&expo);

        head=insert(head,coef,expo);
    }
    return head;
}
void print(struct node* head)
{
    if(head==NULL)
        printf("NO PLYNOMIAL\n");
    else
    {
        struct node* temp=head;
        while (temp!=NULL)
        {  
            printf("(%dx^%d)",temp->coef,temp->expo);
            temp=temp->link;
            if(temp!=NULL)
                printf("+");
            else
                printf("\n");
        }
    }
}
void solution(float a,float b,float t)
{
    if(a==t && a!=b)
        printf("\nTHE SOLUTION OF THE POLYNOMIAL IS %.4f\n",a);
    else if(b==t && b!=a)
        printf("\nTHE SOLUTION OF THE POLYNOMIAL IS %.4f\n",t);
    else if(a==b && a!=t)
        printf("\nTHE SOLUTION OF THE POLYNOMIAL IS %.4f\n",b);
    else
        printf("\nTHE SOLUTION OF THE POLYNOMIAL IS %.4f\n",b);
}
void iteration_table(struct node* head,float a,float b)
{
    struct node* temp=head;
    float t,ft,fa,fb;
    ft=0,fa=0,fb=0;
    for(int i=0;i<20;i++)
    {
        t=(a+b)/2;
        while(temp!=NULL)
        {
            ft=ft+(pow(t,temp->expo)*temp->coef);
            fa=fa+(pow(a,temp->expo)*temp->coef);
            fb=fb+(pow(b,temp->expo)*temp->coef);
            temp=temp->link;
        }
        temp=head;
        if(ft<0 && fa<0 || ft>0 && fa>0)
        {
            a=t;
        }
        else if(ft<0 && fb<0 || ft>0 && fb>0)
        {
            b=t;
        }
        else if(ft<0 && fa<0 && fb<0 || ft>0 && fa>0 && fb>0)
        {
            a=t;
        }
    }
    printf("a=%.4f b=%.4f t=%.4f",a,b,t);
    solution(a,b,t);
}
void range(struct node* head)
{
    struct node* temp=head;
    float a=0,b=0;
    int sum,i,j;
    int count=0;
    int array[5];
    for(i=-2;i<=2;i++)
    {
        sum=0;
        while(temp!=NULL)
        {
            sum=sum+(pow(i,temp->expo)*temp->coef);
            temp=temp->link;
        }
        temp=head;
        array[count]=sum;
        printf("%d ",array[count]);
        count++;
    }
    for(i=0;i<5;i++)
    {
        count=-2;
        for(j=1;j<5;j++)
        {
            if((array[i]>0 && array[j]<0) || (array[i]<0 && array[j]>0))
            {
                a=count;
                b=count+1;
                break;
            }
            else
            {
                count++;
                continue;
            }
        }
        if(a!=0 && b!=0)
            break;
    }
    printf("\na=%0.2f , b=%0.2f\n",a,b);
    iteration_table(head,a,b);
}
int main()
{
    struct node* head=NULL;
    printf("ENTER THE POLYNOMIAL:\n");
    head=create(head);
    print(head);

    range(head);
    return 0;
}