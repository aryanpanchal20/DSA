#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head=NULL;

void inserttobegin(int val)
{
    struct Node *newnode=malloc(sizeof(struct Node));
    
    newnode->data = val;
    newnode->next = head;
    newnode->prev = NULL;
    
    if(head!=NULL)
    {
        head->prev=newnode;
    }
    
    head=newnode;
}

void deletefrombegin()
{
    if(head==NULL)
    {
        printf("List is Empty");
    }
    struct Node *temp=head;
    
    head=temp->next;
    head->prev=NULL;
    
    free(temp);
    printf("value removed\n");
}

void inserttoend(int val)
{
    struct Node *newnode=malloc(sizeof(struct Node));
    
    newnode->data=val;
    newnode->next=NULL;
    
    
    if(head==NULL){
       newnode->prev=NULL;
       head=newnode;
       return;
    }
    
    struct Node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    
    newnode->prev=temp;
    temp->next=newnode;
}

void display()
{
    if(head==NULL)
    {
        printf("List is Empty");
    }
    struct Node *temp=head;
    
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    // inserttobegin(10);
    // inserttobegin(20);
    // inserttobegin(30);
    // inserttobegin(40);
    
    // deletefrombegin();
    inserttoend(10);
    inserttoend(20);
    inserttoend(30);
    inserttoend(40);
    
    inserttobegin(70);

    
    
    display();
}