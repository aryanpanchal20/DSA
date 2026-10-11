#include <stdio.h>
#define max 5

int queue[max];
int front=-1,rear=-1;

void enqueue(int val)
{
    if(rear==max-1)
    {
        printf("queue full");
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    queue[++rear]=val;
}


int isEmpty()
{
    return front==-1;
}

void dequeue()
{
    if(isEmpty())
    {
        printf("Queue is empty");
        return;
    }
    if(front==rear)
    {
        printf("Element removed : %d\n",queue[front]);
        front=-1;
        rear=-1;
        return;
    }
    printf("Element removed : %d\n",queue[front]);
    front++;
}

void display()
{
    int i;

    if(isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    for(i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

void peek()
{
    if(isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Front element: %d\n", queue[front]);
}

void peekrear()
{
    if(isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    printf("last element: %d\n", queue[rear]);
}

void search(int val)
{
    int i;

    if(isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    for(i = front; i <= rear; i++)
    {
        if(queue[i] == val)
        {
            printf("Element found at position %d\n", i - front + 1);
            return;
        }
    }

    printf("Element not found\n");
}

int main()
{
    enqueue(10);
    display();
    enqueue(20);
    display();
    enqueue(30);
    display();
    enqueue(40);
    display();
    enqueue(50);
    peek();
    peekrear();
    display();  
    dequeue();
    peek();
    display();
    // dequeue();
    // display();
    // dequeue();
    // display();
    // dequeue();
    // display();
    // dequeue();
    // display();

    return 0;
}
