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

void DAP()
{
    int pos;
    printf("\nEnter the index whose value you want to delete:\n");
    scanf("%d",&pos);
    struct node*ptr=head;
    struct node*temp;
    if(pos==0)
    {   
        head=head->next;
        ptr->next=NULL;
        head->prev=NULL;
        free(ptr);
    }

    else
    {
        for(int i=0;i<pos-1;i++)
        {
            ptr=ptr->next;
        }
        temp=ptr->next;
        ptr->next->prev=ptr;
        ptr->next=ptr->next->next;
        free(temp);
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
    DAP();
    printf("\nAfter deletion:\n");
    display();

    return 0;
}