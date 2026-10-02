#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *add;
};

struct Node *head=NULL;

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

    
    printf("HEAD");
}

int main()
{
    inserttoend(10);
    inserttoend(20);
    inserttoend(30);
    inserttoend(40);
    
    display();

    display();
    return 0;
}