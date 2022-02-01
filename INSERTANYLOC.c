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
        new->next=NULL;
        tail=new;
    }
}

void IAP()
{
    struct node*new=(struct node*)malloc(sizeof(struct node));
    int pos,val;
    printf("\nEnter the position where you want to insert the data:\n");
    scanf("%d",&pos);
    printf("Enter the data:\n");
    scanf("%d",&val);
    new->data=val;
    if(pos==0)
    {
        new->prev=NULL;
        new->next=head;
        head->prev=new;
        head=new;
    }
    else
    {
    struct node*ptr=head;
    for(int i=0;i<pos-1;i++)
    {
        ptr=ptr->next;
    }
    
    new->next=ptr->next;
    ptr->next->prev=new;
    ptr->next=new;
    new->prev=ptr;
    }  
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
    IAP();
    printf("After insertion:\n");
    display();

    return 0;
}
