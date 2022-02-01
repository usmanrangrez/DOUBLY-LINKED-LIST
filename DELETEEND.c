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
    struct node *new=(struct node*)malloc(sizeof(struct node));
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
        new->next=NULL;
        tail=new;
    }
}

void DE()
{
    struct node*ptr=head;
    while(ptr->next!=tail)
    {
        ptr=ptr->next;
    }
    ptr->next->prev=NULL;
    ptr->next=NULL;
    free(ptr->next);
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
    printf("\nNow after deletion:\n");
    DE();
    display();

    return 0;
}