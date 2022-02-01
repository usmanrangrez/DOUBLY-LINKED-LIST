#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node*prev;
    int data;
    struct node*next;
}*head=NULL,*tail=NULL;

void createL()
{
    struct node*new=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&new->data);
    if(head==NULL)
    {
        head=new;
        tail=new;
    }

    else
    {
        tail->next=new;
        new->prev=tail;
        tail=new;
        new->next=NULL;
    }
}

void IB()
{
    struct node*new=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("\nEnter the data to be inserted in the beginning:\n");
    scanf("%d",&x);
    new->data=x;
    new->prev=NULL;
    new->next=head;
    head->prev=new;
    head=new;
}

void display()
{
    struct node*ptr=head;
    printf("Data is:\n");
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes you want:\n");
    scanf("%d",&n);
    printf("Enter data:\n");
    for(int i=0;i<n;i++)
    {
        createL();
    }
    display();
    IB();
    printf("Now after insertion:\n");
    display();
}