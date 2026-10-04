#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *add;
};

struct Node *head=NULL;


void inserttobegin(int val)
{
    struct Node *newnode=malloc(sizeof(struct Node));
    newnode->data=val;
    newnode->add=NULL;

    if(head==NULL)
    {
        head=newnode;
        newnode->add=head;
        return;
    }

    newnode->add=head;

    struct Node *temp=head;

    while(temp->add!=newnode->add)
    {
        temp=temp->add;
    }

    temp->add=newnode;
    head=newnode;
    
}


void inserttoend(int val)
{
    struct Node *newnode = malloc(sizeof(struct Node));
    newnode->data=val;
    newnode->add=head;

    if(head==NULL)
    {
        head=newnode;
        newnode->add=head;
        return;
    }


    struct Node *temp=head;


    while (temp->add!=head)
    {
        temp=temp->add;
    }

    temp->add=newnode;
}



 void display()
{
    struct Node *temp=head;

     if(head==NULL)
    {
        printf("List is empty");
        return;
    }

   
    do
    {
        printf("%d -> ",temp->data);
        temp=temp->add;
    }while(temp!=head);

    
  
}

void deletefromend()
{
    if(head==NULL)
    {
        printf("List is Empty");
        return;
    }

    // Only one node
    if(head->add==head)
    {
        free(head);
        head=NULL;
        return;
    }

    struct Node *temp=head;

    while(temp->add->add!=head)
    {
        temp=temp->add;
    }

    struct Node *del=temp->add;

    temp->add=head;

    free(del);
}


void deletefrombegin()
{
    if(head==NULL)
    {
        printf("List is Empty");
        return;
    }


    struct Node *temp=head;

    while(temp->add!=head)
    {
        temp=temp->add;
    }
  
    struct Node *del=head;
    head=head->add;
    temp->add=head;
    free(del);


}
int main()
{
    inserttobegin(10);
    inserttobegin(20);            
    inserttobegin(30);
    inserttobegin(40);

    display();

    deletefrombegin();
    deletefrombegin();
   

    display();

  
    return 0;
}