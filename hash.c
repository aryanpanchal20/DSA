#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct node
{
    int key;
    struct node *next;
};

struct node *table[SIZE];

int hashfunction(int val)
{
    return val % SIZE;
}

void insert(int val)
{
    int index = hashfunction(val);

    struct node *current = table[index];

    while (current != NULL)
    {
        if (current->key == val)
        {
            printf("Key already exists\n");
            return;
        }

        current = current->next;
    }

    struct node *newnode = malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->key = val;
    newnode->next = table[index];
    table[index] = newnode;

    printf("Key inserted: %d\n", val);
}

void search(int val)
{
    int index = hashfunction(val);
    struct node *current = table[index];

    while (current != NULL)
    {
        if (current->key == val)
        {
            printf("Key found: %d\n", val);
            return;
        }

        current = current->next;
    }

    printf("Key not found\n");
}
void update(int oldval , int newval)
{
    int index1  =hashfunction(oldval);
     int index2  =hashfunction(newval);

     if(index1!=index2)
     {
        printf("update is not possible");
        return;
     }

     struct node *current=table[index1];

     while(current !=NULL)
     {
        if(current->key==oldval)
        {
            current->key=newval;
            printf("Key is updated");
            return;

        }
        current=current->next;
     }
}


    
void delete(int data)
{
    int index = hashfunction(data);
    struct node *current = table[index];
    struct node *prev = NULL;

    if(current == NULL)
    {
        printf("Position is empty\n");
        return;
    }

    while(current != NULL)
    {
        if(current->key == data)
        {
            if(prev == NULL)
            {
                table[index] = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            free(current);
            printf("Key deleted successfully\n");
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Key not found\n");
}



void display()
{
    for (int i = 0; i < SIZE; i++)
    {
        struct node *current = table[i];

        printf("Index %d: ", i);

        while (current != NULL)
        {
            printf("%d -> ", current->key);
            current = current->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    insert(10);
    insert(20);
    insert(15);
    insert(25);
    insert(10);

    printf("\nHash Table:\n");
    display();

    printf("\n");
    search(20);
    search(30);

    delete(25);

    display();

    return 0;
}