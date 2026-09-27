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

void deletefromend()
{
    if(head==NULL)
    {
        printf("List is Empty");
        return;
    }
    struct Node *temp=head;

    if(head->next==NULL)
    {
        head=NULL;
        free(temp);
        return;
    }
     while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
  
    printf("\nValue Removed\n");

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

void search(int val)
{
    int ct=0;
      if(head==NULL)
    {
        printf("List is Empty");
        return;
    }
    struct Node *temp=head;
    while (temp!=NULL)
    {
        ct++;
        if(temp->data==val)
        {
            printf("\nKey found at index %d",ct);
            return;
        }
       temp=temp->next;
    }
    printf("\nKey not found\n");
    
}

int main()
{
 inserttoend(10);
 inserttoend(20);
 inserttoend(30);
 inserttoend(40);
 //display();
// //  display();
//     deletefromend();
//     display();
//     deletefromend();
//     display();
//     deletefromend();
//     display();
//     deletefromend();
//     display();
search(30);
search(40);

search(70);


display();
}