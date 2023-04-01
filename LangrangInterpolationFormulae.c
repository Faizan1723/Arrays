#include<stdio.h>
#include<stdlib.h>
struct node
{
    int expo;
    int coef;
    struct node* link;
};
int term=1;
struct node* insert(struct node* head,int term2)
{
    struct node* temp;
    struct node* newp=malloc(sizeof(struct node));
    newp->term1=term;
    newp->term2=term2;
    newp->link=NULL;

    if(head==NULL)
    {
        newp->link=head;
        head=newp;
    }
    else
    {
        temp=head;
        while (temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=newp;
    }
    return head;
}
struct node* create(struct node* head,int n)
{
    static int coef1=1;
    static int expo1=1;
    static int a=120;
    for(int i=0;i<n;i++)
    {
        printf("ENTER %c(%d):",a,i);
        scanf("%d",&term2);

        head=insert(head,term2);
    }
    a=a+1;
    coef1
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
            printf("(%dx-(%d))",temp->term1,temp->term2);
            temp=temp->link;
            if(temp!=NULL)
                printf(" ");
            else
                printf("\n");
        }
    }
}
int main()
{ 
    int n;
    printf("ENTER THE NO. OF INDEPENDENT VARIABLES (X): ");
    scanf("%d",&n);
    struct node* head1=NULL;
    head1=create(head1,n);
    print(head1);

    printf("ENTER THE DEPENDENT VARIABLES (Y):\n");
    struct node* head2=NULL;
    head2=create(head2,n);
    print(head2);    
}